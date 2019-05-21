/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <utility>
#include "Orientation.hpp"
#include "IBehaviour.hpp"

namespace ind {

    class AbstractEntity {
        public:
            AbstractEntity(std::pair<float, float> position, ORIENTATION rotation, IBehaviour &behaviour);
            virtual ~AbstractEntity() = default;
            virtual void draw() = 0;
            virtual void update(float deltaTime) = 0;
            std::pair<float, float> getPosition() const;
            ORIENTATION getRotation() const;
            void setRotation(ORIENTATION orientation);
            const IBehaviour &getBehaviour() const;
            void setBehaviour(IBehaviour &);

        protected:
            ORIENTATION rotation;
            std::pair<float, float> position;
            IBehaviour &behaviour;
    };
}
