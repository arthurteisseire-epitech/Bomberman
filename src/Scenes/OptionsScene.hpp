/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_OPTIONSSCENE_HPP
#define BOMBERMAN_OPTIONSSCENE_HPP

#include <map>
#include <irrlicht/IGUIEnvironment.h>
#include <bits/unique_ptr.h>
#include "AScene.hpp"

namespace ind {
    class OptionsScene : public AScene {
    public:
        OptionsScene();
        ~OptionsScene() override;
        SceneType execute(irr::f32 deltaTime) final;
        SceneType type() final;

    private:
        irr::gui::IGUIEnvironment *gui;
        irr::gui::IGUIButton *returnButton;
        irr::gui::IGUIButton *playerMaxBombsPlaced;
        irr::gui::IGUIButton *bombsPlacedUp;
        irr::gui::IGUIButton *bombsPlacedDown;
        irr::video::ITexture *background;
        irr::gui::IGUIButton *bombsPlacedNumber;
        std::map<irr::gui::IGUIButton *, std::unique_ptr<irr::core::dimension2d<irr::core::dimension2df>>> buttonsPlace;

        void initButtons(const irr::core::dimension2d<irr::s32> &size);
        irr::gui::IGUIButton *initButton(const irr::core::dimension2df &center, const irr::core::dimension2df &size,
                                         const irr::core::dimension2di &screenDimension, const char *path);
        void resizeButtons(const irr::core::dimension2d<irr::u32> &currSize) const;
        void draw(const irr::core::dimension2d<irr::u32> &size) const;
        irr::core::rect<irr::s32> findPosition(const irr::u32 &x, const irr::u32 &y, irr::gui::IGUIButton *button) const;
        void incrementBombsInit();
        void decrementBombsInit();
    };
}

#endif