/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:47:04
 * @ Modified by: Samael
 * @ Modified time: 2023-06-26 07:02:46
 * @ Description:
 */

#pragma once
#include "Human.hpp"
#include "Zombie.hpp"
#include <vector>
#include <cmath>

class Engine {
    public:
        Engine();
        ~Engine();
        void update(sf::Time deltaTime);
        std::vector<IEntity*> getEntities();
        void addEntity(IEntity *entity);
        void initSimulation(int nbEntities, int percentInfected);
        sf::Vector2f getNearestHuman(sf::Vector2f position);
        sf::Vector2f getNearestZombie(sf::Vector2f position);
        sf::Vector2f mapSize;
        void boundariesHandler();
        void collisionHandler();
    protected:
    private:
        std::vector<IEntity*> _entities;
        int _nbEntities;
        int _percentInfected;
};