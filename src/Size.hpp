/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Size.hpp
*/

#ifndef BOMBERMAN_SIZE_HPP
#define BOMBERMAN_SIZE_HPP

#include <cstddef>

namespace ind {
    struct Size {
        Size(size_t width, size_t height) : width(width), height(height)
        {}

        size_t width;
        size_t height;
    };
}

#endif
