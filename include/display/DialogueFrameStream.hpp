#ifndef DIALOGUEFRAMESTREAM_HPP_INCLUDED
#define DIALOGUEFRAMESTREAM_HPP_INCLUDED

#include <string>
#include <sstream>
#include <mutex>
#include <memory>
#include <fstream>

#include "display/DialogueFrame.hpp"

namespace vne
{
    class DialogueFrame;

    //class logger;

    class DialogueFrameStream : public std::ostringstream
    {
    public:
        DialogueFrameStream(DialogueFrame& dialogueFrame, std::string name);
        DialogueFrameStream(const DialogueFrameStream& ls);
        ~DialogueFrameStream();

    private:
        DialogueFrame& dialogueFrame_;
        std::string name_;
    };
}

#endif