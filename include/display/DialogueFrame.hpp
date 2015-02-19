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

#ifndef DIALOGUEFRAME_HPP_INCLUDED
#define DIALOGUEFRAME_HPP_INCLUDED

#include <iostream>
#include <string>
#include <memory>
#include <sstream>

#include <SFML/Graphics.hpp>

#include <MiraiProject/util/StringUtilities.hpp>
#include <MiraiProject/util/WindowManager.hpp>

#include "display/DialogueFrameStream.hpp"
#include "display/DialogueSkin.hpp"

/** 
 * @file DialogueFrame.hpp
 * @brief This file define DialogueFrame class.
 */

namespace mvn
{
    //forward declaration.
    class DialogueFrameStream;

    /**
     * @class DialogueFrame
     */
    class DialogueFrame
    {
    friend class DialogueSkin;

    public:
        /**
         * @brief Constructor
         * @details Genere a dialogue frame with DialogueSkin parameter.
         * 
         * @param skin : A DialogueSkin.
         */
        DialogueFrame(mvn::DialogueSkin skin);

        /**
         * @brief Return the sprite (background of the frame)
         * @return A sf::Sprite which is the background frame.
         */
        sf::Sprite getSprite();

        /**
         * @brief Return the name.
         * @return A sf::Text.
         */
        sf::Text getName();

        /**
         * @brief Return the text
         * @return [description]
         */
        sf::Text getText();

        /**
         * @brief Change the dialogue
         * @details Set name_ string value to character.getName(), set name_ color to character.getColor()
         * and set text_ string value to text.
         *  
         * @param character : A Character
         * @param text [description]
         */
        void changeDialogue(Character character, std::string text);

        /**
         * @brief Call DialogueFrameStream constructor in order to call changeDialogue
         * @details Allow you to use << operator in order to changeDialogue.
         * @param character : A character, by default it's a character with empty name and sf::Color::White.
         * @return Return a stream.
         */
        DialogueFrameStream operator()(Character character = Character(""));

    private:
        sf::Font font_;

        sf::Text text_;
        sf::Text name_;
        
        sf::Sprite sprite_;
    };
}

#endif