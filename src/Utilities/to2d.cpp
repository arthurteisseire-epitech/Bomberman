/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Tiles.hpp"
#include "Position.hpp"
#include "to2d.hpp"

ind::Position ind::to2d(const irr::core::vector3df& pos3d)
{
    size_t x = (int)((pos3d.X + TILE_SIZE / 2) / TILE_SIZE);
    size_t y = (int)((pos3d.Z + TILE_SIZE / 2) / TILE_SIZE);

    return {x, y};
}
