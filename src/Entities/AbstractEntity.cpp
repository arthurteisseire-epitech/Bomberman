/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <memory>
#include <algorithm>
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

void ind::AbstractEntity::update(float deltaTime)
{
    this->behaviour->update(deltaTime);
    for (auto &it : this->children) {
        it->update(deltaTime);
    }
}

void ind::AbstractEntity::addChild(ind::AbstractEntity *entity)
{
    this->children.emplace_back(entity);
}

void ind::AbstractEntity::removeChild(ind::AbstractEntity *entity)
{
    auto found = std::find_if(this->children.begin(), this->children.end(),
        [entity](std::unique_ptr<AbstractEntity> &elem) {
        return entity == elem.get();
    });
    if (found != this->children.end())
        this->children.erase(found);
}
