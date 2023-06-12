/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-12 06:05:19
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
        virtual void draw() = 0;
    private:
        sf::CircleShape _body;
};
