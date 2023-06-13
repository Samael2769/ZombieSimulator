/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:48:29
 * @ Modified by: Samael
 * @ Modified time: 2023-06-13 06:54:56
 * @ Description:
 */

#include "Frontend.hpp"

Frontend::Frontend()
{
    _window.create(sf::VideoMode(800, 600), "Zombie Simulator");
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
        _window.display();
    }
}