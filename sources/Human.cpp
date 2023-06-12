/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-12 06:06:51
 * @ Description:
 */

#include "Human.hpp"

Human::Human()
{
    _body = sf::CircleShape(10);
    _body.setFillColor(sf::Color::Green);
}