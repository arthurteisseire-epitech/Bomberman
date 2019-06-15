/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_PAUSESCENE_HPP
#define BOMBERMAN_PAUSESCENE_HPP

#include <irrlicht/IGUIEnvironment.h>
#include <irrlicht/IGUIButton.h>
#include <map>
#include "ButtonPosition.hpp"
#include "AScene.hpp"

namespace ind {
    class PauseScene : public AScene {
    public:
        PauseScene();
        ~PauseScene() final;

        SceneType execute(irr::f32 deltaTime) final;
        SceneType type() final;

    private:
        irr::gui::IGUIEnvironment *gui;
        irr::video::ITexture *background;
        std::map<irr::gui::IGUIButton *, ButtonPosition> buttonsPlace;
        std::map<irr::gui::IGUIButton *, void (ind::PauseScene::*)(void)> buttonsFunction;
        irr::gui::IGUIButton *returnButton;
        irr::gui::IGUIButton *saveButtion;
        irr::gui::IGUIButton *menuButton;

        void initButtons(const irr::core::dimension2d<irr::s32> &size);
        irr::gui::IGUIButton *initButton(const irr::core::dimension2df &center,
                                                          const irr::core::dimension2df &size,
                                                          const irr::core::dimension2di &screenDimension, const char *path,
                                                          void (ind::PauseScene::*function)());
        void resizeButtons(const irr::core::dimension2d<irr::u32> &currSize) const;
        irr::core::rect<irr::s32> findPosition(const irr::u32 &x, const irr::u32 &y, irr::gui::IGUIButton *button) const;
        void draw(const irr::core::dimension2d<irr::u32> &size) const;
    };
}


#endif