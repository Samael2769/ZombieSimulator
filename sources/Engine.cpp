/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:51:25
 * @ Modified by: Samael
 * @ Modified time: 2023-06-15 07:06:09
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