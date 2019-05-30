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
#include "PlaceRectangle.hpp"

ind::MainMenu::MainMenu() :
        AScene(),
        _gui(_manager->getGUIEnvironment())
{
    irr::video::IVideoDriver *driver = _gui->getVideoDriver();
    const irr::core::dimension2d<irr::u32> &size = _gui->getVideoDriver()->getScreenSize();
    const irr::u32 &x = size.Width;
    const irr::u32 &y = size.Height;

    _startButton = initButton(PlaceRectangle::getRectangle({x / 3, y / 2}, {x / 6, y / 14}), "./assets/play_button.png");
    _optionsButton = initButton(PlaceRectangle::getRectangle({x * 2 / 3, y / 2}, {x / 6, y / 14}), "./assets/options_buttons.png");
    _exitButton = initButton(PlaceRectangle::getRectangle({x / 2, y * 2 / 3}, {x / 6, y / 14}), "./assets/exit.png");
    _background = driver->getTexture("./assets/bomb_background.png");
}

irr::gui::IGUIButton *ind::MainMenu::initButton(const irr::core::rect<irr::s32> &rect, const char *string)
{
    irr::gui::IGUIButton *button = _gui->addButton(rect);
    button->setImage(_gui->getVideoDriver()->getTexture(string));
    button->setDrawBorder(false);
    return button;
}

ind::SceneType ind::MainMenu::execute(__attribute__((unused)) irr::f32 deltaTime)
{
    const irr::core::dimension2d<irr::u32> &size = _gui->getVideoDriver()->getScreenSize();
    const irr::u32 &x = size.Width;
    const irr::u32 &y = size.Height;

    _startButton->setRelativePosition(PlaceRectangle::getRectangle({x / 5, y / 2}, {x / 6, y / 14}));
    _optionsButton->setRelativePosition(PlaceRectangle::getRectangle({x * 4 / 5, y / 2}, {x / 6, y / 14}));
    _exitButton->setRelativePosition(PlaceRectangle::getRectangle({x / 2, y * 4 / 5}, {x / 6, y / 14}));
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
