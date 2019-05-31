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
    KeyService &keyService = SingleTon<KeyService>::getInstance();

    if (this->playerNumber == PLAYER_ONE) {
        if (keyService.isKeyPressed(this->playerOneKeys[PlaceBomb]))
            this->player.placeBomb();
        if (keyService.isKeyPressed(this->playerOneKeys[Up])) {
            std::cout << "salut1" << std::endl;
            this->player.getAnimator().setCurrentAnimation("idle")
                                      .playAnimation();
            this->player.move(NORTH, deltaTime, this->player.getSpeed());
        }
        if (keyService.isKeyPressed(this->playerOneKeys[Down]))
            this->player.move(SOUTH, deltaTime, this->player.getSpeed());
        if (keyService.isKeyPressed(this->playerOneKeys[Left])) {
            this->player.getAnimator().setCurrentAnimation("walk")
                                      .playAnimation();
            this->player.move(WEST, deltaTime, this->player.getSpeed());
        }
        if (keyService.isKeyPressed(this->playerOneKeys[Right]))
            this->player.move(EAST, deltaTime, this->player.getSpeed());
    }
    if (this->playerNumber == PLAYER_TWO) {
        if (keyService.isKeyPressed(this->playerTwoKeys[PlaceBomb]))
            this->player.placeBomb();
        if (keyService.isKeyPressed(this->playerTwoKeys[Up]))
            this->player.move(NORTH, deltaTime, this->player.getSpeed());
        if (keyService.isKeyPressed(this->playerTwoKeys[Down]))
            this->player.move(SOUTH, deltaTime, this->player.getSpeed());
        if (keyService.isKeyPressed(this->playerTwoKeys[Left]))
            this->player.move(WEST, deltaTime, this->player.getSpeed());
        if (keyService.isKeyPressed(this->playerTwoKeys[Right]))
            this->player.move(EAST, deltaTime, this->player.getSpeed());
    }

    this->player.getAnimator().update();
}
