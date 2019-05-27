/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include "Position.hpp"
#include <irrlicht/irrlicht.h>

namespace ind {
    Position to2d(const irr::core::vector3df& pos3d);
}
