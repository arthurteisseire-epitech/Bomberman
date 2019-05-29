/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <iostream>
#include <crossPlatform.hpp>
#include "Player.hpp"
#include "Utilities/to2d.hpp"
#include "PlayerBehaviour.hpp"

ind::Player::Player(const Position &position, PlayerNumber playerNum, Board &map, irr::scene::IMeshSceneNode *object) :
    AbstractEntity(),
    boardPosition(0, 0),
    map(map),
    object(object)
{
    auto *behaviour = new PlayerBehaviour(*this, playerNum);
    setBehaviour(static_cast<IBehaviour *>(behaviour));
}

void ind::Player::placeBomb()
{
    std::string path = "assets";

    if (actualBombs < bombNumber) {
        auto *bomb = new Bomb(boardPosition, map, bombPower, [this](Bomb *bomb) {
            decreaseBombNumber(1);
            removeChild(bomb);
        });
        addChild(bomb);
        actualBombs += 1;
    }
}

void ind::Player::draw()
{
    if (force == irr::core::vector2df(0, 0))
        return;

    const irr::core::vector3df actualPosition = object->getPosition();
    const irr::core::vector3df futurePosition = correctMovement(actualPosition);
    Position futurePosition2d = to2d(futurePosition);

    object->setPosition(futurePosition);
    boardPosition = futurePosition2d;
    force.X = 0;
    force.Y = 0;
}

void ind::Player::decreaseBombNumber(short number)
{
    actualBombs -= number;
}

float ind::Player::getSpeed() const
{
    return movementSpeed;
}

irr::core::vector3df ind::Player::correctMovement(const irr::core::vector3df &actualPosition)
{
    const irr::core::vector3df horizontalNextPos = irr::core::vector3df(actualPosition.X, actualPosition.Y,
                                                                        actualPosition.Z - force.X);
    const irr::core::vector3df verticalNextPos = irr::core::vector3df(actualPosition.X - force.Y, actualPosition.Y,
                                                                      actualPosition.Z);
    const irr::core::vector3df nextPos = irr::core::vector3df(actualPosition.X - force.Y, actualPosition.Y,
                                                              actualPosition.Z - force.X);
    const bool horizontalWalkable = isWalkable(horizontalNextPos, {0, 0, force.X > 0 ? 1.0f : -1.0f});
    const bool verticalWalkable = isWalkable(verticalNextPos, {force.Y > 0 ? 1.0f : -1.0f, 0, 0});

    if (horizontalWalkable && verticalWalkable)
        return nextPos;
    if (horizontalWalkable)
        return horizontalNextPos;
    if (verticalWalkable)
        return verticalNextPos;
    return actualPosition;
}

const bool ind::Player::isWalkable(const irr::core::vector3df &pos, const irr::core::vector3df &direction)
{
    const irr::core::vector3df posBorder = pos - direction * (TILE_SIZE / 2);
    const irr::core::vector3df cornerOffset = (direction.X != 0 ? irr::core::vector3df(0, 0, TILE_SIZE / 2.3)
                                                                : irr::core::vector3df(TILE_SIZE / 2.3, 0, 0));
    const Position firstCorner = to2d(posBorder + cornerOffset);
    const Position secondCorner = to2d(posBorder - cornerOffset);
    const Position mapSize = map.getSize();

    if (pos.X + TILE_SIZE / 2 >= mapSize.x * TILE_SIZE - TILE_SIZE / 2 || pos.X < 0 ||
        pos.Z + TILE_SIZE / 2.0f >= mapSize.y * TILE_SIZE - TILE_SIZE / 2 || pos.Z < 0)
        return false;

    const Tile firstCornerTile = map.getInfoAtCoord(firstCorner);
    const Tile secondCornerTile = map.getInfoAtCoord(secondCorner);
    return (checkWalkableTile(firstCornerTile) && checkWalkableTile(secondCornerTile));
}

bool ind::Player::checkWalkableTile(const ind::Tile &Tile) const
{
    return Tile != BLOCKBREAKABLE && (Tile != BOMB || map.getInfoAtCoord(boardPosition) == BOMB);
}
