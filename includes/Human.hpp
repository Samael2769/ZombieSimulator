/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-20 06:22:21
 * @ Description:
 */

#pragma once
#include "IEntity.hpp"

class Human : public IEntity
{
    public:
        Human();
        ~Human();
        void update(sf::Time deltaTime) override;
        void draw(sf::RenderWindow &_window) override;
        void setPosition(sf::Vector2f position) override;
        void setDirection(sf::Vector2f direction) override;
        sf::Vector2f getPosition() override;
        sf::Vector2f getDirection() override;
        std::string getName() override;
        void setSpeed(float speed) override;
        float getSpeed() override;
    private:
        sf::CircleShape _body;
        sf::Vector2f _position;
        sf::Vector2f _direction;
        float _speed;
        bool canAttack;
        std::string _name;
};