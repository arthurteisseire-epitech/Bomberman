/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Keys.cpp
*/

#include "Keys.hpp"

const std::map<ind::Actions, irr::EKEY_CODE> ind::Keys::playerOne = {
    {PlaceBomb, irr::KEY_KEY_M},
    {Up,        irr::KEY_UP},
    {Left,      irr::KEY_LEFT},
    {Right,     irr::KEY_RIGHT},
    {Down,      irr::KEY_DOWN},
};

const std::map<ind::Actions, irr::EKEY_CODE> ind::Keys::playerTwo = {
    {PlaceBomb, irr::KEY_KEY_1},
    {Up,        irr::KEY_KEY_Z},
    {Left,      irr::KEY_KEY_Q},
    {Right,     irr::KEY_KEY_D},
    {Down,      irr::KEY_KEY_S},
};
