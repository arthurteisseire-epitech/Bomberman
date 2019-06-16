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

    initButtons(x, y);
    fillMapButtonScene();
    _background = driver->getTexture("./assets/bomb_background.png");
}

ind::MainMenu::~MainMenu()
{
    _startButton->remove();
    _exitButton->remove();
    _optionsButton->remove();
    _loadButton->remove();
}

void ind::MainMenu::initButtons(const irr::u32 &x, const irr::u32 &y)
{
    _startButton = initButton(ind::PlaceRectangle::getRectangle({(const irr::s32) x / 4, (const irr::s32) y / 2},
                                                                {(const irr::s32) x / 6, (const irr::s32) y / 14}),
                              "./assets/new_game.png");
    _optionsButton = initButton(ind::PlaceRectangle::getRectangle({(const irr::s32) x * 3 / 4, (const irr::s32) y / 2},
                                                                  {(const irr::s32) x / 6, (const irr::s32) y / 14}),
                                "./assets/options.png");
    _exitButton = initButton(ind::PlaceRectangle::getRectangle({(const irr::s32) x / 2, (const irr::s32) y * 3 / 4},
                                                               {(const irr::s32) x / 6, (const irr::s32) y / 14}),
                             "./assets/exit.png");
    _loadButton = initButton(ind::PlaceRectangle::getRectangle({(const irr::s32) x / 2, (const irr::s32) y / 3},
                                                               {(const irr::s32) x / 6, (const irr::s32) y / 14}),
                             "./assets/load.png");;
}

void ind::MainMenu::fillMapButtonScene()
{
    _buttonScene.emplace(_startButton, ind::GAME);
    _buttonScene.emplace(_loadButton, ind::GAME);
    _buttonScene.emplace(_optionsButton, ind::OPTIONS);
    _buttonScene.emplace(_exitButton, ind::EXIT);
}

irr::gui::IGUIButton *ind::MainMenu::initButton(const irr::core::rect<irr::s32> &rect, const char *string)
{
    irr::gui::IGUIButton *button = _gui->addButton(rect);

    button->setImage(_gui->getVideoDriver()->getTexture(string));
    button->setDrawBorder(false);
    return button;
}

ind::SceneType ind::MainMenu::execute(irr::f32 deltaTime)
{
    static irr::core::dimension2d<irr::u32> size = _gui->getVideoDriver()->getScreenSize();
    irr::core::dimension2d<irr::u32> currSize = _gui->getVideoDriver()->getScreenSize();

    if (currSize != size) {
        resizeButtons(currSize);
        size = currSize;
    }
    for (auto &buttonAssocScene : _buttonScene)
        if (buttonAssocScene.first->isPressed())
            return buttonAssocScene.second;
    draw(size);
    return MAIN_MENU;
}

void ind::MainMenu::draw(const irr::core::dimension2d<irr::u32> &size) const
{
    this->_gui->getVideoDriver()->draw2DImage(this->_background,
                                              irr::core::position2d<irr::s32>(0, 0),
                                              irr::core::rect<irr::s32>(0, 0, 1920, 1080),
                                              new irr::core::rect<irr::s32>(0, 0, size.Width, size.Height));

    this->_gui->drawAll();
}

void ind::MainMenu::resizeButtons(const irr::core::dimension2d<irr::u32> &currSize) const
{
    const irr::u32 &x = currSize.Width;
    const irr::u32 &y = currSize.Height;

    _startButton->setRelativePosition(
            ind::PlaceRectangle::getRectangle({(const irr::s32) x / 5, (const irr::s32) y / 2},
                                              {(const irr::s32) x / 6, (const irr::s32) y / 14}));
    _optionsButton->setRelativePosition(
            ind::PlaceRectangle::getRectangle({(const irr::s32) x * 4 / 5, (const irr::s32) y / 2},
                                              {(const irr::s32) x / 6, (const irr::s32) y / 14}));
    _exitButton->setRelativePosition(
            ind::PlaceRectangle::getRectangle({(const irr::s32) x / 2, (const irr::s32) y * 4 / 5},
                                              {(const irr::s32) x / 6, (const irr::s32) y / 14}));
    _loadButton->setRelativePosition(
            ind::PlaceRectangle::getRectangle({(const irr::s32) x / 2, (const irr::s32) y / 3},
                                              {(const irr::s32) x / 6, (const irr::s32) y / 14}));
}

ind::SceneType ind::MainMenu::type()
{
    return MAIN_MENU;
}
