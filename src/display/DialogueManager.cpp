#include "display/DialogueManager.hpp"

using namespace std;

vne::DialoguesManager::DialoguesManager(vne::DialogueFrame& dialogueFrame, int characterPerFrames, 
                                        sf::Time pauseTime) :   queue_{ },
                                                                dialogueFrame_{ dialogueFrame },
                                                                characterSpeed_ { sf::seconds(1.f/static_cast<float>(characterPerFrames)) },
                                                                pauseTime_ { pauseTime },
                                                                deltaTime_ { sf::Time::Zero },
                                                                i_ { 0 },
                                                                output_ { "" }
{

}

void vne::DialoguesManager::operator()(sf::Time deltaTime)
{
    deltaTime_ += deltaTime;

    while(deltaTime_ > characterSpeed_ and queue_.size() != 0)
    {
        deltaTime_ -= characterSpeed_;
        pair<vne::Character*, string> firstIn = queue_[0];

        if(firstIn.second.length() > i_)
        {
            output_ += firstIn.second[i_];
            dialogueFrame_(*firstIn.first) << output_;
            i_++;
        }
        else
        {
            i_ = 0;
            output_ = "";
            queue_.erase(queue_.begin());
            deltaTime_ -= sf::seconds(2.f);
        } 
    }
}

void vne::DialoguesManager::addDialogue(vne::Character* character, string dialogue)
{
    queue_.push_back(std::make_pair(character, dialogue));
}