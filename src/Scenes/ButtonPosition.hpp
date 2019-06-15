/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_BUTTONPOSITION_HPP
#define BOMBERMAN_BUTTONPOSITION_HPP

#include <irrlicht/dimension2d.h>

namespace ind {
    struct ButtonPosition {
        ButtonPosition(irr::core::dimension2df center_, irr::core::dimension2df size);

        irr::core::dimension2df center;
        irr::core::dimension2df size;
    };
}
#endif //BOMBERMAN_BUTTONPOSITION_HPP
