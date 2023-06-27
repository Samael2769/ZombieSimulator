/**
 * @ Author: Samael
 * @ Create Time: 2023-06-27 08:02:02
 * @ Modified by: Samael
 * @ Modified time: 2023-06-27 08:21:44
 * @ Description:
 */

#include "Config.hpp"
#include <fstream>
#include <iostream>

Config::Config()
{
    std::string file = "./Assets/init.conf";
    std::ifstream ifs(file);
    std::string line;
    for (int i = 0; std::getline(ifs, line); i++) {
        std::string key = line.substr(0, line.find("="));
        std::string value = line.substr(line.find("=") + 1, line.size());
        _config[key] = value;
    }
}

Config::~Config()
{
}