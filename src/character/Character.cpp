#include "character/Character.hpp"

using namespace std;

vne::Character::Character(string name, sf::Color color) : name_ { name },
                                                          color_ { color }
{

}

vne::Character::~Character()
{

}

string vne::Character::getName()
{
    return name_;
}

sf::Color vne::Character::getColor()
{
    return color_;
}

void vne::Character::setName(string name)
{
    name_ = name;
}

void vne::Character::setColor(sf::Color color)
{
    color_ = color;
}