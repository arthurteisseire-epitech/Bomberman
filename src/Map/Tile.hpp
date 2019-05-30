/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#define TILE_SIZE 10.0f

namespace ind
{
    enum Tile : int {
        EMPTY = 1,
        BLOCKBREAKABLE = 2,
        POWERUP = 3,
        BOMB = 6,
        EXPLOSION = 7,
    };
}
