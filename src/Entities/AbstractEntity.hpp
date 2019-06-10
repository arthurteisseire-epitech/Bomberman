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
        explicit AbstractEntity();
        virtual ~AbstractEntity() = default;
        void updateForce(Orientation direction, float deltaTime, float movementSpeed);
        virtual void update(float deltaTime);
        void addChild(AbstractEntity *entity);
        void removeChild(AbstractEntity *entity);
        void setBehaviour(IBehaviour *newBehaviour);

    protected:
        std::unique_ptr<IBehaviour> behaviour = nullptr;
        std::vector<AbstractEntity *> children;
        irr::core::vector2df force;
	    irr::scene::ISceneManager *manager;
    };
}
