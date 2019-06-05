/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** DirectionMap.cpp
*/

#include "DirectionMap.hpp"

const std::map<ind::Actions, ind::ORIENTATION> ind::DirectionMap::keyDirections = {
    {Up,    ind::NORTH},
    {Down,  ind::SOUTH},
    {Left,  ind::WEST},
    {Right, ind::EAST}
};

const std::map<ind::ORIENTATION, irr::core::vector3df> ind::DirectionMap::directionAngles = {
    {ind::NORTH, {0, 90,  0}},
    {ind::SOUTH, {0, 270, 0}},
    {ind::EAST,  {0, 180, 0}},
    {ind::WEST,  {0, 0,   0}}
};

