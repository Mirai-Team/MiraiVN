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

#ifndef DIALOGUEFRAMESTREAM_HPP_INCLUDED
#define DIALOGUEFRAMESTREAM_HPP_INCLUDED

#include <string>
#include <sstream>
#include <mutex>
#include <memory>
#include <fstream>

#include "character/Character.hpp"
#include "display/DialogueFrame.hpp"

namespace mvn
{
    class DialogueFrame;

    class DialogueFrameStream : public std::ostringstream
    {
    public:
        DialogueFrameStream(DialogueFrame& dialogueFrame, Character character);
        DialogueFrameStream(const DialogueFrameStream& ls);
        ~DialogueFrameStream();

    private:
        DialogueFrame&  dialogueFrame_;
        Character       character_;

    };
}

#endif