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

#ifndef DIALOGUESKIN_HPP_INCLUDED
#define DIALOGUESKIN_HPP_INCLUDED

#include <string>

#include <SFML/Graphics.hpp>

#include <MiraiProject/util/WindowManager.hpp>

/** 
 * @file DialogueSkin.hpp
 * @brief This file define DialogueSkin class.
 */

namespace mvn
{
    /**
     * @class DialogueSkin
     */
    class DialogueSkin
    {
    friend class DialogueFrame;

    public:
        /**
         * @brief Constructor with sf::Texture
         * 
         * @param texture : A Texture which contains the DialogueFrame's background.
         * @param framePosition : Position of the background.
         * @param font : Font path.
         * @param fontSize : Font size. 
         * @param namePosition : Position of the name.
         * @param textPosition : Position of the text.
         * @param textColor : Text Color. By default text color is white.
         * @param relativePosition : True if the text and name position is relative to the background.
         */
        DialogueSkin(sf::Texture texture, sf::Vector2f framePosition,
                     std::string font, unsigned int fontSize,
                     sf::Vector2f namePosition, sf::Vector2f textPosition,
                     sf::Color textColor = sf::Color::White, bool relativePosition = true);

        /**
         * @brief Constructor with sf::Sprite
         * 
         * @param sprite : A sprite which contains the DialogueFrame's background.
         * @param framePosition : Position of the background.
         * @param font : Font path.
         * @param fontSize : Font size. 
         * @param namePosition : Position of the name.
         * @param textPosition : Position of the text.
         * @param textColor : Text Color. By default text color is white.
         * @param relativePosition : True if the text and name position is relative to the background.
         */
        DialogueSkin(sf::Sprite sprite, sf::Vector2f framePosition,
                     std::string font, unsigned int fontSize,
                     sf::Vector2f namePosition, sf::Vector2f textPosition,
                     sf::Color textColor, bool relativePosition = true);

    private:
        struct Skin
        {
            sf::Sprite sprite { };
            sf::Vector2f framePosition { sf::Vector2f(0.f, 0.f) };
            std::string font { "" };
            unsigned int fontSize { 20 };
            sf::Color textColor { sf::Color::White };
            sf::Vector2f namePosition { sf::Vector2f(0.f, 0.f) };
            sf::Vector2f textPosition { sf::Vector2f(0.f, 0.f) };
        };

        Skin getSkin();

        Skin dialogueSkin_;
    };
}

#endif