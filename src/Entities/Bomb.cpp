/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Bomb.hpp"

ind::Bomb::Bomb(const ind::Position &position, ind::ORIENTATION rotation,
    ind::Map &map, int power) :
    AbstractEntity(position, rotation), map(map), power(power)
{}
