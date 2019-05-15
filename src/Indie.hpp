/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Created by abel,
*/

#pragma once

#include <irrlicht/irrlicht.h>

namespace ind {

    class Indie {
        public:
            Indie();
            ~Indie() = default;

        private:
            irr::IrrlichtDevice *device;
    };
}
