/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <utility>
#include <memory>
#include <vector>
#include <irrlicht/irrlicht.h>
#include "Orientation.hpp"
#include "IBehaviour.hpp"
#include "Position.hpp"

namespace ind {

    class AbstractEntity {
    public:
        explicit AbstractEntity(irr::scene::ISceneManager *mgr);
        virtual ~AbstractEntity() = default;
        void move(ORIENTATION direction, float deltaTime, float movementSpeed);
        virtual void update(float deltaTime);
        void addChild(AbstractEntity *entity);
        void removeChild(AbstractEntity *entity);
        void setBehaviour(IBehaviour *newBehavior);

    protected:
        irr::scene::ISceneManager *manager;
        std::unique_ptr<IBehaviour> behaviour = nullptr;
        std::vector<std::unique_ptr<AbstractEntity>> children;
        irr::core::vector2df force;
    };
}
