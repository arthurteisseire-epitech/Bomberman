/*
** EPITECH PROJECT, 2019
** Hello_World
** File description:
** Created by abel,
*/

#include <iostream>
#include "irrlicht.h"

int main(void)
{
    std::cout << "Hello World !" << std::endl;
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(1920, 1080), 16, false, false, false, 0);
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* smgr = device->getSceneManager();
    irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

    guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
        irr::core::rect<irr::s32>(10, 10, 260, 22), true);
    device->setWindowCaption(L"Bonjour");
    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
        guienv->drawAll();
        std::cout << "Running game" << std::endl;
        driver->endScene();
    }
    return 0;
}
