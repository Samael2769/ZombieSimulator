/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:45:36
 * @ Modified by: Samael
 * @ Modified time: 2023-06-27 08:09:13
 * @ Description:
 */

#pragma once
#include "Engine.hpp"

class Frontend
{
    public:
        Frontend();
        ~Frontend();
        void run();
        void print();

    private:
        sf::RenderWindow _window;
        Engine _engine;
        Config _config;

};
