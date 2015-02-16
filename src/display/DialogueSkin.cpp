#include "display/DialogueSkin.hpp"

#include <iostream>

vne::DialogueSkin::DialogueSkin(sf::Texture texture, sf::Vector2f framePosition, 
                                std::string font, unsigned int fontSize, 
                                sf::Color textColor, sf::Vector2f namePosition, 
                                sf::Vector2f textPosition, bool relativePosition) : dialogueSkin_ { }
{
    dialogueSkin_.sprite.setTexture(texture);
    dialogueSkin_.framePosition = framePosition;
    dialogueSkin_.font = font;
    dialogueSkin_.fontSize = fontSize;
    dialogueSkin_.textColor = textColor;

    if(relativePosition)
    {
        dialogueSkin_.namePosition = framePosition + namePosition;
        dialogueSkin_.textPosition = framePosition + namePosition;
    }
    else
    {
        dialogueSkin_.namePosition = namePosition;
        dialogueSkin_.textPosition = textPosition;
    }
}

vne::DialogueSkin::DialogueSkin(sf::Sprite sprite, sf::Vector2f framePosition, 
                                std::string font, unsigned int fontSize, 
                                sf::Color textColor, sf::Vector2f namePosition, 
                                sf::Vector2f textPosition, bool relativePosition) : dialogueSkin_ { }
{
    dialogueSkin_.sprite = sprite;
    dialogueSkin_.framePosition = framePosition;
    dialogueSkin_.font = font;
    dialogueSkin_.fontSize = fontSize;
    dialogueSkin_.textColor = textColor;

    if(relativePosition)
    {
        dialogueSkin_.namePosition = framePosition + namePosition;
        dialogueSkin_.textPosition = framePosition + textPosition;
    }
    else
    {
        dialogueSkin_.namePosition = namePosition;
        dialogueSkin_.textPosition = textPosition;
    }
}

vne::DialogueSkin::Skin vne::DialogueSkin::getSkin()
{
    return dialogueSkin_;
}