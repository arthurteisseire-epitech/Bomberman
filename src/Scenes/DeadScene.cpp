/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** DeadScene.cpp
*/

#include <irrlicht/irrlicht.h>
#include <iostream>
#include "PlaceRectangle.hpp"
#include "DeadScene.hpp"
#include "Path.hpp"

ind::DeadScene::DeadScene() :
    button(nullptr),
    gui(_manager->getGUIEnvironment())
{
    background = gui->getVideoDriver()->getTexture(Path::realpath("assets/bomb_background.png").c_str());
    initButtons();
}

ind::DeadScene::~DeadScene()
{
    button->remove();
}

ind::SceneType ind::DeadScene::execute(irr::f32)
{
    draw();
    return type();
}

ind::SceneType ind::DeadScene::type()
{
    if (button->isPressed())
        return MAIN_MENU;
    return DEAD;
}

void ind::DeadScene::draw()
{
    const irr::core::dimension2d<irr::u32> size = gui->getVideoDriver()->getScreenSize();

    gui->getVideoDriver()->draw2DImage(background,
                                       irr::core::position2d<irr::s32>(0, 0),
                                       irr::core::rect<irr::s32>(0, 0, 1920, 1080),
                                       new irr::core::rect<irr::s32>(0, 0, size.Width, size.Height));

    gui->drawAll();
}

void ind::DeadScene::initButtons()
{
    const irr::core::dimension2d<irr::u32> &size = gui->getVideoDriver()->getScreenSize();
    const irr::u32 &x = size.Width;
    const irr::u32 &y = size.Height;

    button = initButton(ind::PlaceRectangle::getRectangle({(const irr::s32)x / 2, (const irr::s32)y / 2},
                                                          {(const irr::s32)x / 2, (const irr::s32)y / 2}),
                        "./assets/return.png");
}

irr::gui::IGUIButton *ind::DeadScene::initButton(const irr::core::rect<irr::s32> &rect, const char *string)
{
    irr::gui::IGUIButton *b = gui->addButton(rect);

    b->setImage(gui->getVideoDriver()->getTexture(Path::realpath(string).c_str()));
    b->setDrawBorder(false);
    return b;
}
