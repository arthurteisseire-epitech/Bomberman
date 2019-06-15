/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <Animations/AnimatedMesh.hpp>
#include "GameScene.hpp"
#include "crossPlatform.hpp"
#include "Singleton.hpp"
#include "DeviceService.hpp"
#include "KeyService.hpp"

ind::GameScene::GameScene() :
        AScene(),
        _map(Position(15, 15))
{
    _manager->addCameraSceneNode(nullptr, irr::core::vector3df(-20, 200, 70), irr::core::vector3df(60, 0, 70));
    _manager->getActiveCamera()->setFOV(0.7);
    _manager->addLightSceneNode(nullptr, irr::core::vector3df(90, 200, 70), irr::video::SColorf(1.0f, 1.0f, 1.0f), 1000.0f);
}

ind::SceneType ind::GameScene::execute(irr::f32 deltaTime)
{
    _map.update(deltaTime);
    if (_map.getPlayers().size() == 1)
        return DEAD;
    if (SingleTon<KeyService>::getInstance().isKeyPressed(irr::KEY_ESCAPE))
        return MAIN_MENU;
    return GAME;
}

ind::SceneType ind::GameScene::type()
{
    return GAME;
}
