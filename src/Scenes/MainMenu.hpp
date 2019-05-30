/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_MAINMENU_HPP
#define BOMBERMAN_MAINMENU_HPP

#include <irrlicht/ISceneManager.h>
#include <irrlicht/IrrlichtDevice.h>
#include <irrlicht/IGUIButton.h>
#include "AScene.hpp"

namespace ind {
    class MainMenu : public AScene {
    public:
        MainMenu();
        SceneType execute(irr::f32 deltaTime) final;
        SceneType type() final;

    private:
        irr::gui::IGUIEnvironment *_gui;
        irr::gui::IGUIButton *_startButton;
    };
}

#endif
