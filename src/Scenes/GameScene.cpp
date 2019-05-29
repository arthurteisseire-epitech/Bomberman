/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include "GameScene.hpp"
#include "crossPlatform.hpp"
#include "Singleton.hpp"
#include "DeviceService.hpp"

ind::GameScene::GameScene() :
        AScene(),
        _map(Position(15, 15))
{
    initRootPath();
    irr::scene::IMeshSceneNode *cube = initializePlayerCube();
    auto *player = new Player(Position(0, 0), PLAYER_ONE, _map, cube);
    players.emplace_back(player);
    _manager->addCameraSceneNode(nullptr, irr::core::vector3df(-20, 200, 70), irr::core::vector3df(60, 0, 70));
    _manager->getActiveCamera()->setFOV(0.7);
    _manager->addLightSceneNode(nullptr, irr::core::vector3df(90, 200, 70), irr::video::SColorf(1.0f, 1.0f, 1.0f), 10000.0f);
}

void ind::GameScene::initRootPath()
{
    std::size_t last_slash = this->_progPath.find_last_of(DIRECTORYSEPARATOR);
    if (last_slash == std::string::npos) {
        this->_rootPath = ".";
        this->_rootPath += DIRECTORYSEPARATOR;
    } else {
        this->_rootPath = this->_progPath.substr(0, last_slash);
        this->_rootPath += DIRECTORYSEPARATOR;
    }
}

irr::scene::IMeshSceneNode *ind::GameScene::initializePlayerCube() const
{
    auto cube = SingleTon<ind::DeviceService>::getInstance().getSceneManager()->addCubeSceneNode(TILE_SIZE, nullptr, -1);

    cube->setPosition(irr::core::vector3df(0, 0, 0));
    cube->setMaterialTexture(0, this->_manager->getVideoDriver()->getTexture(
            (this->_rootPath + "assets" + DIRECTORYSEPARATOR + "creeper.jpg").c_str()));
    return cube;
}

ind::SceneType ind::GameScene::execute(irr::f32 deltaTime)
{
    for (auto &it : players) {
        it->update(deltaTime);
        it->draw();
    }
    return GAME;
}

ind::SceneType ind::GameScene::type()
{
    return GAME;
}
