#ifndef DIALOGUESMANAGER_HPP_INCLUDED
#define DIALOGUESMANAGER_HPP_INCLUDED

#include <string>
#include <map>
#include <vector>

#include <SFML/System.hpp>

#include "character/Character.hpp"
#include "display/DialogueFrame.hpp"

namespace mvn
{
    class DialogueManager
    {
    public:
        DialogueManager(DialogueFrame& dialogueFrame, int characterPerSeconds, 
                         sf::Time pauseTime, bool autoMode = false);

        void operator()(sf::Time deltaTime);

        void addDialogue(Character *character, std::string dialogue);

        void next();

        void enable();

        void disable();

        bool isEnabled();

    private:
        std::vector<std::pair<Character*, std::string>> queue_;

        DialogueFrame& dialogueFrame_;

        sf::Time characterSpeed_;

        sf::Time pauseTime_;

        sf::Time deltaTime_;

        unsigned int i_;

        std::string output_;

        bool mode_;

        bool next_;

        bool onGoing_;

        bool enabled_;
    };
}

#endif