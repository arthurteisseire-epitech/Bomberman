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
#include "ExplosionManager.hpp"
#include "Wall.hpp"

namespace ind {
    class Bomb;
    class Board {
    public:
        explicit Board(Position size);
        ~Board() = default;

        void update(float deltaTime);
        Tile getInfoAtCoord(int x, int y) const;
        Tile getInfoAtCoord(Position coord) const;
        Position getSize() const;
        void emptyTile(std::shared_ptr<BoardObject> &tile);
        void emptyTile(Position position);
        void explodeTile(const Position &position);
        void placeBomb(const Position &position, int power, const std::function<void(Bomb *)> &f);
        void removeDeadObjects();
        void killDeadPlayers();
        void putPowerUp(const Position &position);
        bool isOnExplosion(const Position &position) const;
        PowerUp *getPowerUp(const Position &position);
        std::vector<std::unique_ptr<Player>> &getPlayers();
        std::vector<Bomb *> getAllBombs() const;
        bool in(const Position &pos) const;
        bool isWalkable(const Position &pos) const;
        std::vector<Position> getAllExplosionsPositions() const;

    private:
        void printMap() const;
        void cleanCorners();
        void initGround();
        void initWall();
        void initBlocks();

        std::vector<std::unique_ptr<Player>> players;
        std::vector<std::vector<std::unique_ptr<Ground>>> ground;
        std::vector<std::vector<std::shared_ptr<BoardObject>>> map;
        std::vector<std::vector<std::unique_ptr<Wall>>> walls;
        TimeoutObjectManager<BoardObject> timeoutObjectManager;
        ExplosionManager explosionManager;
        Position size;
    };
}
