#include "display/DialogueFrameStream.hpp"

vne::DialogueFrameStream::DialogueFrameStream(DialogueFrame& dialogueFrame, std::string name) : dialogueFrame_(dialogueFrame), name_(name)
{

}

vne::DialogueFrameStream::DialogueFrameStream(const DialogueFrameStream& ls) : dialogueFrame_(ls.dialogueFrame_), name_(ls.name_)
{

}

vne::DialogueFrameStream::~DialogueFrameStream()
{
    dialogueFrame_.changeDialogue(name_, str());
}