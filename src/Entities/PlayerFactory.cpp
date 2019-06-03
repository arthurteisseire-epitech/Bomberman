/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** PlayerFactory.cpp
*/

#include <Services/LoadingService.hpp>
#include "PlayerBehaviour.hpp"
#include "PlayerFactory.hpp"
#include "Singleton.hpp"
#include "DeviceService.hpp"
#include "Player.hpp"

ind::Player *ind::PlayerFactory::create(ind::PlayerNumber playerNumber, const ind::Position &position, ind::Board &map)
{
    ind::animations::Animator *animator = initAnimator(playerNumber);
    auto player = new Player(position, map, animator);

    player->setBehaviour(new PlayerBehaviour(*player, playerNumber));
    return player;
}

ind::animations::Animator *ind::PlayerFactory::initAnimator(const ind::PlayerNumber &playerNumber)
{
    ind::animations::Animator *animator = nullptr;

    if (playerNumber == PLAYER_ONE)
        animator = SingleTon<LoadingService>::getInstance().getAnimator("playerAAnimator");
    else
        animator = SingleTon<LoadingService>::getInstance().getAnimator("playerBAnimator");

    if (animator == nullptr)
        return nullptr;

    animator->setCurrentAnimation("walk")
            .setCurrentAnimationSpeed(50)
            .setAnimationsScale({1.3, 1.3, 1.3})
            .setCurrentAnimation("idle")
            .playAnimation();
    return animator;
}
