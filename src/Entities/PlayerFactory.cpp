/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** PlayerFactory.cpp
*/

#include "LoadingService.hpp"
#include "AIBehaviour.hpp"
#include "PlayerBehaviour.hpp"
#include "PlayerFactory.hpp"
#include "Singleton.hpp"
#include "DeviceService.hpp"
#include "Player.hpp"

ind::Player *ind::PlayerFactory::create(ind::PlayerNumber playerNumber, const ind::Position &position, ind::Board &map)
{
    auto animator = initAnimator(playerNumber);
    auto player = new Player(position, map, animator);

    if (playerNumber == PLAYER_ONE || playerNumber == PLAYER_TWO)
        player->setBehaviour(new PlayerBehaviour(*player, playerNumber));
    else
        player->setBehaviour(new AIBehaviour(*player, map));
    return player;
}

ind::animations::Animator *ind::PlayerFactory::initAnimator(const ind::PlayerNumber &playerNumber)
{
    ind::animations::Animator *animator = nullptr;

    if (playerNumber == PLAYER_ONE)
        animator = SingleTon<LoadingService>::getInstance().getAnimator("playerAAnimator");
    else if (playerNumber == PLAYER_TWO)
        animator = SingleTon<LoadingService>::getInstance().getAnimator("playerBAnimator");
    else if (playerNumber == AI1)
        animator = SingleTon<LoadingService>::getInstance().getAnimator("playerCAnimator");
    else if (playerNumber == AI2)
        animator = SingleTon<LoadingService>::getInstance().getAnimator("playerDAnimator");
    else if (playerNumber == AI3)
        animator = SingleTon<LoadingService>::getInstance().getAnimator("playerBAnimator");
    else if (playerNumber == AI4)
        animator = SingleTon<LoadingService>::getInstance().getAnimator("playerAAnimator");

    if (animator == nullptr)
        return nullptr;

    animator->setCurrentAnimation("walk")
        .setCurrentAnimationSpeed(50)
        .setAnimationsScale({1.1, 1.1, 1.1})
        .setCurrentAnimation("idle")
        .playAnimation();
    return animator;
}
