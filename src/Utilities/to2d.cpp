/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Position.hpp"
#include "to2d.hpp"

ind::Position ind::to2d(const irr::core::vector3df& pos3d)
{
    auto x = (size_t)((pos3d.X + 5) / 10.0f);
    auto y = (size_t)((pos3d.Z + 5) / 10.0f);

    return {x, y};
}
