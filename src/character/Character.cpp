#include "character/Character.hpp"

using namespace std;

mvn::Character::Character(string name, sf::Color color) : name_ { name },
                                                          color_ { color }
{

}

mvn::Character::~Character()
{

}

string mvn::Character::getName()
{
    return name_;
}

sf::Color mvn::Character::getColor()
{
    return color_;
}

void mvn::Character::setName(string name)
{
    name_ = name;
}

void mvn::Character::setColor(sf::Color color)
{
    color_ = color;
}