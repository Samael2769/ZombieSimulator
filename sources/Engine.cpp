/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:51:25
 * @ Modified by: Samael
 * @ Modified time: 2023-06-26 07:33:03
 * @ Description:
 */

#include <iostream>
#include "Engine.hpp"
#include <cmath>
#include <ctime>

Engine::Engine()
{
    mapSize = sf::Vector2f(800, 600);
}

Engine::~Engine()
{
}

void Engine::update(sf::Time deltaTime)
{
    int i = 0;
    for (auto &entity : _entities) {
        if (entity->getName() == "Zombie") {
            sf::Vector2f nearestHuman = getNearestHuman(entity->getPosition());
            entity->setDirection(nearestHuman);
        } else if (entity->getName() == "Human") {
            sf::Vector2f nearestZombie = getNearestZombie(entity->getPosition());
            entity->setDirection(nearestZombie);
            
        }
        entity->update(deltaTime);
        i++;
    }
    collisionHandler();
    boundariesHandler();
}

void Engine::boundariesHandler()
{
    for (auto &entity : _entities) {
        sf::Vector2f position = entity->getPosition();
        if (position.x < 0)
            position.x = mapSize.x - 10;
        else if (position.x > mapSize.x)
            position.x = 0;
        if (position.y < 0)
            position.y = mapSize.y - 10;
        else if (position.y > mapSize.y)
            position.y = 0;
        entity->setPosition(position);
    }
}

bool checkCollision(const sf::Vector2f& position1, const sf::Vector2f& collider1, const sf::Vector2f& position2, const sf::Vector2f& collider2)
{
    if (position1.x + collider1.x > position2.x - collider2.x && 
        position1.x - collider1.x < position2.x + collider2.x && 
        position1.y + collider1.y > position2.y - collider2.y && 
        position1.y - collider1.y < position2.y + collider2.y)
    {
        return true; // Collision detected
    }

    return false; // No collision
}

sf::Vector2f normalize(const sf::Vector2f& vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length != 0.0f) {
        return sf::Vector2f(vector.x / length, vector.y / length);
    }
    return sf::Vector2f(0.0f, 0.0f);
}


void Engine::collisionHandler()
{
    const float separationDistance = 20.0f; // Distance de séparation pour éviter les collisions
    int index = 0;
    for (auto& entity : _entities) {
        for (auto& otherEntity : _entities) {
            if (entity != otherEntity) {
                if (checkCollision(entity->getPosition(), entity->getCollider(), otherEntity->getPosition(), otherEntity->getCollider())) {
                    if (entity->getName() == "Zombie" && otherEntity->getName() == "Human") {
                        std::cout << "Zombie collision" << std::endl;
                        IEntity *zombie = new Zombie();
                        zombie->setPosition(otherEntity->getPosition());
                        _entities[index] = zombie;
                    } else if (entity->getName() == "Human" && otherEntity->getName() == "Zombie") {
                        std::cout << "Human collision" << std::endl;
                        IEntity *zombie = new Zombie();
                        zombie->setPosition(entity->getPosition());
                        _entities[index] = zombie;
                    } else if (entity->getName() == otherEntity->getName()) {
                        std::cout << "Collision with same species" << std::endl;
                        // Déplacez otherEntity hors de la zone de collision avec entity
                        sf::Vector2f collisionVector = otherEntity->getPosition() - entity->getPosition();
                        collisionVector = normalize(collisionVector); // Normalisez le vecteur de collision

                        sf::Vector2f separationVector = collisionVector * separationDistance; // Calculez le vecteur de séparation

                        sf::Vector2f newPosition = otherEntity->getPosition() + separationVector;
                        otherEntity->setPosition(newPosition);
                    }
                }
            }
        }
        index++;
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
    srand(time(NULL));

    for (int i = 0; i < nbEntities; i++) {
        if (i < nbInfected) {
            IEntity *zombie = new Zombie();
            addEntity(zombie);
        } else {
            IEntity *human = new Human();
            addEntity(human);
        }
    }
    for (auto &entity : _entities) {
        entity->setPosition(sf::Vector2f(rand() % 800, rand() % 600));
    }
}

sf::Vector2f Engine::getNearestHuman(sf::Vector2f position)
{
    sf::Vector2f nearestHuman = sf::Vector2f(-1, -1);
    float shortestDistance = std::numeric_limits<float>::infinity();

    for (auto &entity : _entities) {
        if (entity->getName() == "Human") {
            sf::Vector2f entityPosition = entity->getPosition();
            float xDistance = std::abs(entityPosition.x - position.x);
            float yDistance = std::abs(entityPosition.y - position.y);

            // Handle wraparound effect for x-axis
            if (xDistance > mapSize.x / 2) {
                xDistance = mapSize.x - xDistance;
                if (entityPosition.x < position.x)
                    entityPosition.x += mapSize.x;
                else
                    entityPosition.x -= mapSize.x;
            }

            // Handle wraparound effect for y-axis
            if (yDistance > mapSize.y / 2) {
                yDistance = mapSize.y - yDistance;
                if (entityPosition.y < position.y)
                    entityPosition.y += mapSize.y;
                else
                    entityPosition.y -= mapSize.y;
            }

            float distance = std::sqrt(xDistance * xDistance + yDistance * yDistance);

            if (distance < shortestDistance) {
                shortestDistance = distance;
                nearestHuman = entityPosition;
            }
        }
    }

    return nearestHuman;
}


sf::Vector2f Engine::getNearestZombie(sf::Vector2f position)
{
    sf::Vector2f nearestZombie = sf::Vector2f(-1, -1);
    float shortestDistance = std::numeric_limits<float>::infinity();

    for (auto &entity : _entities) {
        if (entity->getName() == "Zombie") {
            sf::Vector2f entityPosition = entity->getPosition();
            float xDistance = std::abs(entityPosition.x - position.x);
            float yDistance = std::abs(entityPosition.y - position.y);

            // Handle wraparound effect for x-axis
            if (xDistance > mapSize.x / 2) {
                xDistance = mapSize.x - xDistance;
                if (entityPosition.x < position.x)
                    entityPosition.x += mapSize.x;
                else
                    entityPosition.x -= mapSize.x;
            }

            // Handle wraparound effect for y-axis
            if (yDistance > mapSize.y / 2) {
                yDistance = mapSize.y - yDistance;
                if (entityPosition.y < position.y)
                    entityPosition.y += mapSize.y;
                else
                    entityPosition.y -= mapSize.y;
            }

            float distance = std::sqrt(xDistance * xDistance + yDistance * yDistance);

            if (distance < shortestDistance) {
                shortestDistance = distance;
                nearestZombie = entityPosition;
            }
        }
    }

    return nearestZombie;
}

