#include "display/DialogueFrame.hpp"
#include "display/DialogueFrameStream.hpp"

vne::DialogueFrame::DialogueFrame(vne::DialogueSkin dialogueSkin) : font_ { },
                                                                    text_ { },
                                                                    name_ { },
                                                                    sprite_ { }
{
    vne::DialogueSkin::Skin skin = dialogueSkin.getSkin();

    sprite_ = skin.sprite;
    sprite_.setPosition(skin.framePosition);

    if (font_.loadFromFile(skin.font))
    {
        name_.setFont(font_);
        text_.setFont(font_);
    }

    name_.setCharacterSize(skin.fontSize);
    text_.setCharacterSize(skin.fontSize);

    text_.setColor(skin.textColor);
    name_.setColor(sf::Color::White);

    name_.setPosition(skin.namePosition);
    text_.setPosition(skin.textPosition);

    name_.setString("");
    text_.setString("");
}

sf::Sprite vne::DialogueFrame::getSprite()
{
    return sprite_;
}

sf::Text vne::DialogueFrame::getName()
{
    return name_;
}

sf::Text vne::DialogueFrame::getText()
{
    return text_;
}

void vne::DialogueFrame::changeDialogue(vne::Character character, std::string text)
{
    name_.setString(character.getName());
    name_.setColor(character.getColor());
    text_.setString(text);
}

vne::DialogueFrameStream vne::DialogueFrame::operator()(vne::Character character)
{
    return DialogueFrameStream(*this, character);
}