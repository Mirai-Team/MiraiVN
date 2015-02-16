#include "display/DialogueFrameStream.hpp"

vne::DialogueFrameStream::DialogueFrameStream(DialogueFrame& dialogueFrame, Character character) :  dialogueFrame_ { dialogueFrame },
                                                                                                    character_ { character }
{

}

vne::DialogueFrameStream::~DialogueFrameStream()
{
    dialogueFrame_.changeDialogue(character_, str());
}