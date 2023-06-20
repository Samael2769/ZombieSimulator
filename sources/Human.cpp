/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-20 07:05:11
 * @ Description:
 */

#include "Human.hpp"
#include <iostream>
#include <cmath>

Human::Human()
{
    _body = sf::CircleShape(10);
    _body.setFillColor(sf::Color::Blue);
    _name = "Human";
}

Human::~Human()
{
}

void Human::update(sf::Time deltaTime)
{
    if (_direction.x == 0 && _direction.y == 0)
        return;
    sf::Vector2f position = _body.getPosition();
    sf::Vector2f enemyPos = _direction;
    sf::Vector2f direction = enemyPos - position;
    float speed = _speed * deltaTime.asSeconds();
    float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    direction.x = direction.x / distance;
    direction.y = direction.y / distance;
    direction.x = direction.x * speed;
    direction.y = direction.y * speed;
    _body.move(-direction);
}

void Human::draw(sf::RenderWindow &_window)
{
    _window.draw(_body);
}

void Human::setPosition(sf::Vector2f position)
{
    _body.setPosition(position);
}

void Human::setDirection(sf::Vector2f direction)
{
    _direction = direction;
}

sf::Vector2f Human::getPosition()
{
    return _body.getPosition();
}

sf::Vector2f Human::getDirection()
{
    return _direction;
}

std::string Human::getName()
{
    return _name;
}

void Human::setSpeed(float speed)
{
    _speed = speed;
}

float Human::getSpeed()
{
    return _speed;
}
