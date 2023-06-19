/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:48:29
 * @ Modified by: Samael
 * @ Modified time: 2023-06-19 18:45:22
 * @ Description:
 */

#include "Frontend.hpp"
#include <iostream>

Frontend::Frontend()
{
    _window.create(sf::VideoMode(800, 600), "Zombie Simulator");
    _window.setFramerateLimit(60);
    _engine.initSimulation(100, 20);
}

Frontend::~Frontend()
{
}

void Frontend::run()
{
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile("Assets/map.jpg");
    sf::Sprite *sprite = new sf::Sprite();
    sprite->setTexture(*texture);

    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                _window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    _window.close();
                }
            }
        }
        _window.clear();
        _window.draw(*sprite);
        _engine.update();
        print();
        _window.display();
    }
}

void Frontend::print()
{
    for (auto entity : _engine.getEntities()) {
        entity->draw(_window);
    }
}