/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** DeadScene.hpp
*/

#ifndef BOMBERMAN_DEADSCENE_HPP
#define BOMBERMAN_DEADSCENE_HPP

#include "AScene.hpp"

namespace ind {
    class DeadScene : public AScene {
    public:
        DeadScene();
        ~DeadScene() override;
        SceneType execute(irr::f32 deltaTime) override;
        SceneType type() override;

        void initButtons();
        irr::gui::IGUIButton *initButton(const irr::core::rect<irr::s32> &rect, const char *string);
        void draw();
    private:
        irr::gui::IGUIEnvironment *gui;
        irr::video::ITexture *background;
        irr::gui::IGUIButton *button;
    };
}

#endif
