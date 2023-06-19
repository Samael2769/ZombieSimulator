/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-19 18:44:11
 * @ Description:
 */

#include "Zombie.hpp"

Zombie::Zombie()
{
    _body = sf::CircleShape(10);
    _body.setFillColor(sf::Color::Green);
}

Zombie::~Zombie()
{
}

void Zombie::update()
{
    _body.move(1, 0);
}

void Zombie::draw(sf::RenderWindow &_window)
{
    _window.draw(_body);
}

void Zombie::setPosition(sf::Vector2f position)
{
    _body.setPosition(position);
}