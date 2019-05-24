/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Position.hpp"
#include "to2d.hpp"

ind::Position ind::to2d(irr::core::vector3df pos3d)
{
    size_t x = (pos3d.X + 5) / 10.0f;
    size_t y = (pos3d.Z + 5) / 10.0f;

    return Position(x, y);
}
