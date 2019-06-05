/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "PlayerBehaviour.hpp"
#include "Singleton.hpp"
#include "KeyService.hpp"

ind::PlayerBehaviour::PlayerBehaviour(ind::Player &player, ind::PlayerNumber playerNumber) :
    player(player),
    playerKeys(playerNumber == PLAYER_ONE ? playerOneKeys : playerTwoKeys)
{}

void ind::PlayerBehaviour::update(float deltaTime)
{
    KeyService &keyService = SingleTon<KeyService>::getInstance();

    player.checkDeath();
    if (wantToWalk()) {
        if (player.getAction() != Actions::Walking) {
            player.getAnimator().setCurrentAnimation("walk").playAnimation();
            player.setAction(Actions::Walking);
        }
    } else {
        if (player.getAction() != Actions::Idle) {
            player.getAnimator().setCurrentAnimation("idle").playAnimation();
            player.setAction(Actions::Idle);
        }
    }
    if (keyService.isKeyPressed(playerKeys[PlaceBomb]))
        player.placeBomb();
    move(deltaTime);
}

void ind::PlayerBehaviour::move(float deltaTime) const
{
    KeyService &keyService = SingleTon<KeyService>::getInstance();

    for (const auto &action : {Up, Down, Left, Right}) {
        if (keyService.isKeyPressed(playerKeys[action])) {
            if (player.getDirection() != directionsMapping.at(action)) {
                player.setDirection(directionsMapping.at(action));
                player.getAnimator().setAnimationsRotation(
                    directionAngles.at(directionsMapping.at(action)));
            }
            player.move(directionsMapping.at(action), deltaTime, player.getSpeed());
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