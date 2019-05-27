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
    enum Tiles : int {
        EMPTY = 1,
        BLOCKBREAKABLE = 2,
        BOMBUP = 3,
        SPEEDUP = 4,
        BOMBPOWERUP = 5,
        BOMB = 6,
        EXPLOSION = 7,
    };
}
