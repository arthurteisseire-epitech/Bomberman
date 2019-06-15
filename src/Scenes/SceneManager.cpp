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
#include "DeadScene.hpp"
#include "PauseScene.hpp"

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
            if (_savedGame) {
                dynamic_cast<GameScene *>(_savedGame.get())->resume();
                _currentScene = std::move(_savedGame);
            } else
                _currentScene = std::unique_ptr<GameScene>(new GameScene());
            break;
        case OPTIONS:
            _currentScene = std::unique_ptr<OptionsScene>(new OptionsScene());
            break;
        case LOADING:
            _currentScene = std::unique_ptr<LoadingScene>(new LoadingScene());
            break;
        case DEAD:
            _currentScene = std::unique_ptr<DeadScene>(new DeadScene());
            break;
        case PAUSE:
            dynamic_cast<GameScene *>(_currentScene.get())->pause();
            _savedGame = std::move(_currentScene);
            _currentScene = std::unique_ptr<PauseScene>(new PauseScene());
        default:
            return;
    }
}