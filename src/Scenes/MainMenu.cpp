/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <irrlicht/IGUIEnvironment.h>
#include <irrlicht/IGUIButton.h>
#include <iostream>
#include "MainMenu.hpp"

ind::MainMenu::MainMenu() :
        AScene(),
        _gui(_manager->getGUIEnvironment())
{
    irr::video::IVideoDriver *driver = _gui->getVideoDriver();
    irr::core::dimension2d<irr::u32> size = _gui->getVideoDriver()->getScreenSize();
    irr::u32 xCorner = size.Width / 3;
    irr::u32 yCorner = size.Height / 8;

    _startButton = _gui->addButton(irr::core::rect<irr::s32>(xCorner, yCorner, 2 * xCorner, 2 * yCorner));
    _optionsButton = _gui->addButton(irr::core::rect<irr::s32>(xCorner, 3 * yCorner, 2 * xCorner, 4 * yCorner));
    _exitButton = _gui->addButton(irr::core::rect<irr::s32>(xCorner, 5 * yCorner, 2 * xCorner, 6 * yCorner));
    _background = driver->getTexture("./assets/bomb_background.png");

    irr::video::ITexture *startButtonImage = driver->getTexture("./assets/play_button.png");
    irr::video::ITexture *optionsImage = driver->getTexture("./assets/options_buttons.png");
    irr::video::ITexture *exitImage = driver->getTexture("./assets/exit.png");

    _startButton->setImage(startButtonImage);
    _exitButton->setImage(exitImage);
    _optionsButton->setImage(optionsImage);
}

ind::SceneType ind::MainMenu::execute(__attribute__((unused)) irr::f32 deltaTime)
{
    irr::core::dimension2d<irr::u32> size = _gui->getVideoDriver()->getScreenSize();
    if (_startButton->isPressed())
        return GAME;
    if (_exitButton->isPressed())
        return END;
    _gui->getVideoDriver()->draw2DImage(_background,
                        irr::core::position2d<irr::s32>(0, 0),
                        irr::core::rect<irr::s32>(0,0, 1920, 1080),
                        new irr::core::rect<irr::s32>(0, 0, size.Width, size.Height));

    _gui->drawAll();
    return MAIN_MENU;
}

ind::SceneType ind::MainMenu::type()
{
    return MAIN_MENU;
}
