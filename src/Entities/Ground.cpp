/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Ground.hpp"

ind::Ground::Ground(const ind::Position &boardPosition,
    ind::ORIENTATION rotation, irr::scene::IMeshSceneNode *object
) : AbstractEntity(boardPosition, rotation, object)
{}

void ind::Ground::draw()
{}
