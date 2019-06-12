/*
** EPITECH PROJECT, 2019
** Hello_World
** File description:
** Created by abel,
*/

#include "Game.hpp"
#include "Path.hpp"

int main(int, char **av)
{
    srand(time(nullptr));
    try {
        ind::Path::changePath(av[0]);
        ind::Game game;
        game.run();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
