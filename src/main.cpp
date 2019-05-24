/*
** EPITECH PROJECT, 2019
** Hello_World
** File description:
** Created by abel,
*/

#include <iostream>
#include <irrlicht/irrlicht.h>
#include <string>
#include <stdlib.h>
#include "Game.hpp"
#include "Board.hpp"
#include "Singleton.hpp"

using namespace irr;

using namespace core;
using namespace video;
using namespace scene;
using namespace gui;

int main(int, char **av)
{
    srand(time(NULL));
    try {
        irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL);
        if (device == NULL)
            exit(1);
        ind::Game game(av[0], device);
        game.run();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
