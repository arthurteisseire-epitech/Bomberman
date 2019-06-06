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
        ~Bomb() override;
        Tile getTile() const override;
        void explode();
        int getPower() const;

        template<typename Func>
        void explodeRow(Func getPosAt)
        {
            for (int i = 1; i < power; ++i)
                if (explodeTile(getPosAt(i)))
                    return;
        }

        template<typename Func>
        std::vector<Position> getRowPositions(Func getPosAt) const
        {
            std::vector<Position> positions;

            positions.reserve(power - 1);
            for (int i = 1; i < power; ++i) {
                if (!isExplosionStop(getPosAt(i)))
                    positions.emplace_back(getPosAt(i));
                else
                    break;
            }
            return positions;
        }

        bool explodeTile(const ind::Position &pos);
        std::vector<Position> getExplosionsPositions() const;

    private:
        bool isExplosionStop(const Position &pos) const;

        Board &map;
        int power;
        std::function<void(Bomb *bomb)> onExplode;
        std::vector<Position> toExplode;
    };
}
