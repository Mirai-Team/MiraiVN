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

#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

#include <string>

#include <SFML/Graphics.hpp>

/** 
 * @file Character.hpp
 * @brief This file define Character class.
 */
 
namespace mvn
{
    /** \class Character */
    class Character
    {
    public:
        /**
         * @brief Constructor
         * 
         * @param name : character's name.
         * @param color : name's color.
         */
        Character(std::string name, const sf::Color color = sf::Color::White);

        virtual ~Character();

        /**
         * @brief Give character's name
         * @return A string which contains character's name.
         */
        std::string getName();

        /**
         * @brief Give name's color
         * @return A sf::Color
         */
        sf::Color getColor();

        /**
         * @brief Change character's name
         * 
         * @param name : new character's name.
         */
        void setName(std::string name);

        /**
         * @brief Change character name color.
         * 
         * @param color : the new color.
         */
        void setColor(sf::Color color);

    private:
        std::string name_;
        sf::Color color_;
    };
}
#endif