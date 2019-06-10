/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <iostream>

namespace ind {
    enum Orientation {
        NORTH,
        SOUTH,
        EAST,
        WEST,
        NONE,
    };
    std::ostream &operator<<(std::ostream &os, Orientation orientation);
}
