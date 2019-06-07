/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AiBehaviour.cpp
*/

#include <Utilities/DirectionMap.hpp>
#include "AIBehaviour.hpp"

ind::AIBehaviour::AIBehaviour(ind::Player &player, Board &board) :
    player(player),
    board(board)
{
}

void ind::AIBehaviour::update(float deltaTime)
{
    player.checkDeath();

    if (board.isOnExplosion(player.getPosition())) {
        if (this->player.getAction() != Actions::Walking) {
            player.getAnimator().setCurrentAnimation("walk").playAnimation();
            player.setAction(Actions::Walking);
        }
        player.setDirection(DirectionMap::keyDirections.at(Up));
        player.getAnimator().setAnimationsRotation(
            DirectionMap::directionAngles.at(DirectionMap::keyDirections.at(Up)));
        player.move(DirectionMap::keyDirections.at(Up), deltaTime, player.getSpeed());
        player.draw();
    }
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
