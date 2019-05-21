/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <string>

namespace ind {
    class Game {
        public:
        explicit Game(char *exec);

        ~Game() = default;

        void run();
    private:
        std::string rootPath;
        irr::IrrlichtDevice *device = nullptr;
        irr::gui::IGUIEnvironment *environment = nullptr;
        irr::scene::ISceneManager *manager = nullptr;
        irr::video::IVideoDriver *driver = nullptr;
    };
}
