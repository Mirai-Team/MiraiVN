#ifndef DIALOGUESMANAGER_HPP_INCLUDED
#define DIALOGUESMANAGER_HPP_INCLUDED

#include <string>
#include <map>
#include <vector>

#include <SFML/System.hpp>

#include "character/Character.hpp"
#include "display/DialogueFrame.hpp"

namespace vne
{
    class DialoguesManager
    {
    public:
        DialoguesManager(DialogueFrame& dialogueFrame, int characterPerFrames, 
                         sf::Time pauseTime);

        void operator()(sf::Time deltaTime);

        void addDialogue(Character *character, std::string dialogue);

    private:
        std::vector<std::pair<Character*, std::string>> queue_;

        DialogueFrame& dialogueFrame_;

        sf::Time characterSpeed_;

        sf::Time pauseTime_;

        sf::Time deltaTime_;

        unsigned int i_;

        std::string output_;
    };
}

#endif