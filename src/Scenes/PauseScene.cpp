/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <irrlicht/IGUISkin.h>
#include <irrlicht/IVideoDriver.h>
#include "PlaceRectangle.hpp"
#include "PauseScene.hpp"
#include "Path.hpp"

ind::PauseScene::PauseScene() :
        AScene(),
        gui(_manager->getGUIEnvironment())
{
    irr::video::IVideoDriver *driver = gui->getVideoDriver();
    const irr::core::dimension2d<irr::u32> size = driver->getScreenSize();

    initButtons({(const irr::s32) size.Width, (const irr::s32) size.Height});
    background = driver->getTexture(Path::realpath("assets/bomb_background.png").c_str());
    gui->getSkin()->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255, 180, 180, 180));
}

void ind::PauseScene::initButtons(const irr::core::dimension2d<irr::s32> &size)
{
    returnButton = initButton({1.0f / 2, 1.0f / 4}, {1.0f / 10, 1.0f / 20}, size, "assets/return.png", nullptr);
    menuButton = initButton({1.0f / 2, 3.0f / 4}, {1.0f / 10, 1.0f / 20}, size, "assets/settings/menu.png", nullptr);
}

irr::gui::IGUIButton *ind::PauseScene::initButton(const irr::core::dimension2df &center,
                                                    const irr::core::dimension2df &size,
                                                    const irr::core::dimension2di &screenDimension, const char *path,
                                                    void (ind::PauseScene::*function)())
{
    irr::gui::IGUIButton *button = gui->addButton(ind::PlaceRectangle::getRectangle(
            {(int) (center.Width * screenDimension.Width), (int) (center.Height * screenDimension.Height)},
            {(int) (size.Width * screenDimension.Width), (int) (size.Height * screenDimension.Height)}));

    button->setImage(gui->getVideoDriver()->getTexture(Path::realpath(path).c_str()));
    button->setDrawBorder(false);
    buttonsPlace.emplace(button, ButtonPosition(center, size));
    if (function)
        buttonsFunction[button] = function;
    return button;
}

ind::SceneType ind::PauseScene::execute(irr::f32)
{
    static irr::core::dimension2d<irr::u32> size = gui->getVideoDriver()->getScreenSize();
    const irr::core::dimension2d<irr::u32> currSize = gui->getVideoDriver()->getScreenSize();

    if (currSize != size) {
        resizeButtons(currSize);
        size = currSize;
    }
    if (returnButton->isPressed())
        return LOADED_SCENE;
    if (menuButton->isPressed()) {
        return MAIN_MENU;
    }
    for (const auto &pair : buttonsFunction)
        if (pair.first->isPressed())
            (this->*pair.second)();
    draw(size);
    return PAUSE;
}

void ind::PauseScene::resizeButtons(const irr::core::dimension2d<irr::u32> &currSize) const
{
    const irr::u32 &x = currSize.Width;
    const irr::u32 &y = currSize.Height;

    for (const auto &buttonPair : buttonsPlace)
        buttonPair.first->setRelativePosition(findPosition(x, y, buttonPair.first));
}

irr::core::rect<irr::s32> ind::PauseScene::findPosition(const irr::u32 &x, const irr::u32 &y,
                                                          irr::gui::IGUIButton *button) const
{
    const ButtonPosition &buttonPlace = buttonsPlace.at(button);

    return ind::PlaceRectangle::getRectangle(
            {(int) (x * buttonPlace.center.Width), (int) (y * buttonPlace.center.Height)},
            {(int) (x * buttonPlace.size.Width), (int) (y * buttonPlace.size.Height)});
}

void ind::PauseScene::draw(const irr::core::dimension2d<irr::u32> &size) const
{
    gui->getVideoDriver()->draw2DImage(background,
                                       irr::core::position2d<irr::s32>(0, 0),
                                       irr::core::rect<irr::s32>(0, 0, 1920, 1080),
                                       new irr::core::rect<irr::s32>(0, 0, size.Width, size.Height));

    gui->drawAll();
}

ind::SceneType ind::PauseScene::type()
{
    return PAUSE;
}

ind::PauseScene::~PauseScene()
{
    menuButton->remove();
    returnButton->remove();
}