/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:51:25
 * @ Modified by: Samael
 * @ Modified time: 2023-06-20 07:05:40
 * @ Description:
 */

#include <iostream>
#include "Engine.hpp"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::update(sf::Time deltaTime)
{
    for (auto &entity : _entities) {
        if (entity->getName() == "Zombie") {
            sf::Vector2f nearestHuman = getNearestHuman(entity->getPosition());
            entity->setDirection(nearestHuman);
            std::cout << "nearestHuman: " << nearestHuman.x << ", " << nearestHuman.y << std::endl;
        } else if (entity->getName() == "Human") {
            //flee from zombie (inverse direction)
            sf::Vector2f nearestZombie = getNearestZombie(entity->getPosition());
            entity->setDirection(nearestZombie);
            
        }
        entity->update(deltaTime);
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

void Engine::initSimulation(int nbEntities, int percentInfected)
{
    int nbInfected = nbEntities * percentInfected / 100;
    std::cout << "nbInfect: " << nbInfected << std::endl;

    for (int i = 0; i < nbEntities; i++) {
        if (i < nbInfected) {
            IEntity *zombie = new Zombie();
            zombie->setSpeed(100);
            addEntity(zombie);
        } else {
            IEntity *human = new Human();
            human->setSpeed(200);
            addEntity(human);
        }
    }
    for (auto &entity : _entities) {
        entity->setPosition(sf::Vector2f(rand() % 800, rand() % 600));
    }
}

sf::Vector2f Engine::getNearestHuman(sf::Vector2f position)
{
    sf::Vector2f nearestHuman;
    float distance = 10000;

    for (auto &entity : _entities) {
        if (entity->getName() == "Human") {
            float tmp = sqrt(pow(position.x - entity->getPosition().x, 2) + pow(position.y - entity->getPosition().y, 2));
            if (tmp < distance) {
                distance = tmp;
                nearestHuman = entity->getPosition();
            }
        }
    }
    return nearestHuman;
}

sf::Vector2f Engine::getNearestZombie(sf::Vector2f position)
{
    sf::Vector2f nearestZombie;
    float distance = 100;

    for (auto &entity : _entities) {
        if (entity->getName() == "Zombie") {
            float tmp = sqrt(pow(position.x - entity->getPosition().x, 2) + pow(position.y - entity->getPosition().y, 2));
            if (tmp < distance) {
                distance = tmp;
                nearestZombie = entity->getPosition();
            }
        }
    }
    return nearestZombie;
}