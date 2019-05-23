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
#include "Orientation.hpp"
#include "IBehaviour.hpp"
#include "Position.hpp"

namespace ind {

    class AbstractEntity {
        public:
            AbstractEntity(const Position &boardPosition, ORIENTATION rotation);
            virtual ~AbstractEntity() = default;
            virtual void draw() = 0;
            virtual void update(float deltaTime) = 0;
            const Position &getPosition() const;
            ORIENTATION getRotation() const;
            void setRotation(ORIENTATION orientation);
            const IBehaviour &getBehaviour() const;
            void setBehaviour(IBehaviour *behaviour);

        protected:
            ORIENTATION rotation;
            Position boardPosition;
            std::unique_ptr<IBehaviour> behaviour = nullptr;
    };
}
