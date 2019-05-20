/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <utility>

class IEntity {
    public:
        virtual ~IEntity() = default;
        virtual void draw() = 0;
        virtual void update(float deltaTime) = 0;

    protected:
        std::pair<float, float> position;
        //Asset
};
