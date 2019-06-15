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
#include <memory>
#include "AScene.hpp"

namespace ind {
    struct ButtonPosition {
        ButtonPosition(irr::core::dimension2df center_, irr::core::dimension2df size_);

        irr::core::dimension2df center;
        irr::core::dimension2df size;
    };

    class OptionsScene : public AScene {
    public:
        OptionsScene();
        ~OptionsScene() override;
        SceneType execute(irr::f32 deltaTime) final;
        SceneType type() final;

    private:
        irr::gui::IGUIEnvironment *gui;
        irr::gui::IGUIButton *returnButton;
        irr::gui::IGUIButton *maxBombsPlacedButton;
        irr::gui::IGUIButton *bombsPlacedUp;
        irr::gui::IGUIButton *bombsPlacedDown;
        irr::gui::IGUIButton *speedButton;
        irr::gui::IGUIButton *speedDownButton;
        irr::gui::IGUIButton *speedUpButton;
        irr::gui::IGUIButton *speedNumberButton;
        irr::video::ITexture *background;
        irr::gui::IGUIButton *bombsPlacedNumber;
        irr::gui::IGUIButton *bombsPowerButton;
        irr::gui::IGUIButton *bombsPowerUpButton;
        irr::gui::IGUIButton *bombsPowerDownButton;
        irr::gui::IGUIButton *bombsPowerNumberButton;
        irr::gui::IGUIButton *playerNumberButton;
        irr::gui::IGUIButton *playerNumberValue;
        irr::gui::IGUIButton *playerNumberUp;
        irr::gui::IGUIButton *playerNumberDown;
        irr::gui::IGUIButton *AINumberButton;
        irr::gui::IGUIButton *AINumberDown;
        irr::gui::IGUIButton *AINumberUp;
        irr::gui::IGUIButton *AINumberValue;
        std::map<irr::gui::IGUIButton *, ButtonPosition> buttonsPlace;
        std::map<irr::gui::IGUIButton *, void (ind::OptionsScene::*)(void)> buttonsFunction;

        void initButtons(const irr::core::dimension2d<irr::s32> &size);
        irr::gui::IGUIButton *initButton(const irr::core::dimension2df &center, const irr::core::dimension2df &size,
                                         const irr::core::dimension2di &screenDimension, const char *path,
                                         void (ind::OptionsScene::*)());
        void initMaxBombsButtons(const irr::core::dimension2d<irr::s32> &size, const irr::core::dimension2df &signSize);
        void initSpeedButtons(const irr::core::dimension2d<irr::s32> &size, const irr::core::dimension2df &signSize);
        void initBombsPowerButtons(const irr::core::dimension2d<irr::s32> &size,
                                   const irr::core::dimension2df &signSize);
        void resizeButtons(const irr::core::dimension2d<irr::u32> &currSize) const;
        void draw(const irr::core::dimension2d<irr::u32> &size) const;
        irr::core::rect<irr::s32> findPosition(const irr::u32 &x, const irr::u32 &y, irr::gui::IGUIButton *button) const;
        void incrementMaxBombsPlaced();
        void decrementMaxBombsPlaced();
        void incrementSpeed();
        void decrementSpeed();
        void decrementBombsPower();
        void incrementBombsPower();
        void setTexts() const;
        void initPlayerNumber(const irr::core::dimension2d<irr::s32> &size, const irr::core::dimension2df &signSize);
        void incrementPlayerNumber();
        void decrementPlayerNumber();
        void initAINumber(const irr::core::dimension2d<irr::s32> &size, const irr::core::dimension2df &signSize);
        void decrementAINumber();
        void incrementAINumber();
    };
}

#endif
