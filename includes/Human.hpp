/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-19 18:37:03
 * @ Description:
 */

#pragma once
#include "IEntity.hpp"

class Human : public IEntity
{
    public:
        Human();
        ~Human();
        void update() override;
        void draw(sf::RenderWindow &_window) override;
        void setPosition(sf::Vector2f position) override;
    private:
        sf::CircleShape _body;
        sf::Vector2f _position;
        float _speed;
        bool canAttack;
        std::string _name;
};