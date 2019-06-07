/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AiBehaviour.cpp
*/

#include "DirectionMap.hpp"
#include "PathfindingService.hpp"
#include "Singleton.hpp"
#include "AIBehaviour.hpp"

ind::AIBehaviour::AIBehaviour(ind::Player &player, Board &board) :
    player(player),
    board(board)
{
}

void ind::AIBehaviour::update(float deltaTime)
{
    player.checkDeath();
    const Position &targetPos = board.getPlayers()[0]->getPosition();
    auto posToTarget = SingleTon<PathfindingService>::getInstance().searchPath(board, player.getPosition(), targetPos);

    if (!posToTarget.empty() && !contain(board.getAllExplosionsPositions(), getPositionsAround())) {
        if (player.getAction() != Actions::Walking) {
            player.getAnimator().setCurrentAnimation("walk").playAnimation();
            player.setAction(Actions::Walking);
        }
        move(deltaTime, posToDir(posToTarget[1]));
    } else {
        if (player.getAction() == Actions::Walking) {
            player.getAnimator().setCurrentAnimation("idle").playAnimation();
            player.setAction(Actions::Down);
        }
    }
}

void ind::AIBehaviour::move(float deltaTime, ind::Actions direction) const
{
    player.setDirection(ind::DirectionMap::keyDirections.at(direction));
    player.getAnimator().setAnimationsRotation(
        ind::DirectionMap::directionAngles.at(ind::DirectionMap::keyDirections.at(direction)));
    player.move(ind::DirectionMap::keyDirections.at(direction), deltaTime, player.getSpeed());
    player.draw();
}

std::vector<ind::Position> ind::AIBehaviour::getAllFutureExplosionsPositions() const
{
    auto bombs = board.getAllBombs();
    std::vector<Position> positions;

    for (const auto &bomb : bombs) {
        auto row = bomb->getExplosionsPositions();
        positions.insert(positions.end(), row.begin(), row.end());
    }
    return positions;
}

std::vector<ind::Position> ind::AIBehaviour::getPositionsAround() const
{
    const auto &pos = player.getPosition();
    std::vector<Position> positions;

    addPosIfInMap(positions, pos.x + 1, pos.y);
    addPosIfInMap(positions, pos.x - 1, pos.y);
    addPosIfInMap(positions, pos.x, pos.y + 1);
    addPosIfInMap(positions, pos.x, pos.y - 1);
    addPosIfInMap(positions, pos.x + 1, pos.y + 1);
    addPosIfInMap(positions, pos.x - 1, pos.y - 1);
    addPosIfInMap(positions, pos.x + 1, pos.y - 1);
    addPosIfInMap(positions, pos.x - 1, pos.y + 1);
    return positions;
}

void ind::AIBehaviour::addPosIfInMap(std::vector<ind::Position> &positions, int x, int y) const
{
    if (board.in(Position(x, y)))
        positions.emplace_back(x, y);
}

ind::Actions ind::AIBehaviour::posToDir(const ind::Position &pos) const
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

bool ind::AIBehaviour::contain(const std::vector<ind::Position> &pos1, const std::vector<ind::Position> &pos2) const
{
    if (pos1.empty())
        std::cout << "no explosions" << std::endl;
    else if (pos2.empty())
        std::cout << "no pos around" << std::endl;
    for (auto &i : pos1) {
        for (auto &j : pos2) {
            if (i == j) {
                std::cout << "same pos : " << i << std::endl;
                return true;
            } else {
                std::cout << i << " != " << j << std::endl;
            }
        }
    }
    return false;
}
