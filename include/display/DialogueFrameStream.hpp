////////////////////////////////////////////////////////////
//
// MiraiVN
// Copyright (C) 2014-2015 CORTIER Benoît (benoit.cortier@gmail.com), BOULMIER Jérôme (jerome.boulmier@outlook.fr)
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

#ifndef DIALOGUEFRAMESTREAM_HPP_INCLUDED
#define DIALOGUEFRAMESTREAM_HPP_INCLUDED

#include <string>
#include <sstream>
#include <mutex>
#include <memory>
#include <fstream>

#include "character/Character.hpp"
#include "display/DialogueFrame.hpp"

/** 
 * @file DialogueFrameStream.hpp
 * @brief This file define DialogueFrameStream class.
 */

namespace mvn
{
    // forward declaration.
    class DialogueFrame;

    /** @class DialogueFrameStream */
    class DialogueFrameStream : public std::ostringstream
    {
    public:
        /**
         * @brief Constructor
         * 
         * @param dialogueFrame : A reference to a DialogueFrame.
         * @param character : A character.
         */
        DialogueFrameStream(DialogueFrame& dialogueFrame, Character character);

        /**
         * @brief Copy constructor
         * 
         * @param ls : A DialogueFrameStream.
         */
        DialogueFrameStream(const DialogueFrameStream& ls);

        /**
         * @brief Destructor
         * @details Call DialogueFrame::changeDialogue.
         */
        ~DialogueFrameStream();

    private:
        DialogueFrame&  dialogueFrame_;
        Character       character_;

    };
}

#endif