/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <irrlicht/IGUIEnvironment.h>
#include <irrlicht/IGUIButton.h>
#include "MainMenu.hpp"

ind::MainMenu::MainMenu() :
        AScene(),
        _gui(_manager->getGUIEnvironment())
{
    irr::gui::IGUIFont *font = _gui->getFont("fontlucida.png");

    _startButton = _gui->addButton(
            irr::core::rect<irr::s32>(500, 380, 800, 520),  // position du bouton
            nullptr, -1, L"Start Game");              // texte
    _startButton->setOverrideFont(font);                  // changement de police
}

ind::SceneType ind::MainMenu::execute(__attribute__((unused)) irr::f32 deltaTime)
{
    if (_startButton->isPressed())
        return GAME;
    _gui->drawAll();
    return MAIN_MENU;
}

ind::SceneType ind::MainMenu::type()
{
    return MAIN_MENU;
}
