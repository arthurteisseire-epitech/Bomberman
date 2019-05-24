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

ind::Game::Game(char *exec) : map(std::pair<int, int>(15,15))
{
    std::string ex = exec;
    std::size_t last_slash = ex.find_last_of(DIRECTORYSEPARATOR);
    if (last_slash == std::string::npos) {
        this->rootPath = ".";
        this->rootPath += DIRECTORYSEPARATOR;
    } else {
        this->rootPath = ex.substr(0, last_slash);
        this->rootPath += DIRECTORYSEPARATOR;
    }
    this->device = irr::createDevice(irr::video::EDT_OPENGL);
    if (!this->device)
        throw std::runtime_error("Can't create device");
    this->environment = this->device->getGUIEnvironment();
    this->driver = this->device->getVideoDriver();
    this->manager = this->device->getSceneManager();
    this->device->setEventReceiver(&(SingleTon<KeyService>::getInstance()));
    this->device->setWindowCaption(L"Bomberman");
    auto cube = this->manager->addCubeSceneNode(10.0f, nullptr, -1);
    cube->setPosition(irr::core::vector3df(70, 0, 70));
    cube->setMaterialTexture(0, this->driver->getTexture((this->rootPath + "assets" + DIRECTORYSEPARATOR + "creeper.jpg").c_str()));
    auto *player = new Player(Position(0, 0), SOUTH, PLAYER_ONE, this->map, cube);
    this->players.emplace_back(player);
}

void ind::Game::run()
{
    GraphicalBoard board(Size(15, 13));

    board.create([this]() {
        auto cube = manager->addCubeSceneNode(10.0f, nullptr, -1);
        cube->setMaterialTexture(0, this->driver->getTexture((this->rootPath + "assets" + DIRECTORYSEPARATOR + "wood.png").c_str()));
        cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        return cube;
    });
    manager->addLightSceneNode(0, irr::core::vector3df(90, 200, 70), irr::video::SColorf(1.0f, 1.0f, 1.0f), 10000.0f);
    manager->addCameraSceneNode(nullptr, irr::core::vector3df(90, 200, 70), irr::core::vector3df(90, 0, 70));
    irr::u32 then = device->getTimer()->getTime();


    /*
    std::string path = "/home/Taz/Desktop/obj_indie/";

    ind::animations::AnimatedMesh bite(*manager, path);
    auto var = manager->addAnimatedMeshSceneNode(&bite, nullptr, -1);
    */


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
    device->drop();
}
