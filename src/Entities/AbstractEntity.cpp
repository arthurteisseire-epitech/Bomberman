/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <memory>
#include <algorithm>
#include <iostream>
#include "AbstractEntity.hpp"

ind::ORIENTATION ind::AbstractEntity::getRotation() const
{
    return rotation;
}

const ind::Position &ind::AbstractEntity::getPosition() const
{
    return boardPosition;
}

ind::AbstractEntity::AbstractEntity(const Position &boardPosition, ind::ORIENTATION rotation, irr::scene::IMeshSceneNode *object) :
    rotation(rotation),
    boardPosition(boardPosition),
    object(object)
{}

void ind::AbstractEntity::setRotation(ind::ORIENTATION orientation)
{
    rotation = orientation;
}

const ind::IBehaviour &ind::AbstractEntity::getBehaviour() const
{
    return *behaviour;
}

void ind::AbstractEntity::setBehaviour(IBehaviour *newBehavior)
{
    behaviour = std::unique_ptr<IBehaviour>(newBehavior);
}

void ind::AbstractEntity::update(float deltaTime)
{
    size_t list_size = children.size();

    for (auto &it : children) {
        if (children.size() != list_size) {
            update(deltaTime);
            return;
        }
        it->update(deltaTime);
    }
    if (behaviour)
        behaviour->update(deltaTime);
}

void ind::AbstractEntity::addChild(ind::AbstractEntity *entity)
{
    children.emplace_back(entity);
}

void ind::AbstractEntity::removeChild(ind::AbstractEntity *entity)
{
    auto found = std::find_if(children.begin(), children.end(),
        [entity](std::unique_ptr<AbstractEntity> &elem) {
        return entity == elem.get();
    });
    if (found != children.end()) {
        children.erase(found++);
    }
}

void ind::AbstractEntity::move(ind::ORIENTATION direction, float deltaTime, float movementSpeed)
{
    rotation = direction;
    if (direction == NORTH) {
        force.Y -= deltaTime * movementSpeed;
    } else if (direction == SOUTH) {
        force.Y += deltaTime * movementSpeed;
    } else if (direction == WEST) {
        force.X -= deltaTime * movementSpeed;
    } else if (direction == EAST) {
        force.X += deltaTime * movementSpeed;
    }
}

irr::scene::IMeshSceneNode *ind::AbstractEntity::getObject()
{
    return object;
}

ind::AbstractEntity::~AbstractEntity()
{
    object->remove();
}

void ind::AbstractEntity::setPosition(Position &position)
{
    boardPosition = position;
}
