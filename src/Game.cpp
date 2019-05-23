/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <iostream>
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
}

void ind::Game::run()
{
    GraphicalBoard board(Size(15, 13));

    board.create([this]() {
        auto cube = manager->addCubeSceneNode(10.0f, nullptr, -1);
        cube->setMaterialTexture(0, this->driver->getTexture((this->rootPath + "assets" + DIRECTORYSEPARATOR + "tnt.jpg").c_str()));
        cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        return cube;
    });
    manager->addLightSceneNode(0, irr::core::vector3df(90, 200, 70), irr::video::SColorf(1.0f, 1.0f, 1.0f), 10000.0f);
    manager->addCameraSceneNode(nullptr, irr::core::vector3df(90, 200, 70), irr::core::vector3df(90, 0, 70));
    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        manager->drawAll();
        driver->endScene();
    }
    device->drop();
}
