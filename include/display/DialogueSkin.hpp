#ifndef DIALOGUESKIN_HPP_INCLUDED
#define DIALOGUESKIN_HPP_INCLUDED

#include <string>

#include <SFML/Graphics.hpp>

#include <MiraiProject/util/WindowManager.hpp>

namespace vne
{
    class DialogueSkin
    {
    friend class DialogueFrame;
    
    public:
        DialogueSkin(sf::Texture texture, sf::Vector2f framePosition, std::string font, unsigned int fontSize, sf::Color textColor, sf::Vector2f namePosition, sf::Vector2f textPosition, bool relativePosition = true);
        DialogueSkin(sf::Sprite sprite, sf::Vector2f framePosition, std::string font, unsigned int fontSize, sf::Color textColor, sf::Vector2f namePosition, sf::Vector2f textPosition, bool relativePosition = true);
        
    private:
        struct Skin
        {
            sf::Sprite sprite;
            sf::Vector2f framePosition;
            std::string font;
            unsigned int fontSize;
            sf::Color textColor;
            sf::Vector2f namePosition;
            sf::Vector2f textPosition;
        };
        Skin getSkin();
        Skin dialogueSkin_;
    };
}

#endif