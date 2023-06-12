/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-12 06:05:50
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
        void draw() override;
    private:
        sf::CircleShape _body;
};