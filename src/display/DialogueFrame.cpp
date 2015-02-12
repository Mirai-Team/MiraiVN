#include "display/DialogueFrame.hpp"
#include "display/DialogueFrameStream.hpp"

vne::DialogueFrame::DialogueFrame(sf::Texture texture)
{
    sprite_.setTexture(texture);
}

sf::Sprite vne::DialogueFrame::getSprite()
{
    return sprite_;
}

void vne::DialogueFrame::setColor(sf::Color color)
{
    sprite_.setColor(color);
}

void vne::DialogueFrame::setPosition(sf::Vector2f position)
{
    sprite_.setPosition(position);
}

void vne::DialogueFrame::setNamePosition(sf::Vector2f position)
{
    name_.setPosition(position);
}

void vne::DialogueFrame::setName(sf::Text name)
{
    name_ = name;
}

void vne::DialogueFrame::setName(std::string name)
{
    name_.setString(name);
}

sf::Text vne::DialogueFrame::getName()
{
    return name_;
}

void vne::DialogueFrame::changeDialogue(std::string name, std::string text)
{
    name_.setString(name);
}

vne::DialogueFrameStream vne::DialogueFrame::operator()()
{
    return DialogueFrameStream(*this, "");
}

vne::DialogueFrameStream vne::DialogueFrame::operator()(std::string name)
{
    return DialogueFrameStream(*this, name);
}