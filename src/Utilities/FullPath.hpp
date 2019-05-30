/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_FULLPATH_HPP
#define BOMBERMAN_FULLPATH_HPP

#include <string>

namespace ind {
    class FullPath {
    public:
        static std::string concatenate(std::string &string);
        static void changePath(const std::string &string);
    private:
        static std::string progPath;
    };
}

#endif
