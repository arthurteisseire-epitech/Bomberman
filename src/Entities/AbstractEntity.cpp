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

void ind::AbstractEntity::setBehaviour(IBehaviour *behaviour)
{
    this->behaviour = std::unique_ptr<IBehaviour>(behaviour);
}

void ind::AbstractEntity::update(float deltaTime)
{
    size_t list_size = this->children.size();

    for (auto &it : this->children) {
        if (this->children.size() != list_size) {
            this->update(deltaTime);
            return;
        }
        it->update(deltaTime);
    }
    if (this->behaviour)
        this->behaviour->update(deltaTime);
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
    if (found != this->children.end()) {
        this->children.erase(found++);
    }
}

void ind::AbstractEntity::move(ind::ORIENTATION direction, float deltaTime, float movementSpeed)
{
    this->rotation = direction;
    if (direction == NORTH) {
        this->force.Y -= deltaTime * movementSpeed;
    } else if (direction == SOUTH) {
        this->force.Y += deltaTime * movementSpeed;
    } else if (direction == WEST) {
        this->force.X -= deltaTime * movementSpeed;
    } else if (direction == EAST) {
        this->force.X += deltaTime * movementSpeed;
    }
}

irr::scene::IMeshSceneNode *ind::AbstractEntity::getObject()
{
    return this->object;
}

ind::AbstractEntity::~AbstractEntity()
{
    this->object->remove();
}

void ind::AbstractEntity::setPosition(Position &position)
{
    this->boardPosition = position;
}
