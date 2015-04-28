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

#include "display/DialogueFrame.hpp"
#include "display/DialogueFrameStream.hpp"

mvn::DialogueFrame::DialogueFrame(mvn::DialogueSkin dialogueSkin) : font_ { },
                                                                    text_ { },
                                                                    name_ { },
                                                                    sprite_ { }
{
    mvn::DialogueSkin::Skin skin = dialogueSkin.getSkin();

    sprite_ = skin.sprite;
    sprite_.setPosition(skin.framePosition);

    if (font_.loadFromFile(skin.font))
    {
        name_.setFont(font_);
        text_.setFont(font_);
    }

    name_.setCharacterSize(skin.fontSize);
    text_.setCharacterSize(skin.fontSize);

    text_.setColor(skin.textColor);
    name_.setColor(sf::Color::White);

    name_.setPosition(skin.namePosition);
    text_.setPosition(skin.textPosition);

    name_.setString("");
    text_.setString("");
}

sf::Sprite mvn::DialogueFrame::getSprite()
{
    return sprite_;
}

sf::Text mvn::DialogueFrame::getName()
{
    return name_;
}

sf::Text mvn::DialogueFrame::getText()
{
    return text_;
}

void mvn::DialogueFrame::changeDialogue(mvn::Character character, std::string text)
{
    name_.setString(character.getName());
    name_.setColor(character.getColor());
    text_.setString(text);
}

mvn::DialogueFrameStream mvn::DialogueFrame::operator()(mvn::Character character)
{
    return DialogueFrameStream(*this, character);
}