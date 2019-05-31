/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <irrlicht/IVideoDriver.h>
#include <irrlicht/IGUIButton.h>
#include "PlayersSettingsSave.hpp"
#include "OptionsScene.hpp"
#include "PlaceRectangle.hpp"

ind::OptionsScene::OptionsScene() :
        AScene(),
        gui(_manager->getGUIEnvironment())
{
    irr::video::IVideoDriver *driver = gui->getVideoDriver();
    const irr::core::dimension2d<irr::u32> size = gui->getVideoDriver()->getScreenSize();

    initButtons({size.Width, size.Height});
    background = driver->getTexture("./assets/bomb_background.png");
}

ind::OptionsScene::~OptionsScene()
{
    returnButton->remove();
    playerBombsAtStartButton->remove();
    bombInitDown->remove();
    bombInitUp->remove();
    bombInitNumber->remove();
}

void ind::OptionsScene::initButtons(const irr::core::dimension2d<irr::s32> &size)
{
    returnButton = initButton({1.0f / 2, 2.0f / 3}, {1.0f / 6, 1.0f / 14}, size, "./assets/return.png");
    playerBombsAtStartButton = initButton({1.0f / 4, 1.0f / 4}, {1.0f / 6, 1.0f / 14}, size, "./assets/settings/player_bombs.png");
    bombInitDown = initButton({3.0f / 5, 1.0f / 4}, {1.0f / 10, 1.0f / 20}, size, "./assets/settings/minus.png");
    bombInitNumber = initButton({3.5f / 5, 1.0f / 4}, {1.0f / 10, 1.0f / 20}, size, "./assets/settings/empty.png");

    std::string initBombStr = std::to_string(PlayersSettingsSave::defaultSettings().initBombs);
    bombInitNumber->setText(std::wstring(initBombStr.begin(), initBombStr.end()).c_str());
    bombInitUp = initButton({4.0f / 5, 1.0f / 4}, {1.0f / 10, 1.0f / 20}, size, "./assets/settings/plus.png");
}

irr::gui::IGUIButton *ind::OptionsScene::initButton(const irr::core::dimension2df &center,
                                                    const irr::core::dimension2df &size,
                                                    const irr::core::dimension2di &screenDimension, const char *path)
{
    irr::gui::IGUIButton *button = gui->addButton(ind::PlaceRectangle::getRectangle(
            {(int)(center.Width * screenDimension.Width), (int)(center.Height * screenDimension.Height)},
            {(int)(size.Width * screenDimension.Width), (int)(size.Height * screenDimension.Height)}));
    button->setImage(gui->getVideoDriver()->getTexture(path));
    button->setDrawBorder(false);
    buttonsPlace[button] = std::unique_ptr<irr::core::dimension2d<irr::core::dimension2df>>(
            new irr::core::dimension2d<irr::core::dimension2df>(center, size));
    return button;
}

ind::SceneType ind::OptionsScene::execute(__attribute__((unused)) irr::f32 deltaTime)
{
    static irr::core::dimension2d<irr::u32> size = gui->getVideoDriver()->getScreenSize();
    const irr::core::dimension2d<irr::u32> currSize = gui->getVideoDriver()->getScreenSize();

    if (currSize != size) {
        resizeButtons(currSize);
        size = currSize;
    }
    if (returnButton->isPressed())
        return MAIN_MENU;
    draw(size);
    return OPTIONS;
}

void ind::OptionsScene::draw(const irr::core::dimension2d<irr::u32> &size) const
{
    gui->getVideoDriver()->draw2DImage(background,
                                       irr::core::position2d<irr::s32>(0, 0),
                                       irr::core::rect<irr::s32>(0, 0, 1920, 1080),
                                       new irr::core::rect<irr::s32>(0, 0, size.Width, size.Height));

    gui->drawAll();
}

void ind::OptionsScene::resizeButtons(const irr::core::dimension2d<irr::u32> &currSize) const
{
    const irr::u32 &x = currSize.Width;
    const irr::u32 &y = currSize.Height;

    returnButton->setRelativePosition(findPosition(x, y, returnButton));
    playerBombsAtStartButton->setRelativePosition(findPosition(x, y, playerBombsAtStartButton));
    bombInitDown->setRelativePosition(findPosition(x, y, bombInitDown));
    bombInitUp->setRelativePosition(findPosition(x, y, bombInitUp));
}

#include <iostream>
irr::core::rect<irr::s32> ind::OptionsScene::findPosition(const irr::u32 &x, const irr::u32 &y,
                                                          irr::gui::IGUIButton *button) const
{
    const std::unique_ptr<irr::core::dimension2d<irr::core::dimension2df>> &buttonPlace = buttonsPlace.at(button);

    return ind::PlaceRectangle::getRectangle(
            {(int)(x * buttonPlace->Width.Width), (int)(y * buttonPlace->Width.Height)},
            {(int)(x * buttonPlace->Height.Width), (int)(y * buttonPlace->Height.Height)});
}

ind::SceneType ind::OptionsScene::type()
{
    return OPTIONS;
}