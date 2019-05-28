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

ind::Game::Game(char *exec, irr::IrrlichtDevice *device) : device(device), manager(device->getSceneManager()), map(Position(15,15), manager)
{
    std::string ex = exec;
    std::size_t last_slash = ex.find_last_of(DIRECTORYSEPARATOR);
    if (last_slash == std::string::npos) {
        rootPath = ".";
        rootPath += DIRECTORYSEPARATOR;
    } else {
        rootPath = ex.substr(0, last_slash);
        rootPath += DIRECTORYSEPARATOR;
    }
    driver = device->getVideoDriver();
    environment = device->getGUIEnvironment();
    device->setEventReceiver(&(SingleTon<KeyService>::getInstance()));
    device->setWindowCaption(L"Bomberman");
    auto cube = manager->addCubeSceneNode(TILE_SIZE, nullptr, -1);
    cube->setPosition(irr::core::vector3df(0, 0, 0));
    cube->setMaterialTexture(0, driver->getTexture((rootPath + "assets" + DIRECTORYSEPARATOR + "creeper.jpg").c_str()));
    auto *player = new Player(manager, Position(0, 0), PLAYER_ONE, map, cube);
    players.emplace_back(player);
}

void ind::Game::run()
{
/*    GraphicalBoard board(Size(15, 13));

    board.create([this]() {
        auto cube = manager->addCubeSceneNode(10.0f, nullptr, -1);
        cube->setMaterialTexture(0, driver->getTexture((rootPath + "assets" + DIRECTORYSEPARATOR + "wood.png").c_str()));
        cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        return cube;
    });*/

    startMenu();

    manager->addLightSceneNode(0, irr::core::vector3df(90, 200, 70), irr::video::SColorf(1.0f, 1.0f, 1.0f), 10000.0f);
    manager->addCameraSceneNode(nullptr, irr::core::vector3df(-20, 200, 70), irr::core::vector3df(60, 0, 70));
    irr::u32 then = device->getTimer()->getTime();

   // std::string path = "/home/Taz/Desktop/wolfanim/";
   // ind::animations::AnimatedMesh bite(*manager, path);

    //auto mob = manager->addAnimatedMeshSceneNode(&bite);
    //mob->setScale({10, 10, 10});
    //mob->setAnimationSpeed(24);
    //mob->setLoopMode(false);

    manager->getActiveCamera()->setFOV(0.7);

    while (device->run()) {
        const irr::u32 now = device->getTimer()->getTime();
        const irr::f32 deltaTime = (irr::f32)(now - then) / 1000.f;

        then = now;
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

        for (auto &it : players) {
            it->update(deltaTime);
            it->draw();
        }
        manager->drawAll();
        driver->endScene();
    }
    for (auto &it: players)
        it = nullptr;
    //device->drop();
}

void ind::Game::startMenu() const
{
    irr::scene::ISceneManager *sceneManager = this->device->getSceneManager();

    // recuperation GUI et police
    irr::gui::IGUIEnvironment *gui = sceneManager->getGUIEnvironment();
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
        sceneManager->drawAll();
        gui->drawAll();
        this->driver->endScene();
    }
}


