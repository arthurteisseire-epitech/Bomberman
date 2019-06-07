/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "DirectionMap.hpp"
#include "Keys.hpp"
#include "PlayerBehaviour.hpp"
#include "Singleton.hpp"
#include "KeyService.hpp"

ind::PlayerBehaviour::PlayerBehaviour(ind::Player &player, ind::PlayerNumber playerNumber) :
    player(player),
    playerKeys(playerNumber == PLAYER_ONE ? Keys::playerOne : Keys::playerTwo)
{}

void ind::PlayerBehaviour::update(float deltaTime)
{
    KeyService &keyService = SingleTon<KeyService>::getInstance();

    player.checkDeath();
    updateAnimation();
    if (keyService.isKeyPressed(playerKeys.at(PlaceBomb)))
        player.placeBomb();
    move(deltaTime);
}

void ind::PlayerBehaviour::updateAnimation() const
{
    if (wantToWalk()) {
        if (player.getAction() != ind::Walking) {
            player.getAnimator().setCurrentAnimation("walk").playAnimation();
            player.setAction(ind::Walking);
        }
    } else {
        if (player.getAction() != ind::Idle) {
            player.getAnimator().setCurrentAnimation("idle").playAnimation();
            player.setAction(ind::Idle);
        }
    }
}

void ind::PlayerBehaviour::move(float deltaTime) const
{
    KeyService &keyService = SingleTon<KeyService>::getInstance();

    for (const auto &action : {Up, Down, Left, Right}) {
        if (keyService.isKeyPressed(playerKeys.at(action))) {
            if (player.getDirection() != DirectionMap::keyDirections.at(action)) {
                player.setDirection(DirectionMap::keyDirections.at(action));
                player.getAnimator().setAnimationsRotation(
                    DirectionMap::directionAngles.at(DirectionMap::keyDirections.at(action)));
            }
            player.updateForce(DirectionMap::keyDirections.at(action), deltaTime, player.getSpeed());
            player.draw();
            return;
        }
    }
}

bool ind::PlayerBehaviour::wantToWalk() const
{
    KeyService &keyService = SingleTon<KeyService>::getInstance();

    return keyService.isKeyPressed(playerKeys.at(Up)) ||
           keyService.isKeyPressed(playerKeys.at(Down)) ||
           keyService.isKeyPressed(playerKeys.at(Left)) ||
           keyService.isKeyPressed(playerKeys.at(Right));
}