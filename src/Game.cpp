/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <iostream>
#include "Game.hpp"
#include "Board.hpp"
#include "Singleton.hpp"
#include "crossPlatform.hpp"
#include "KeyService.hpp"

ind::Game::Game(char *exec)
{
    std::string ex = exec;
    std::size_t last_slash = ex.find_last_of('/');
    if (last_slash == std::string::npos) {
        this->rootPath = ".";
        this->rootPath += '/';
    } else {
        this->rootPath = ex.substr(0, last_slash);
        this->rootPath += '/';
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
    Board board(Size(15, 13));

    board.create([this]() {
        auto cube = manager->addCubeSceneNode(10.0f, nullptr, -1);
        cube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
        return cube;
    });
    manager->addCameraSceneNode(nullptr, irr::core::vector3df(120, 200, 120), irr::core::vector3df(0, 0, 0));
    while (device->run()) {
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        manager->drawAll();
        driver->endScene();
    }
    device->drop();
}
