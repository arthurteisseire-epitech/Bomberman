/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <vector>
#include <utility>
#include "AbstractEntity.hpp"
#include "BoardObject.hpp"
#include "Ground.hpp"
#include "Tile.hpp"
#include "TimeoutObjectManager.hpp"

namespace ind {
    class Board : public AbstractEntity {
    public:
        explicit Board(Position size);
        ~Board() override = default;
        Tile getInfoAtCoord(Position coord) const;
        void printMap() const;
        Position getSize() const;
        void emptyTile(std::shared_ptr<BoardObject> &tile);
        void emptyTile(Position position);
        void explodeTile(const Position &position);
        void updateTimeoutObjects(float deltaTime);
        void cleanCorners();
        void initGround();
        void initBlocks();

    private:
        std::vector<std::vector<std::unique_ptr<Ground>>> ground;
        std::vector<std::vector<std::shared_ptr<BoardObject>>> map;
        TimeoutObjectManager<BoardObject> timeoutObjectManager;
        Position size;
    };
}
