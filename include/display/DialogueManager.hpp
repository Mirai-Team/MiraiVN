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

#ifndef DIALOGUESMANAGER_HPP_INCLUDED
#define DIALOGUESMANAGER_HPP_INCLUDED

#include <string>
#include <map>
#include <vector>

#include <SFML/System.hpp>

#include "character/Character.hpp"
#include "display/DialogueFrame.hpp"

/** 
 * @file DialogueManager.hpp
 * @brief This file define DialogueManager class.
 */
 
namespace mvn
{
    /**
     * @class DialogueManager
     * @brief Manage the dialogues.
     */
    class DialogueManager
    {
    public:
        /**
         * @brief Constructor
         * 
         * @param dialogueFrame : A DialogueFrame where the dialogues are written.
         * @param characterPerSeconds : Number of characters written per seconds.
         * @param pauseTime : In auto mode pause between each dialogue.
         * @param autoMode : If true, active autoMode.
         * @param ratio : Modifier for user in order to change pauseTime in autoMode.
         */
        DialogueManager(DialogueFrame& dialogueFrame, int characterPerSeconds, 
                         sf::Time pauseTime = sf::Time::Zero, bool autoMode = false, float ratio = 1.f);

        /**
         * @brief Update the dialogueFrame.
         * @details If it's in autoMode display dialogue one after another. 
         * If pauseTime is set to Zero, Calcul time between each dialogue. 
         * Change ratio in order to change pause duration.
         * 
         * @param deltaTime : Time per frame.
         */
        void operator()(sf::Time deltaTime);

        /**
         * @brief Add a dialogue.
         * @details Add a dialogue in the end of the queue.
         * 
         * @param character : Character who speaks.
         * @param dialogue : Text says by the character.
         */
        void addDialogue(Character *character, std::string dialogue);

        /**
         * @brief Force the update.
         * @details If autoMode is true, displays the whole current dialogue and disable autoMode.
         * Else display the next dialogue.
         */
        void next();

        /**
         * @brief enable auto mode.
         */
        void enabledAutoMode();

        /**
         * @brief Change the Ratio.
         * 
         * @param ratio : a float >= 0
         */
        void setRatio(float ratio);

        /**
         * @brief Enable DialogueManager.
         */
        void enable();

        /**
         * @brief Disable DialogueManager.
         */
        void disable();

        /**
         * @brief Return the state of the instance.
         * @return True if the instance is enabled.
         */
        bool isEnabled();

    private:
        std::vector<std::pair<Character*, std::string>> queue_;

        DialogueFrame& dialogueFrame_;

        sf::Time characterSpeed_;

        sf::Time pauseTime_;

        sf::Time deltaTime_;

        unsigned int currentCharacter_;

        float ratio_;

        std::string output_;

        bool mode_;

        bool next_;

        bool onGoing_;

        bool enabled_;
    };
}

#endif