/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include "PlaceRectangle.hpp"

irr::core::rect<irr::s32>
ind::PlaceRectangle::getRectangle(irr::core::dimension2d<irr::s32> center, irr::core::dimension2d<irr::s32> size)
{
    return {center.Width - size.Width, center.Height - size.Height, center.Width + size.Width, center.Height + size.Height};
}
