/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-13 06:59:40
 * @ Description:
 */

#include "Zombie.hpp"

Zombie::Zombie()
{
    _body = sf::CircleShape(10);
    _body.setFillColor(sf::Color::Red);
}

Zombie::~Zombie()
{
}

void Zombie::update()
{
    _body.move(1, 0);
}