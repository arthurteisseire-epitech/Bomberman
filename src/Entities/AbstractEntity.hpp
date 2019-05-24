/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <utility>
#include <irrlicht/IMeshSceneNode.h>
#include <memory>
#include <vector>
#include "Orientation.hpp"
#include "IBehaviour.hpp"
#include "Position.hpp"

namespace ind {

    class AbstractEntity {
        public:
            AbstractEntity(const Position &boardPosition, ORIENTATION rotation, irr::scene::IMeshSceneNode *object);
            AbstractEntity(const AbstractEntity &) = default;
            virtual ~AbstractEntity() = default;
            virtual void draw() = 0;
            void move(ORIENTATION direction, float deltaTime, float movementSpeed);
            virtual void update(float deltaTime);
            const Position &getPosition() const;
            ORIENTATION getRotation() const;
            void addChild(AbstractEntity *entity);
            void removeChild(AbstractEntity *entity);
            void setRotation(ORIENTATION orientation);
            const IBehaviour &getBehaviour() const;
            void setBehaviour(IBehaviour *behaviour);
            irr::scene::IMeshSceneNode *getObject();

        protected:
            ORIENTATION rotation;
            Position boardPosition;
            std::unique_ptr<IBehaviour> behaviour = nullptr;
            std::vector<std::unique_ptr<AbstractEntity>> children;
            irr::core::vector2df force;
            irr::scene::IMeshSceneNode *object;
    };
}
