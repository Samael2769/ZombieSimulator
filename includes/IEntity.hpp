/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-19 18:36:55
 * @ Description:
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <string>


class IEntity
{
    public:
        virtual ~IEntity() = default;
        virtual void update() = 0;
        virtual void draw(sf::RenderWindow &_window) = 0;
        virtual void setPosition(sf::Vector2f position) = 0;
    private:
        sf::CircleShape _body;
        sf::Vector2f _position;
        float _speed;
        bool canAttack;
        std::string _name;
};
