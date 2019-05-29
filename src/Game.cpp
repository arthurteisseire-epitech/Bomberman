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
#include "Player.hpp"
#include "SceneManager.hpp"

ind::Game::Game() :
    deviceService(&SingleTon<DeviceService>::getInstance()),
    device(deviceService->getDevice()),
    driver(device->getVideoDriver()),
    manager(device->getSceneManager())
{
}

void ind::Game::run()
{
    irr::u32 now;
    irr::f32 deltaTime;
    SceneManager sceneManager(MAIN_MENU);
    SceneType currentScene = MAIN_MENU;
    SceneType newScene;

    manager->addLightSceneNode(nullptr, irr::core::vector3df(90, 200, 70), irr::video::SColorf(1.0f, 1.0f, 1.0f), 10000.0f);

//    startMenu();

//    manager->addCameraSceneNode(nullptr, irr::core::vector3df(-20, 200, 70), irr::core::vector3df(60, 0, 70));
    irr::u32 then = device->getTimer()->getTime();

//    manager->getActiveCamera()->setFOV(0.7);

    while (device->run() && currentScene != END) {
        now = device->getTimer()->getTime();
        deltaTime = (irr::f32)(now - then) / 1000.f;
        then = now;

        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

        /*        for (auto &it : players) {
            it->update(deltaTime);
            it->draw();
        }*/
        newScene = sceneManager.executeScene(deltaTime);
        if (newScene != currentScene) {
            sceneManager.buildScene(newScene);
            std::cout << "building new scene: " << newScene << std::endl;
            currentScene = newScene;
        }
        manager->drawAll();
        driver->endScene();
    }
//    device->drop();
}

void ind::Game::startMenu() const
{
    // recuperation GUI et police
    irr::gui::IGUIEnvironment *gui = manager->getGUIEnvironment();
    irr::gui::IGUIFont *font = gui->getFont("fontlucida.png");
    irr::gui::IGUIButton *startButton = gui->addButton(
            irr::core::rect<irr::s32>(500, 380, 800, 520),  // position du bouton
            nullptr, -1, L"Start Game");              // texte
    startButton->setOverrideFont(font);                  // changement de police
    while (this->device->run())                          // boucle de rendu
    {
        this->driver->beginScene(true, true, irr::video::SColor(150, 150, 255, 255));
        if (startButton->isPressed())
            break;
        manager->drawAll();
        gui->drawAll();
        this->driver->endScene();
    }
}
