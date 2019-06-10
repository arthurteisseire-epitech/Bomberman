/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AiBehaviour.cpp
*/

#include "to2d.hpp"
#include "DirectionMap.hpp"
#include "PathfindingService.hpp"
#include "Singleton.hpp"
#include "AIBehaviour.hpp"

ind::AIBehaviour::AIBehaviour(ind::Player &player, Board &board) :
    player(player),
    board(board),
    state(MOVE_TO_PLAYER),
    prevDir(Up),
    deltaTime(0)
{
    alterStateMap = {
        {DODGE,          [this]() { alterDodge(); }},
        {MOVE_TO_PLAYER, [this]() { alterMoveToPlayer(); }},
    };

    actionStateMap = {
        {DODGE,          [this]() { actionDodge(); }},
        {MOVE_TO_PLAYER, [this]() { actionMoveToPlayer(); }},
    };
}

void ind::AIBehaviour::update(float dt)
{
    deltaTime = dt;
    player.checkDeath();

    if (!AIUtils::contain(board.getAllExplosionsPositions(), AIUtils::getPositionsAroundWalkable(board, player.getPosition()))) {
        action();
    } else {
        if (player.getAction() == Actions::Walking) {
            player.getAnimator().setCurrentAnimation("idle").playAnimation();
            player.setAction(Actions::Down);
        }
    }
}

void ind::AIBehaviour::action()
{
    execFromMap(alterStateMap);
    execFromMap(actionStateMap);
}

void ind::AIBehaviour::execFromMap(const std::map<State, std::function<void()>> &map)
{
    for (auto &pair : map)
        if (pair.first == state) {
            pair.second();
            break;
        }
}

void ind::AIBehaviour::alterDodge()
{
}

void ind::AIBehaviour::alterMoveToPlayer()
{
    if (AIUtils::isOnFutureExplosion(board, player.getPosition()))
        state = DODGE;
}

void ind::AIBehaviour::actionDodge()
{
    std::vector<Position> pos = AIUtils::getPositionsAroundWithoutExplosion(board, player.getPosition());

    if (!pos.empty())
        move(AIUtils::posToDir(player.getPosition(), pos.at(0)));
}

void ind::AIBehaviour::actionMoveToPlayer()
{
    const Position &targetPos = board.getPlayers()[0]->getPosition();
    auto posToTarget = SingleTon<PathfindingService>::getInstance().searchPath(board, player.getPosition(), targetPos);

    if (posToTarget.size() > 2)
        move(AIUtils::posToDir(player.getPosition(), posToTarget.at(1)));
}

void ind::AIBehaviour::move(ind::Actions direction)
{
    Actions &dir = direction;

    player.updateForce(ind::DirectionMap::keyDirections.at(dir), deltaTime, player.getSpeed());
    if (to2d(player.nextPos()) == to2d(player.getAnimator().getPosition()))
        dir = prevDir;
    if (player.getAction() != Actions::Walking) {
        player.getAnimator().setCurrentAnimation("walk").playAnimation();
        player.setAction(Actions::Walking);
    }
    player.setDirection(DirectionMap::keyDirections.at(dir));
    player.getAnimator().setAnimationsRotation(DirectionMap::directionAngles.at(DirectionMap::keyDirections.at(dir)));
    player.updateForce(DirectionMap::keyDirections.at(dir), deltaTime, player.getSpeed());
    player.draw();
    prevDir = dir;
}
