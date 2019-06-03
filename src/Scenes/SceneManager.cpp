/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <irrlicht/IrrlichtDevice.h>
#include <iostream>
#include "SceneManager.hpp"
#include "GameScene.hpp"
#include "MainMenu.hpp"
#include "OptionsScene.hpp"
#include "LoadingScene.hpp"

ind::SceneManager::SceneManager(SceneType sceneType)
{
    buildScene(sceneType);
}

ind::SceneType ind::SceneManager::executeScene(irr::f32 deltaTime) const
{
    return _currentScene->execute(deltaTime);
}

void ind::SceneManager::buildScene(ind::SceneType type)
{
    switch (type) {
        case MAIN_MENU:
            _currentScene = std::unique_ptr<MainMenu>(new MainMenu());
            break;
        case GAME:
            _currentScene = std::unique_ptr<GameScene>(new GameScene());
            break;
        case OPTIONS:
            _currentScene = std::unique_ptr<OptionsScene>(new OptionsScene());
            break;
        case LOADING:
            _currentScene = std::unique_ptr<LoadingScene>(new LoadingScene());
            break;
        default:
            return;
    }
}