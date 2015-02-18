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

namespace mvn
{
    class DialogueManager
    {
    public:
        DialogueManager(DialogueFrame& dialogueFrame, int characterPerSeconds, 
                         sf::Time pauseTime, bool autoMode = false, float ratio = 1.f);

        void operator()(sf::Time deltaTime);

        void addDialogue(Character *character, std::string dialogue);

        void next();

        void setRatio(float ratio);

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

        float ratio_;

        std::string output_;

        bool mode_;

        bool next_;

        bool onGoing_;

        bool enabled_;
    };
}

#endif