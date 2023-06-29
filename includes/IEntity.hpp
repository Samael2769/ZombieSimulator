/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-29 07:16:36
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
        virtual void update(sf::Time deltatime) = 0;
        virtual void draw(sf::RenderWindow &_window) = 0;
        virtual void setPosition(sf::Vector2f position) = 0;
        virtual void setDirection(sf::Vector2f direction) = 0;
        virtual sf::Vector2f getPosition() = 0;
        virtual sf::Vector2f getDirection() = 0;
        virtual std::string getName() = 0;
        virtual void setSpeed(float speed) = 0;
        virtual float getSpeed() = 0;
        virtual sf::Vector2f getCollider() = 0;
        virtual void setRange(int range) = 0;
        virtual int getRange() = 0;
        virtual bool getIsAlive() = 0;
        virtual void setIsAlive(bool isAlive) = 0;
    private:
        sf::CircleShape _body;
        sf::Vector2f _position;
        sf::Vector2f _direction;
        float _speed;
        bool canAttack;
        std::string _name;
        sf::Vector2f _Collider;
        int range;
        bool isAlive;
};
