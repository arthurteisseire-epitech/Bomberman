/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <memory>
#include "AbstractEntity.hpp"

ind::ORIENTATION ind::AbstractEntity::getRotation() const
{
    return rotation;
}

const ind::Position &ind::AbstractEntity::getPosition() const
{
    return boardPosition;
}

ind::AbstractEntity::AbstractEntity(const Position &boardPosition, ind::ORIENTATION rotation) :
    rotation(rotation),
    boardPosition(boardPosition)
{}

void ind::AbstractEntity::setRotation(ind::ORIENTATION orientation)
{
    rotation = orientation;
}

const ind::IBehaviour &ind::AbstractEntity::getBehaviour() const
{
    return *behaviour;
}

void ind::AbstractEntity::setBehaviour(IBehaviour *behaviour)
{
    this->behaviour = std::unique_ptr<IBehaviour>(behaviour);
}
