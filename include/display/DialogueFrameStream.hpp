#ifndef DIALOGUEFRAMESTREAM_HPP_INCLUDED
#define DIALOGUEFRAMESTREAM_HPP_INCLUDED

#include <string>
#include <sstream>
#include <mutex>
#include <memory>
#include <fstream>

#include "character/Character.hpp"
#include "display/DialogueFrame.hpp"

namespace vne
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