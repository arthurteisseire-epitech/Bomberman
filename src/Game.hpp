/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <SFML/Audio.hpp>
#include <string>
#include "Board.hpp"
#include "Player.hpp"
#include "DeviceService.hpp"
#include "AScene.hpp"
#include "SceneManager.hpp"

namespace ind {
    class Game {
    public:
        explicit Game();
        ~Game() = default;

        void run();
        void startMusic();
    private:
        DeviceService *deviceService;
        irr::IrrlichtDevice *device;
        irr::video::IVideoDriver *driver;
        irr::scene::ISceneManager *manager;
        sf::Music music;

        SceneType changeScene(SceneManager &sceneManager, const SceneType &newScene) const;
        irr::f32 updateDeltaTime(irr::u32 &then) const;
    };
}
