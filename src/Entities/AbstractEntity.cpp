/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "AbstractEntity.hpp"

ind::ORIENTATION ind::AbstractEntity::getRotation() const
{
    return rotation;
}

const ind::Position &ind::AbstractEntity::getPosition() const
{
    return boardPosition;
}

ind::AbstractEntity::AbstractEntity(const Position &boardPosition, ind::ORIENTATION rotation, IBehaviour &behaviour) :
    rotation(rotation),
    boardPosition(boardPosition),
    behaviour(behaviour)
{}

void ind::AbstractEntity::setRotation(ind::ORIENTATION orientation)
{
    rotation = orientation;
}

const ind::IBehaviour &ind::AbstractEntity::getBehaviour() const
{
    return behaviour;
}
