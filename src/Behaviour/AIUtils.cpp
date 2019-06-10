/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AiUtils.cpp
*/

#include "to2d.hpp"
#include "DirectionMap.hpp"
#include "AIUtils.hpp"

std::vector<ind::Position> ind::AIUtils::getAllFutureExplosionsPositions(const Board &board, const Position &pos)
{
    auto bombs = board.getAllBombs();
    std::vector<Position> positions;

    for (const auto &bomb : bombs) {
        auto row = bomb->getExplosionsPositions();
        positions.insert(positions.end(), row.begin(), row.end());
    }
    return positions;
}

std::vector<ind::Position> ind::AIUtils::getPositionsAroundWalkable(const Board &board, const Position &pos)
{
    std::vector<Position> positions;

    addPosIfWalkable(board, positions, pos.x + 1, pos.y);
    addPosIfWalkable(board, positions, pos.x - 1, pos.y);
    addPosIfWalkable(board, positions, pos.x, pos.y + 1);
    addPosIfWalkable(board, positions, pos.x, pos.y - 1);
    addPosIfWalkable(board, positions, pos.x + 1, pos.y + 1);
    addPosIfWalkable(board, positions, pos.x - 1, pos.y - 1);
    addPosIfWalkable(board, positions, pos.x + 1, pos.y - 1);
    addPosIfWalkable(board, positions, pos.x - 1, pos.y + 1);
    return positions;
}

void ind::AIUtils::addPosIfWalkable(const Board &board, std::vector<ind::Position> &positions, int x, int y)
{
    if (!board.in(Position(x, y)))
        return;

    const auto &type = board.getInfoAtCoord(x, y);

    if (type != BLOCKBREAKABLE && type != WALL && type != BOMB)
        positions.emplace_back(x, y);
}

ind::Orientation ind::AIUtils::posToDir(const Position &playerPos, const ind::Position &pos)
{
    if (pos.y > playerPos.y)
        return WEST;
    else if (pos.y < playerPos.y)
        return EAST;
    if (pos.x > playerPos.x)
        return NORTH;
    else if (pos.x < playerPos.x)
        return SOUTH;
    return NORTH;
}

bool ind::AIUtils::contain(const std::vector<ind::Position> &pos1, const std::vector<ind::Position> &pos2)
{
    for (auto &i : pos1)
        for (auto &j : pos2)
            if (i == j)
                return true;
    return false;
}

std::vector<ind::Position> ind::AIUtils::getPositionsAroundWithoutExplosion(const Board &board, const Position &pos)
{
    std::vector<Position> positions;
    auto positionsAround = getPositionsAroundWalkable(board, pos);
    auto futureExplosions = getAllFutureExplosionsPositions(board, pos);

    for (auto &p : positionsAround)
        if (std::find(futureExplosions.begin(), futureExplosions.end(), p) == futureExplosions.end())
            positions.push_back(p);
    return positions;
}

bool ind::AIUtils::isOnFutureExplosion(const Board &board, const ind::Position &pos)
{
    auto futureExplosions = getAllFutureExplosionsPositions(board, pos);
    auto it = std::find(futureExplosions.begin(), futureExplosions.end(), pos);

    return it != futureExplosions.end();
}
