/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-13 06:59:35
 * @ Description:
 */

#include "Human.hpp"

Human::Human()
{
    _body = sf::CircleShape(10);
    _body.setFillColor(sf::Color::Green);
}

Human::~Human()
{
}

void Human::update()
{
    _body.move(1, 0);
}