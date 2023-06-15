/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:47:04
 * @ Modified by: Samael
 * @ Modified time: 2023-06-15 07:04:58
 * @ Description:
 */

#pragma once
#include "Human.hpp"
#include "Zombie.hpp"
#include <vector>

class Engine {
    public:
        Engine();
        ~Engine();
        void update();
        std::vector<IEntity*> getEntities();
        void addEntity(IEntity *entity);
    protected:
    private:
        std::vector<IEntity*> _entities;
};