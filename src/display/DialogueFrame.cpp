#include "display/DialogueFrame.hpp"
#include "display/DialogueFrameStream.hpp"

mvn::DialogueFrame::DialogueFrame(mvn::DialogueSkin dialogueSkin) : font_ { },
                                                                    text_ { },
                                                                    name_ { },
                                                                    sprite_ { }
{
    mvn::DialogueSkin::Skin skin = dialogueSkin.getSkin();

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

sf::Sprite mvn::DialogueFrame::getSprite()
{
    return sprite_;
}

sf::Text mvn::DialogueFrame::getName()
{
    return name_;
}

sf::Text mvn::DialogueFrame::getText()
{
    return text_;
}

void mvn::DialogueFrame::changeDialogue(mvn::Character character, std::string text)
{
    name_.setString(character.getName());
    name_.setColor(character.getColor());
    text_.setString(text);
}

mvn::DialogueFrameStream mvn::DialogueFrame::operator()(mvn::Character character)
{
    return DialogueFrameStream(*this, character);
}