/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <iostream>
#include <Animations/AnimatedMesh.hpp>
#include "Game.hpp"
#include "GraphicalBoard.hpp"
#include "Singleton.hpp"
#include "crossPlatform.hpp"
#include "KeyService.hpp"
#include "PlayerBehaviour.hpp"

ind::Game::Game() :
        deviceService(&SingleTon<DeviceService>::getInstance()),
        device(deviceService->getDevice()),
        driver(device->getVideoDriver()),
        manager(device->getSceneManager())
{
    manager->getVideoDriver()->getTexture("assets/powerup/bomb/bombbody_BaseColor.png"); //preLoading
}

void ind::Game::run()
{
    irr::f32 deltaTime;
    SceneManager sceneManager(LOADING);
    irr::u32 then = device->getTimer()->getTime();
    SceneType currentScene = LOADING;
    SceneType newScene;

    while (device->run() && currentScene != EXIT) {
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        deltaTime = updateDeltaTime(then);
        newScene = sceneManager.executeScene(deltaTime);
        if (newScene != currentScene)
            currentScene = changeScene(sceneManager, newScene);
        manager->drawAll();
        driver->endScene();
    }
//    device->drop();
}

irr::f32 ind::Game::updateDeltaTime(irr::u32 &then) const
{
    irr::f32 deltaTime;
    irr::u32 now;

    now = this->device->getTimer()->getTime();
    deltaTime = (irr::f32) (now - then) / 1000.f;
    then = now;
    return deltaTime;
}

ind::SceneType ind::Game::changeScene(ind::SceneManager &sceneManager, const ind::SceneType &newScene) const
{
    sceneManager.buildScene(newScene);
    return newScene;
}
