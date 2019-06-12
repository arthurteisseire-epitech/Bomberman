/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Taz
*/

#include "LoadingScene.hpp"
#include "Services/LoadingService.hpp"
#include "Services/Singleton.hpp"
#include <thread>
#include <Services/DeviceService.hpp>
#include <iostream>
#include <Services/KeyService.hpp>
#include "Path.hpp"

extern std::atomic_bool _finish;

ind::LoadingScene::LoadingScene() : _loadingService(SingleTon<LoadingService>::getInstance())
{
    std::vector<ind::LoadAnimationData> playerAAnimations = {
        {
            .id = "walk",
            .folderPath = Path::realpath("assets/PlayerA/walking"),
            .texture = Path::realpath("assets/PlayerA/MAW_diffuse.png")
        },
        {
            .id = "idle",
            .folderPath = Path::realpath("assets/PlayerA/idle"),
            .texture = Path::realpath("assets/PlayerA/MAW_diffuse.png")
        }
    };

    std::vector<ind::LoadAnimationData> playerBAnimations = {
        {
            .id = "walk",
            .folderPath = Path::realpath("assets/PlayerB/walking"),
            .texture = Path::realpath("assets/PlayerB/Mutant_diffuse.png")
        },
        {
            .id = "idle",
            .folderPath = Path::realpath("assets/PlayerB/idle"),
            .texture = Path::realpath("assets/PlayerB/Mutant_diffuse.png")
        }
    };

    this->_loadingService.enqueueAnimator("playerAAnimator", playerAAnimations)
                         .enqueueAnimator("playerBAnimator", playerBAnimations)
                         .enqueueAnimator("playerCAnimator", playerBAnimations);

    this->_loadingService.startLoad();
}

ind::SceneType ind::LoadingScene::execute(irr::f32 deltatime)
{
    // Override game main loop
    while (_finish != true) {
        SingleTon<DeviceService>::getInstance().getDevice()->getVideoDriver()->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
        SingleTon<DeviceService>::getInstance().getSceneManager()->drawAll();
        SingleTon<DeviceService>::getInstance().getDevice()->getVideoDriver()->endScene();
    }
    return MAIN_MENU;
}

ind::SceneType ind::LoadingScene::type()
{
    return LOADING;
}
