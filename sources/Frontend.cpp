/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:48:29
 * @ Modified by: Samael
 * @ Modified time: 2023-06-15 07:07:07
 * @ Description:
 */

#include "Frontend.hpp"

Frontend::Frontend()
{
    _window.create(sf::VideoMode(800, 600), "Zombie Simulator");
    IEntity *human = new Human();
    IEntity *zombie = new Zombie();
    _engine.addEntity(human);
    _engine.addEntity(zombie);
}

Frontend::~Frontend()
{
}

void Frontend::run()
{
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