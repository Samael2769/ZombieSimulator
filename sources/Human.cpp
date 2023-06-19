/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-19 18:44:17
 * @ Description:
 */

#include "Human.hpp"

Human::Human()
{
    _body = sf::CircleShape(10);
    _body.setFillColor(sf::Color::Blue);
}

Human::~Human()
{
}

void Human::update()
{
    _body.move(2, 0);
}

void Human::draw(sf::RenderWindow &_window)
{
    _window.draw(_body);
}

void Human::setPosition(sf::Vector2f position)
{
    _body.setPosition(position);
}