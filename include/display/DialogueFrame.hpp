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

namespace mvn
{
    class DialogueFrameStream;

    class DialogueFrame
    {
    friend class DialogueSkin;

    public:
        DialogueFrame(mvn::DialogueSkin skin);

        sf::Sprite getSprite();

        sf::Text getName();

        sf::Text getText();

        void changeDialogue(Character character, std::string text);

        DialogueFrameStream operator()(Character character = Character(""));

    private:
        sf::Font font_;

        sf::Text text_;
        sf::Text name_;
        
        sf::Sprite sprite_;
    };
}

#endif