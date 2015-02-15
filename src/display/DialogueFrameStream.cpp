#include "display/DialogueFrameStream.hpp"

vne::DialogueFrameStream::DialogueFrameStream(DialogueFrame& dialogueFrame, Character character) :  dialogueFrame_(dialogueFrame),
                                                                                                    character_(character)
{

}

vne::DialogueFrameStream::DialogueFrameStream(const DialogueFrameStream& ls) :  dialogueFrame_(ls.dialogueFrame_),
                                                                                character_(ls.character_)
{

}

vne::DialogueFrameStream::~DialogueFrameStream()
{
    dialogueFrame_.changeDialogue(character_, str());
}