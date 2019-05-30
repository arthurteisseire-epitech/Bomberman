/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BoardBehaviour.cpp
*/

#include <iostream>
#include "BoardBehaviour.hpp"

ind::BoardBehaviour::BoardBehaviour(ind::Board &board) :
    board(board)
{
}

void ind::BoardBehaviour::update(float)
{
    board.removeDeadObjects();
}
