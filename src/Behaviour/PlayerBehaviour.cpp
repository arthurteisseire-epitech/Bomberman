/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "PlayerBehaviour.hpp"
#include "Singleton.hpp"
#include "KeyService.hpp"

ind::PlayerBehaviour::PlayerBehaviour(ind::Player &player,
    ind::PlayerNumber playerNumber
) : player(player), playerNumber(playerNumber)
{}

void ind::PlayerBehaviour::update(float deltaTime)
{
    this->player.checkDeath();
    std::vector<Actions> check = {Up, Down, Left, Right};
    KeyService &keyService = SingleTon<KeyService>::getInstance();

    if (this->wantToWalk(playerNumber == PLAYER_ONE)) {
        if (this->player.getAction() != Actions::Walking) {
            this->player.getAnimator()->setCurrentAnimation("walk")
                                      .playAnimation();
        }
        this->player.setAction(Actions::Walking);
    } else {
        if (this->player.getAction() != Actions::Idle) {
            this->player.getAnimator()->setCurrentAnimation("idle")
                                      .playAnimation();
        }
        this->player.setAction(Actions::Idle);
    }
    if (keyService.isKeyPressed(playerNumber == PLAYER_ONE ? playerOneKeys[PlaceBomb] : playerTwoKeys[PlaceBomb]))
        player.placeBomb();
    for (const auto &action : check) {
        if (keyService.isKeyPressed(playerNumber == PLAYER_ONE ? playerOneKeys[action] : playerTwoKeys[action])) {
            if (player.getDirection() != this->directionsMapping[action]) {
                player.setDirection(this->directionsMapping[action]);
                player.getAnimator()->setAnimationsRotation(this->directionAngles[this->directionsMapping[action]]);
            }
            player.move(this->directionsMapping[action], deltaTime, player.getSpeed());
            player.draw();
            return;
        }
    }
}

bool ind::PlayerBehaviour::wantToWalk(bool player1) const
{
    KeyService &keyService = SingleTon<KeyService>::getInstance();

    return keyService.isKeyPressed(player1 ? playerOneKeys.at(Up) : playerTwoKeys.at(Up)) ||
           keyService.isKeyPressed(player1 ? playerOneKeys.at(Down) : playerTwoKeys.at(Down)) ||
           keyService.isKeyPressed(player1 ? playerOneKeys.at(Left) : playerTwoKeys.at(Left)) ||
           keyService.isKeyPressed(player1 ? playerOneKeys.at(Right) : playerTwoKeys.at(Right));
}

