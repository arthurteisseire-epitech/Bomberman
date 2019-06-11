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
    auto positions = getPositionsAround(board, pos);

    positions.erase(std::remove_if(positions.begin(), positions.end(), [&](const Position &position) {
        return !board.isWalkable(position);
    }), positions.end());
    return positions;
}

std::vector<ind::Position> ind::AIUtils::getPositionsAround(const ind::Board &board, const ind::Position &pos)
{
    auto positions = getPositionsAside(board, pos);

    addPosIfInMap(board, positions, pos.x + 1, pos.y + 1);
    addPosIfInMap(board, positions, pos.x + 2, pos.y + 1);
    addPosIfInMap(board, positions, pos.x + 1, pos.y + 2);
    addPosIfInMap(board, positions, pos.x + 2, pos.y + 2);

    addPosIfInMap(board, positions, pos.x - 1, pos.y - 1);
    addPosIfInMap(board, positions, pos.x - 2, pos.y - 1);
    addPosIfInMap(board, positions, pos.x - 1, pos.y - 2);
    addPosIfInMap(board, positions, pos.x - 2, pos.y - 2);

    addPosIfInMap(board, positions, pos.x + 1, pos.y - 1);
    addPosIfInMap(board, positions, pos.x + 2, pos.y - 1);
    addPosIfInMap(board, positions, pos.x + 1, pos.y - 2);
    addPosIfInMap(board, positions, pos.x + 2, pos.y - 2);

    addPosIfInMap(board, positions, pos.x - 1, pos.y + 1);
    addPosIfInMap(board, positions, pos.x - 2, pos.y + 1);
    addPosIfInMap(board, positions, pos.x - 1, pos.y + 2);
    addPosIfInMap(board, positions, pos.x - 2, pos.y + 2);
    return positions;
}

std::vector<ind::Position> ind::AIUtils::getPositionsAside(const ind::Board &board, const ind::Position &pos)
{
    std::vector<Position> positions;

    addPosIfInMap(board, positions, pos.x + 1, pos.y);
    addPosIfInMap(board, positions, pos.x - 1, pos.y);
    addPosIfInMap(board, positions, pos.x, pos.y + 1);
    addPosIfInMap(board, positions, pos.x, pos.y - 1);
    return positions;
}

void ind::AIUtils::addPosIfInMap(const Board &board, std::vector<ind::Position> &positions, int x, int y)
{
    if (board.in(Position(x, y)))
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

bool ind::AIUtils::isBlockBreakableAround(const ind::Board &board, const ind::Position &playerPos)
{
    auto positions = getPositionsAside(board, playerPos);

    for (const auto &pos : positions)
        if (board.getInfoAtCoord(pos) == BLOCKBREAKABLE)
            return true;
    return false;
}

bool ind::AIUtils::isOnFutureExplosion(const Board &board, const ind::Position &pos)
{
    auto futureExplosions = getAllFutureExplosionsPositions(board, pos);
    auto it = std::find(futureExplosions.begin(), futureExplosions.end(), pos);

    return it != futureExplosions.end();
}

std::vector<ind::Position> ind::AIUtils::findBlockBreakable(const ind::Board &board, const ind::Position &playerPos)
{
    std::vector<Position> positions;

    applyUntil(board, positions, [&](int i) { return Position(playerPos.x, playerPos.y - i); });
    applyUntil(board, positions, [&](int i) { return Position(playerPos.x, playerPos.y + i); });
    applyUntil(board, positions, [&](int i) { return Position(playerPos.x - i, playerPos.y); });
    applyUntil(board, positions, [&](int i) { return Position(playerPos.x + i, playerPos.y); });
    return positions;
}
