////////////////////////////////////////////////////////////
//
// MiraiVN
// Copyright (C) 2014-2015 CORTIER Benoît (benoit.cortier@gmail.com), BOULMIER Jérôme (jerome.boulmier@outlook.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include <cmath>

#include "display/DialogueManager.hpp"

using namespace std;

mvn::DialogueManager::DialogueManager(mvn::DialogueFrame& dialogueFrame, int characterPerSeconds,
                                        sf::Time pauseTime, bool autoMode,
                                        float ratio) :  queue_{ },
                                                        dialogueFrame_{ dialogueFrame },
                                                        characterSpeed_ { sf::seconds(1.f / static_cast<float>(characterPerSeconds)) },
                                                        pauseTime_ { pauseTime },
                                                        deltaTime_ { sf::Time::Zero },
                                                        currentCharacter_ { 0 },
                                                        ratio_ { ratio },
                                                        output_ { "" },
                                                        mode_ { autoMode },
                                                        next_ { false },
                                                        onGoing_ { true },
                                                        enabled_ { true }
{

}

void mvn::DialogueManager::operator()(sf::Time deltaTime)
{
    if (!enabled_)
        return;

    if (onGoing_)
        deltaTime_ += deltaTime;
    else
        deltaTime_ = characterSpeed_;

    while ( (deltaTime_ >= characterSpeed_ and queue_.size()) and 
            (onGoing_ or next_)
          )
    {
        deltaTime_ -= characterSpeed_;

        pair<mvn::Character*, string> firstIn = queue_[0];

        if (next_)
        {    
            next_ = false;
            onGoing_ = true;
        }

        if (firstIn.second.length() > currentCharacter_)
        {
            output_ += firstIn.second[currentCharacter_];
            dialogueFrame_(*firstIn.first) << output_;
            currentCharacter_++;
        }
        else
        {
            deltaTime_ = sf::Time::Zero;
            currentCharacter_ = 0;
            output_ = "";
            queue_.erase(queue_.begin());

            if (mode_)
            {
                if (pauseTime_ == sf::Time::Zero)
                    deltaTime_ -= sf::seconds(ratio_ * characterSpeed_.asSeconds() * static_cast<float>(pow(firstIn.second.length(), 1.2f)));
                else
                    deltaTime_ -= pauseTime_;
            }
            else
            {
                onGoing_ = false;
            }
        }
    }
}

void mvn::DialogueManager::addDialogue(mvn::Character* character, string dialogue)
{
    sf::String str(dialogue);

    float x = 0;

    for (unsigned short i = 0; i < dialogue.length(); i++)
    {
        const sf::Glyph& glyph = dialogueFrame_.getText().getFont()->getGlyph(dialogue[i], dialogueFrame_.getText().getCharacterSize(), false);

        if (x + 2 * static_cast<float>(glyph.textureRect.width) >= dialogueFrame_.getSprite().getGlobalBounds().left + dialogueFrame_.getSprite().getGlobalBounds().width)
        {
            x = 0;

            while (dialogue[i] != ' ')
                --i;

            sf::String str1 = str.toWideString().substr(0,i);
            str1 += "\n";
            str1 += str.toWideString().substr(i+1);
            str = str1;
        }

        x += glyph.advance;
    }

    dialogue = str.toAnsiString();

    queue_.push_back(std::make_pair(character, dialogue));
}

void mvn::DialogueManager::next()
{
    if (!queue_.size() or next_)
        return;

    if (onGoing_)
    {
        mode_ = false;
        onGoing_ = false;

        if (currentCharacter_ != 0)
        {
            pair<mvn::Character*, string> firstIn = queue_[0];
            dialogueFrame_(*firstIn.first) << firstIn.second;
            queue_.erase(queue_.begin());
        }
        else
        {
            next_ = true;
        }

        deltaTime_ = sf::Time::Zero;
        currentCharacter_ = 0;
        output_ = "";
    }
    else
    {
        next_ = true;
    }
}

void mvn::DialogueManager::enabledAutoMode()
{
    mode_ = true;
}

void mvn::DialogueManager::setRatio(float ratio)
{
    if (ratio <= 0)
        ratio_ = 1;

    ratio_ = ratio;
}
void mvn::DialogueManager::enable()
{
    enabled_ = true;
}

void mvn::DialogueManager::disable()
{
    enabled_ = false;
}

bool mvn::DialogueManager::isEnabled()
{
    return enabled_;
}