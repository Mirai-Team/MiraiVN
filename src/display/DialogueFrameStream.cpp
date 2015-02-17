#include "display/DialogueFrameStream.hpp"

mvn::DialogueFrameStream::DialogueFrameStream(DialogueFrame& dialogueFrame, Character character) :  dialogueFrame_ { dialogueFrame },
                                                                                                    character_ { character }
{

}

mvn::DialogueFrameStream::~DialogueFrameStream()
{
    dialogueFrame_.changeDialogue(character_, str());
}