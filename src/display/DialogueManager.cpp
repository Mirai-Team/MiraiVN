#include "display/DialogueManager.hpp"

using namespace std;

mvn::DialogueManager::DialogueManager(mvn::DialogueFrame& dialogueFrame, int characterPerSeconds, 
                                        sf::Time pauseTime, bool autoMode) :    queue_{ },
                                                                                dialogueFrame_{ dialogueFrame },
                                                                                characterSpeed_ { sf::seconds(1.f/static_cast<float>(characterPerSeconds)) },
                                                                                pauseTime_ { pauseTime },
                                                                                deltaTime_ { sf::Time::Zero },
                                                                                i_ { 0 },
                                                                                output_ { "" },
                                                                                mode_ { autoMode },
                                                                                next_ { false },
                                                                                onGoing_ { true },
                                                                                enabled_ { true }
{

}

void mvn::DialogueManager::operator()(sf::Time deltaTime)
{
    if(!onGoing_)
        deltaTime_ = characterSpeed_;
    else
        deltaTime_ += deltaTime;

    while(enabled_ and 
         (deltaTime_ >= characterSpeed_ and queue_.size() != 0) and 
         (onGoing_ or next_))
    {
        deltaTime_ -= characterSpeed_;

        pair<mvn::Character*, string> firstIn = queue_[0];

        if(next_)
        {    
            next_ = false;
            onGoing_ = true;
        }

        if(firstIn.second.length() > i_)
        {
            output_ += firstIn.second[i_];
            dialogueFrame_(*firstIn.first) << output_;
            i_++;
        }
        else
        {
            deltaTime_ = sf::Time::Zero;
            i_ = 0;
            output_ = "";
            queue_.erase(queue_.begin());

            if(!mode_)
                onGoing_ = false;

            if(mode_)
                deltaTime_ -= pauseTime_;
        } 
    }
}

void mvn::DialogueManager::addDialogue(mvn::Character* character, string dialogue)
{
    queue_.push_back(std::make_pair(character, dialogue));
}

void mvn::DialogueManager::next()
{
    next_ = true;
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