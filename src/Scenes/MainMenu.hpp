/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_MAINMENU_HPP
#define BOMBERMAN_MAINMENU_HPP

#include <map>
#include <irrlicht/ISceneManager.h>
#include <irrlicht/IrrlichtDevice.h>
#include <irrlicht/IGUIButton.h>
#include "AScene.hpp"

namespace ind {
    class MainMenu : public AScene {
    public:
        MainMenu();
        ~MainMenu() override;
        SceneType execute(irr::f32 deltaTime) final;
        SceneType type() final;

    private:
        irr::gui::IGUIEnvironment *_gui;
        irr::gui::IGUIButton *_startButton;
        irr::gui::IGUIButton *_optionsButton;
        irr::gui::IGUIButton *_exitButton;
        irr::video::ITexture *_background;
        std::map<irr::gui::IGUIButton *, SceneType> _buttonScene;

        void initButtons(const irr::u32 &x, const irr::u32 &y);
        irr::gui::IGUIButton *initButton(const irr::core::rect<irr::s32> &rect, const char *path);
        void fillMapButtonScene();
        void resizeButtons(const irr::core::dimension2d<irr::u32> &currSize) const;
        void draw(const irr::core::dimension2d<irr::u32> &size) const;
    };
}

#endif
