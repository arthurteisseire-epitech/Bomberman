/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <algorithm>
#include "Tile.hpp"
#include "Position.hpp"
#include "to2d.hpp"

ind::Position ind::to2d(const irr::core::vector3df &pos3d)
{
    int x = static_cast<int>((pos3d.X + TILE_SIZE / 2) / TILE_SIZE);
    int y = static_cast<int>((pos3d.Z + TILE_SIZE / 2) / TILE_SIZE);

    return {x, y};
}

irr::core::vector3df ind::to3d(const ind::Position &pos2d)
{
    return irr::core::vector3df(std::max<int>(pos2d.y * TILE_SIZE - TILE_SIZE / 10.0f, 0), 0,
				    std::max<int>(pos2d.x * TILE_SIZE - TILE_SIZE / 10.0f, 0));
}
