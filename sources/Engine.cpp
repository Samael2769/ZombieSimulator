/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:51:25
 * @ Modified by: Samael
 * @ Modified time: 2023-06-19 18:43:34
 * @ Description:
 */

#include "Engine.hpp"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::update()
{
    for (auto &entity : _entities) {
        entity->update();
    }
}

std::vector<IEntity*> Engine::getEntities()
{
    return _entities;
}

void Engine::addEntity(IEntity *entity)
{
    _entities.push_back(entity);
}
#include <iostream>
void Engine::initSimulation(int nbEntities, int percentInfected)
{
    int nbInfected = nbEntities * percentInfected / 100;
    std::cout << "nbInfect: " << nbInfected << std::endl;

    for (int i = 0; i < nbEntities; i++) {
        if (i < nbInfected)
            addEntity(new Zombie());
        else
            addEntity(new Human());
    }
    for (auto &entity : _entities) {
        entity->setPosition(sf::Vector2f(rand() % 800, rand() % 600));
    }
}