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
#include "TimeoutObject.hpp"

namespace ind {

    class Board;
    class Bomb : public BoardObject, public TimeoutObject {

    public:
        Bomb(const Position &position, Board &map, int power, std::function<void(Bomb *bomb)> onExplode);
        ~Bomb() override = default;
        Tile getTile() const override;
        void explode();
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
        std::function<void(Bomb *bomb)> onExplode;
    };
}
