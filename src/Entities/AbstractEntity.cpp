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
#include "Singleton.hpp"
#include "DeviceService.hpp"

ind::AbstractEntity::AbstractEntity() :
    manager(SingleTon<DeviceService>::getInstance().getSceneManager())
{}

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
        [entity](AbstractEntity *elem) {
        return entity == elem;
    });
    if (found != children.end()) {
        children.erase(found++);
    }
}

void ind::AbstractEntity::move(ORIENTATION direction, float deltaTime, float movementSpeed)
{
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
