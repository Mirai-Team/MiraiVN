#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

#include <string>

#include <SFML/Graphics.hpp>

namespace vne
{
    class Character
    {
    public:
        Character(std::string name, sf::Color color = sf::Color::White);

        std::string getName();
        sf::Color getColor();

        void setName(std::string name);
        void setColor(sf::Color color);

        virtual ~Character();
    private:
        std::string name_;
        sf::Color color_;
    };
}
#endif