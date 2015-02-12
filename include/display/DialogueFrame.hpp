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

namespace vne
{
    class DialogueFrameStream;

    class DialogueFrame
    {
    public:
        DialogueFrame(sf::Texture texture);

        sf::Sprite getSprite();

        void setColor(sf::Color color);

        void setPosition(sf::Vector2f position);

        void setNamePosition(sf::Vector2f position);

        void setName(sf::Text name);

        void setName(std::string name);

        void setTextPosition(sf::Vector2f position);

        void setText(sf::Text text);

        void setText(std::string text);

        sf::Text getName();

        void changeDialogue(std::string name, std::string text);

        DialogueFrameStream operator()();

        DialogueFrameStream operator()(std::string name);

    private:
        sf::Text text_;
        sf::Text name_;
        sf::Sprite sprite_;

    };
}

#endif