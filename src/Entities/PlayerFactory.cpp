/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** PlayerFactory.cpp
*/

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
    auto animator = new ind::animations::Animator();
    auto manager = SingleTon<ind::DeviceService>::getInstance().getSceneManager();

    if (playerNumber == ind::PLAYER_ONE) {
        animator->registerAnimation("walk", "assets/PlayerA/walking", "assets/PlayerA/MAW_diffuse.png", *manager)
            .setCurrentAnimation("walk").setCurrentAnimationSpeed(50)
            .registerAnimation("idle", "assets/PlayerA/idle", "assets/PlayerA/MAW_diffuse.png", *manager)
            .setCurrentAnimation("idle")
            .setAnimationsScale({1.3, 1.3, 1.3})
            .playAnimation();
    } else {
        animator->registerAnimation("walk", "assets/PlayerB/walking", "assets/PlayerB/Mutant_diffuse.png", *manager)
            .setCurrentAnimation("walk").setCurrentAnimationSpeed(50)
            .registerAnimation("idle", "assets/PlayerB/idle", "assets/PlayerB/Mutant_diffuse.png", *manager)
            .setCurrentAnimation("idle")
            .setAnimationsScale({1.3, 1.3, 1.3})
            .playAnimation();
    }
    return animator;
}
