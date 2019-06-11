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
    state(FIND_BLOCKBREACKABLE),
    prevDir(NORTH),
    deltaTime(0)
{
    alterStateMap = {
        {DODGE,                [this]() { alterDodge(); }},
        {MOVE_TO_PLAYER,       [this]() { alterMoveToPlayer(); }},
        {FIND_BLOCKBREACKABLE, [this]() { alterFindBlockBreakable(); }},
        {PLACE_BOMB,           [this]() { alterPlaceBomb(); }},
    };

    actionStateMap = {
        {DODGE,                [this]() { actionDodge(); }},
        {MOVE_TO_PLAYER,       [this]() { actionMoveToPlayer(); }},
        {FIND_BLOCKBREACKABLE, [this]() { actionFindBlockBreakable(); }},
        {PLACE_BOMB,           [this]() { actionPlaceBomb(); }},
    };
}

void ind::AIBehaviour::update(float dt)
{
    deltaTime = dt;
    player.checkDeath();

    if (!AIUtils::contain(board.getAllExplosionsPositions(),
                          AIUtils::getPositionsAroundWalkable(board, player.getPosition()))) {
        action();
    } else {
        stopWalking();
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
    auto positionsWithoutExplosions = AIUtils::getPositionsAroundWithoutExplosion(board, player.getPosition());
    auto positionsWalkable = AIUtils::getPositionsAroundWalkable(board, player.getPosition());

    if (positionsWalkable.size() == positionsWithoutExplosions.size())
        state = FIND_BLOCKBREACKABLE;
}

void ind::AIBehaviour::alterMoveToPlayer()
{
    if (AIUtils::isOnFutureExplosion(board, player.getPosition()))
        state = DODGE;
}

void ind::AIBehaviour::alterFindBlockBreakable()
{
    if (AIUtils::isBlockBreakableAround(board, player.getPosition()))
        state = PLACE_BOMB;
}

void ind::AIBehaviour::alterPlaceBomb()
{
    if (AIUtils::isOnFutureExplosion(board, player.getPosition()))
        state = DODGE;
}

void ind::AIBehaviour::actionDodge()
{
    auto positions = AIUtils::getPositionsAroundWithoutExplosion(board, player.getPosition());

    if (!positions.empty()) {
        auto posToTarget = SingleTon<PathfindingService>::getInstance().searchPath(board, player.getPosition(),
                                                                                   positions.at(0));
        if (!AIUtils::isOnFutureExplosion(board, player.getPosition())) {
            stopWalking();
            return;
        }
        if (posToTarget.size() > 1)
            move(AIUtils::posToDir(player.getPosition(), posToTarget.at(1)));
    } else {
        std::cout << "no available pos around: i'm dead" << std::endl;
    }
}

void ind::AIBehaviour::actionMoveToPlayer()
{
    const Position &targetPos = board.getPlayers()[0]->getPosition();
    auto posToTarget = SingleTon<PathfindingService>::getInstance().searchPath(board, player.getPosition(), targetPos);

    if (posToTarget.size() > 2)
        move(AIUtils::posToDir(player.getPosition(), posToTarget.at(1)));
}

void ind::AIBehaviour::actionFindBlockBreakable()
{
    auto positions = AIUtils::findBlockBreakable(board, player.getPosition());

    if (!positions.empty())
        move(AIUtils::posToDir(player.getPosition(), positions.at(0)));
}

void ind::AIBehaviour::actionPlaceBomb()
{
    player.placeBomb();
}

void ind::AIBehaviour::move(Orientation dir)
{
    player.updateForce(dir, deltaTime, player.getSpeed());
    if (to2d(player.nextPos()) == to2d(player.getAnimator().getPosition()) && !isTurnAround(dir))
        dir = prevDir;
    if (player.getAction() != Actions::Walking) {
        player.getAnimator().setCurrentAnimation("walk").playAnimation();
        player.setAction(Actions::Walking);
    }
    player.setDirection(dir);
    player.getAnimator().setAnimationsRotation(DirectionMap::directionAngles.at(dir));
    player.updateForce(dir, deltaTime, player.getSpeed());
    player.draw();
    prevDir = dir;
}

void ind::AIBehaviour::stopWalking()
{
    if (player.getAction() == ind::Walking) {
        player.getAnimator().setCurrentAnimation("idle").playAnimation();
        player.setAction(ind::Down);
    }
}

bool ind::AIBehaviour::isTurnAround(ind::Orientation orientation)
{
    return (prevDir == NORTH && orientation == SOUTH) ||
           (prevDir == SOUTH && orientation == NORTH) ||
           (prevDir == WEST && orientation == EAST) ||
           (prevDir == EAST && orientation == WEST);
}
