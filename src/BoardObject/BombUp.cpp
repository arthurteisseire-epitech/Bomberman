/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Player.hpp"
#include "BombUp.hpp"

ind::BombUp::BombUp(ind::Position position)
    : PowerUp(position, "assets/powerup/bomb/bombbody_BaseColor.png")
{
    node = manager->addMeshSceneNode(manager->getMesh("assets/powerup/bomb/models/bomb2.obj"));
    node->setMaterialTexture(0, texture);
    node->setPosition(irr::core::vector3df(position.x * TILE_SIZE, 2.0f, position.y * TILE_SIZE));
    node->setScale(irr::core::vector3df(10.0f, 10.0f, 10.0f));
}

void ind::BombUp::upgrade(Player &player)
{
    player.setBombNumber(player.getBombNumber() + 1);
}
