/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_PATH_HPP
#define BOMBERMAN_PATH_HPP

#include <string>

namespace ind {
    class Path {
    public:
        static std::string realpath(const std::string &string);
        static void changePath(const std::string &string);
    private:
        static std::string progPath;
    };
}

#endif
