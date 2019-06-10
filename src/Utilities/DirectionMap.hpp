/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** DirectionMap.hpp
*/

#ifndef BOMBERMAN_DIRECTIONMAP_HPP
#define BOMBERMAN_DIRECTIONMAP_HPP

#include <map>
#include "Player.hpp"

namespace ind {
    class DirectionMap {
    public:
        static const std::map<ind::Actions, ind::Orientation> keyDirections;
        static const std::map<ind::Orientation, irr::core::vector3df> directionAngles;
    };
}

#endif
