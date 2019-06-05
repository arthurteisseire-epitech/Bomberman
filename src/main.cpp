/*
** EPITECH PROJECT, 2019
** Hello_World
** File description:
** Created by abel,
*/

#include <irrlicht/irrlicht.h>
#include <string>
#include <stdlib.h>
#include "Game.hpp"
#include "Board.hpp"
#include "Singleton.hpp"
#include "FullPath.hpp"

using namespace irr;

using namespace core;
using namespace video;
using namespace scene;
using namespace gui;

int main(int, char **av)
{
    srand(time(nullptr));
    try {
        ind::FullPath::changePath(av[0]);
        ind::Game game;
        game.run();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
