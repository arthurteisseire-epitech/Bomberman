/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <vector>
#include <utility>
#include "PowerUp.hpp"
#include "AbstractEntity.hpp"
#include "BoardObject.hpp"
#include "Ground.hpp"
#include "Tile.hpp"
#include "TimeoutObjectManager.hpp"
#include "Bomb.hpp"

namespace ind {
    class Bomb;
    class Board : public AbstractEntity {
    public:
        explicit Board(Position size);
        ~Board() override = default;
        Tile getInfoAtCoord(Position coord) const;
        Position getSize() const;
        void emptyTile(std::shared_ptr<BoardObject> &tile);
        void emptyTile(Position position);
        void explodeTile(const Position &position);
        void placeBomb(const Position &position, int power, const std::function<void(Bomb *)> &f);
        void removeDeadObjects();
        void putPowerUp(const Position &position);
        PowerUp *getPowerUp(const Position &position);
        irr::scene::IMeshSceneNode *initializePlayerCube() const;

    private:
        void printMap() const;
        void cleanCorners();
        void initGround();
        void initBlocks();

        std::vector<std::unique_ptr<Player>> players;
        std::vector<std::vector<std::unique_ptr<Ground>>> ground;
        std::vector<std::vector<std::shared_ptr<BoardObject>>> map;
        TimeoutObjectManager<BoardObject> timeoutObjectManager;
        Position size;
    };
}
