/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-27 08:18:12
 * @ Description:
 */

#include "Zombie.hpp"
#include <iostream>
#include <cmath>

Zombie::Zombie()
{
    _body = sf::CircleShape(10);
    _body.setFillColor(sf::Color::Green);
    _name = "Zombie";
    _direction = sf::Vector2f(-1, -1);
    _Collider = sf::Vector2f(10, 10);
    _speed = 50;
}

Zombie::~Zombie()
{
}

void Zombie::update(sf::Time deltaTime)
{
    if (_direction.x == -1 && _direction.y == -1)
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
    _body.move(direction);
}

void Zombie::draw(sf::RenderWindow &_window)
{
    _window.draw(_body);
}

void Zombie::setPosition(sf::Vector2f position)
{
    _body.setPosition(position);
}

void Zombie::setDirection(sf::Vector2f direction)
{
    _direction = direction;
}

sf::Vector2f Zombie::getPosition()
{
    return _body.getPosition();
}

sf::Vector2f Zombie::getDirection()
{
    return _direction;
}

std::string Zombie::getName()
{
    return _name;
}

void Zombie::setSpeed(float speed)
{
    _speed = speed;
}

float Zombie::getSpeed()
{
    return _speed;
}

sf::Vector2f Zombie::getCollider()
{
    return _Collider;
}

void Zombie::setRange(int range)
{
    this->range = range;
}

int Zombie::getRange()
{
    return range;
}