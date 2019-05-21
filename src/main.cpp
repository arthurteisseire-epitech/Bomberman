/*
** EPITECH PROJECT, 2019
** Hello_World
** File description:
** Created by abel,
*/

#include <iostream>
#include <irrlicht/irrlicht.h>
#include "Game.hpp"

using namespace irr;

using namespace core;
using namespace video;
using namespace scene;
using namespace gui;

int main(int, char **av)
{
    try {
        ind::Game game(av[0]);
        game.run();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
