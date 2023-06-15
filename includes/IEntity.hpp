/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-15 07:02:09
 * @ Description:
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


class IEntity
{
    public:
        virtual ~IEntity() = default;
        virtual void update() = 0;
        virtual void draw(sf::RenderWindow &_window) = 0;
    private:
        sf::CircleShape _body;
};
