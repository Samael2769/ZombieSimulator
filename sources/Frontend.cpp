/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:48:29
 * @ Modified by: Samael
 * @ Modified time: 2023-06-27 08:58:06
 * @ Description:
 */

#include "Frontend.hpp"
#include <iostream>

Frontend::Frontend(): _engine(), _config()
{
    _window.create(sf::VideoMode(std::stoi(_config._config["win_size_x"]), std::stoi(_config._config["win_size_y"])), "Zombie");
    _window.setFramerateLimit(60);
    _engine.setConfig(&_config);
    _engine.initSimulation(std::stoi(_config._config["nb_entities"]), std::stoi(_config._config["percent_infected"]));
}

Frontend::~Frontend()
{
}

void Frontend::run()
{
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(_config._config["map"]);
    sf::Sprite *sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    sf::Clock clock;
    clock.restart();
    sf::Time time = clock.getElapsedTime();

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
        time = clock.getElapsedTime();
        _engine.update(time);
        time = clock.restart();
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