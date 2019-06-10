/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AiUtils.cpp
*/

#include "to2d.hpp"
#include "DirectionMap.hpp"
#include "AIUtils.hpp"

ind::AIUtils::AIUtils(ind::Player &player, ind::Board &board) :
    player(player),
    board(board)
{
}


std::vector<ind::Position> ind::AIUtils::getAllFutureExplosionsPositions() const
{
    auto bombs = board.getAllBombs();
    std::vector<Position> positions;

    for (const auto &bomb : bombs) {
        auto row = bomb->getExplosionsPositions();
        positions.insert(positions.end(), row.begin(), row.end());
    }
    return positions;
}

std::vector<ind::Position> ind::AIUtils::getPositionsAroundWalkable() const
{
    const auto &pos = player.getPosition();
    std::vector<Position> positions;

    addPosIfWalkable(positions, pos.x + 1, pos.y);
    addPosIfWalkable(positions, pos.x - 1, pos.y);
    addPosIfWalkable(positions, pos.x, pos.y + 1);
    addPosIfWalkable(positions, pos.x, pos.y - 1);
    addPosIfWalkable(positions, pos.x + 1, pos.y + 1);
    addPosIfWalkable(positions, pos.x - 1, pos.y - 1);
    addPosIfWalkable(positions, pos.x + 1, pos.y - 1);
    addPosIfWalkable(positions, pos.x - 1, pos.y + 1);
    return positions;
}

void ind::AIUtils::addPosIfWalkable(std::vector<ind::Position> &positions, int x, int y) const
{
    if (!board.in(Position(x, y)))
        return;

    const auto &type = board.getInfoAtCoord(x, y);

    if (type != BLOCKBREAKABLE && type != WALL && type != BOMB)
        positions.emplace_back(x, y);
}

ind::Actions ind::AIUtils::posToDir(const ind::Position &pos) const
{
    const auto &playerPos = player.getPosition();

    if (pos.y > playerPos.y)
        return Left;
    else if (pos.y < playerPos.y)
        return Right;
    if (pos.x > playerPos.x)
        return Up;
    else if (pos.x < playerPos.x)
        return Down;
    return Up;
}

bool ind::AIUtils::contain(const std::vector<ind::Position> &pos1, const std::vector<ind::Position> &pos2) const
{
    for (auto &i : pos1)
        for (auto &j : pos2)
            if (i == j)
                return true;
    return false;
}

std::vector<ind::Position> ind::AIUtils::getPositionsAroundWithoutExplosion() const
{
    std::vector<Position> positions;
    auto positionsAround = getPositionsAroundWalkable();
    auto futureExplosions = getAllFutureExplosionsPositions();

    for (auto &pos : positionsAround)
        if (std::find(futureExplosions.begin(), futureExplosions.end(), pos) == futureExplosions.end())
            positions.push_back(pos);
    return positions;
}

bool ind::AIUtils::isOnFutureExplosion(const ind::Position &pos) const
{
    auto futureExplosions = getAllFutureExplosionsPositions();
    auto it = std::find(futureExplosions.begin(), futureExplosions.end(), pos);

    return it != futureExplosions.end();
}
