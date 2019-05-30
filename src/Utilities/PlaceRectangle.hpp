/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_PLACERECTANGLE_HPP
#define BOMBERMAN_PLACERECTANGLE_HPP

#include <irrlicht/rect.h>

namespace ind {
    class PlaceRectangle {
    public:
        static irr::core::rect<irr::s32> getRectangle(irr::core::dimension2d<irr::s32> center,
                                                      irr::core::dimension2d<irr::s32> size);
    };
}

#endif
