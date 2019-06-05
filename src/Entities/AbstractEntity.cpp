/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <memory>
#include <algorithm>
#include "AbstractEntity.hpp"
#include "Singleton.hpp"
#include "DeviceService.hpp"

ind::AbstractEntity::AbstractEntity() :
    manager(SingleTon<DeviceService>::getInstance().getSceneManager())
{}

void ind::AbstractEntity::setBehaviour(IBehaviour *newBehaviour)
{
    behaviour = std::unique_ptr<IBehaviour>(newBehaviour);
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
    children.erase(std::find(children.begin(), children.end(), entity));
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