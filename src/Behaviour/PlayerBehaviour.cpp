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

    if (playerNumber == PLAYER_ONE) {
        if (keyService.isKeyPressed(playerOneKeys[PlaceBomb]))
            player.placeBomb();
        if (keyService.isKeyPressed(playerOneKeys[Up]))
            player.move(NORTH, deltaTime, player.getSpeed());
        if (keyService.isKeyPressed(playerOneKeys[Down]))
            player.move(SOUTH, deltaTime, player.getSpeed());
        if (keyService.isKeyPressed(playerOneKeys[Left]))
            player.move(WEST, deltaTime, player.getSpeed());
        if (keyService.isKeyPressed(playerOneKeys[Right]))
            player.move(EAST, deltaTime, player.getSpeed());
    }
    if (playerNumber == PLAYER_TWO) {
        if (keyService.isKeyPressed(playerTwoKeys[PlaceBomb]))
            player.placeBomb();
        if (keyService.isKeyPressed(playerTwoKeys[Up]))
            player.move(NORTH, deltaTime, player.getSpeed());
        if (keyService.isKeyPressed(playerTwoKeys[Down]))
            player.move(SOUTH, deltaTime, player.getSpeed());
        if (keyService.isKeyPressed(playerTwoKeys[Left]))
            player.move(WEST, deltaTime, player.getSpeed());
        if (keyService.isKeyPressed(playerTwoKeys[Right]))
            player.move(EAST, deltaTime, player.getSpeed());
    }
    this->player.getAnimator().update();
    player.draw();
}
