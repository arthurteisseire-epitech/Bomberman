/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AiUtils.cpp
*/

#include "PathfindingService.hpp"
#include "Singleton.hpp"
#include "to2d.hpp"
#include "DirectionMap.hpp"
#include "AIUtils.hpp"

ind::Position ind::AIUtils::findAvailablePositionAround(const ind::Board &board, const ind::Position &playerPos)
{
    auto &pathFinding = SingleTon<PathfindingService>::getInstance();
    const auto positions = getPositionsAroundWithoutFutureExplosion(board, playerPos);

    for (const auto &pos : positions) {
        const auto &v = pathFinding.searchPath(board, playerPos, pos);
        if (v.size() > 1)
            return v.at(1);
    }
    return playerPos;
}

std::vector<ind::Position>
ind::AIUtils::getPositionsAroundWithoutFutureExplosion(const Board &board, const Position &pos)
{
    auto positions = getPositionsAroundWalkable(board, pos);

    positions.erase(std::remove_if(positions.begin(), positions.end(), [&](const Position &position) {
        return isOnFutureExplosion(board, position);
    }), positions.end());
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
    addPosIfInMap(board, positions, pos.x - 1, pos.y - 1);
    addPosIfInMap(board, positions, pos.x + 1, pos.y - 1);
    addPosIfInMap(board, positions, pos.x - 1, pos.y + 1);

    addPosIfInMap(board, positions, pos.x + 2, pos.y);
    addPosIfInMap(board, positions, pos.x - 2, pos.y);
    addPosIfInMap(board, positions, pos.x, pos.y + 2);
    addPosIfInMap(board, positions, pos.x, pos.y - 2);

    addPosIfInMap(board, positions, pos.x + 2, pos.y + 1);
    addPosIfInMap(board, positions, pos.x + 1, pos.y + 2);

    addPosIfInMap(board, positions, pos.x - 2, pos.y - 1);
    addPosIfInMap(board, positions, pos.x - 1, pos.y - 2);

    addPosIfInMap(board, positions, pos.x + 2, pos.y - 1);
    addPosIfInMap(board, positions, pos.x + 1, pos.y - 2);

    addPosIfInMap(board, positions, pos.x - 2, pos.y + 1);
    addPosIfInMap(board, positions, pos.x - 1, pos.y + 2);

    addPosIfInMap(board, positions, pos.x + 2, pos.y + 2);
    addPosIfInMap(board, positions, pos.x - 2, pos.y - 2);
    addPosIfInMap(board, positions, pos.x + 2, pos.y - 2);
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

bool ind::AIUtils::isOnFutureExplosion(const Board &board, const ind::Position &pos)
{
    auto futureExplosions = getAllFutureExplosionsPositions(board, pos);
    auto it = std::find(futureExplosions.begin(), futureExplosions.end(), pos);

    return it != futureExplosions.end();
}

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

std::vector<ind::Position> ind::AIUtils::findBlockBreakable(const ind::Board &board, const ind::Position &playerPos)
{
    size_t min = std::string::npos;
    std::vector<std::vector<Position>> positions;
    std::vector<Position> res;

    positions.push_back(applyUntil(board, [&](int i) { return Position(playerPos.x, playerPos.y - i); }));
    positions.push_back(applyUntil(board, [&](int i) { return Position(playerPos.x, playerPos.y + i); }));
    positions.push_back(applyUntil(board, [&](int i) { return Position(playerPos.x - i, playerPos.y); }));
    positions.push_back(applyUntil(board, [&](int i) { return Position(playerPos.x + i, playerPos.y); }));

    for (auto &v : positions) {
        if (!v.empty() && v.size() < min) {
            min = v.size();
            res = v;
        }
    }
    return res;
}

bool ind::AIUtils::isBlockBreakableAround(const ind::Board &board, const ind::Position &playerPos)
{
    auto positions = getPositionsAside(board, playerPos);

    for (const auto &pos : positions)
        if (board.getInfoAtCoord(pos) == BLOCKBREAKABLE)
            return true;
    return false;
}

std::vector<ind::Position> ind::AIUtils::findNearestPlayerPositions(ind::Board &board, const ind::Position &AIPos)
{
    std::size_t min = std::string::npos;
    auto &pathFinding = SingleTon<PathfindingService>::getInstance();
    auto &players = board.getPlayers();
    std::vector<Position> positions;

    for (auto &player : players) {
        if (player->getPosition() != AIPos) {
            auto tmp = pathFinding.searchPath(board, AIPos, player->getPosition());
            if (!tmp.empty() && tmp.size() < min) {
                positions = tmp;
                min = tmp.size();
            }
        }
    }
    return positions;
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
