/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 01:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-06-13 06:59:28
 * @ Description:
 */

#pragma once
#include "IEntity.hpp"

class Zombie : public IEntity
{
    public:
        Zombie();
        ~Zombie();
        void update() override;
    private:
        sf::CircleShape _body;
};