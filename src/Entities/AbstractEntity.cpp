/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "AbstractEntity.hpp"

ind::ORIENTATION ind::AbstractEntity::getRotation() const
{
    return this->rotation;
}

std::pair<float, float> ind::AbstractEntity::getPosition() const
{
    return this->position;
}

ind::AbstractEntity::AbstractEntity(std::pair<float, float> position,
    ind::ORIENTATION rotation, IBehaviour &behaviour
) : position(position), rotation(rotation), behaviour(behaviour)
{}

void ind::AbstractEntity::setRotation(ind::ORIENTATION orientation)
{
    this->rotation = orientation;
}

const ind::IBehaviour &ind::AbstractEntity::getBehaviour() const
{
    return this->behaviour;
}

void ind::AbstractEntity::setBehaviour(ind::IBehaviour &behaviour)
{
    this->behaviour = behaviour;
}
