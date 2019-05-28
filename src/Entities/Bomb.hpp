/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <functional>
#include "AbstractEntity.hpp"
#include "Board.hpp"

namespace ind {

    class Bomb : public AbstractEntity {

    public:
        Bomb(const Position &position, ORIENTATION rotation, Board &map, int power,
             std::function<void(Bomb *bomb)> onExplode, irr::scene::IMeshSceneNode *object);
        ~Bomb() override = default;
        void decreaseTime(float n);
        void explode();
        float getTime() const;
        void draw() override;
        bool inMap(const Position &pos) const;

        template <typename Func>
        void explodeRow(Func getPosAt)
        {
            for (int i = 1; i < power; ++i)
                if (explodeTile(getPosAt(i)))
                    return;
        }
        bool explodeTile(const ind::Position &pos);

    private:
        Board &map;
        int power;
        float timeBeforeExplosion = 1.0f;
        std::function<void(Bomb *bomb)> onExplode;
    };
}
