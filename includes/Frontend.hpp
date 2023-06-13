/**
 * @ Author: Samael
 * @ Create Time: 2023-06-13 06:45:36
 * @ Modified by: Samael
 * @ Modified time: 2023-06-13 06:55:07
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

    private:
        sf::RenderWindow _window;
        //engine _engine;

};
