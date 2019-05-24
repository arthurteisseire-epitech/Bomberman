/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include "AbstractEntity.hpp"

namespace ind {

    class Ground : public AbstractEntity {
        public:
            Ground(const Position &boardPosition, ORIENTATION rotation, irr::scene::IMeshSceneNode *object);
            ~Ground() override = default;
            void draw() override;
    };
}
