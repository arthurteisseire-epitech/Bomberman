/*
** EPITECH PROJECT, 2019
** Hello_World
** File description:
** Created by abel,
*/

#include <irrlicht/irrlicht.h>
#include "crossPlatform.hpp"

int main(int ac, char **argv)
{
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_SOFTWARE,
        irr::core::dimension2d<irr::u32 >(640, 480), 16, false, false, false, nullptr);
    if (!device)
        return 84;
    device->setWindowCaption(L"Hello World");
    while (device->run())
    {}
    return 0;
}