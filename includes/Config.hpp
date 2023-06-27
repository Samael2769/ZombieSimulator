/**
 * @ Author: Samael
 * @ Create Time: 2023-06-27 08:00:37
 * @ Modified by: Samael
 * @ Modified time: 2023-06-27 08:10:53
 * @ Description:
 */

#pragma once
#include <string>
#include <map>

class Config {
    public:
        Config();
        ~Config();
        
        std::map<std::string, std::string> _config;
    private:
};