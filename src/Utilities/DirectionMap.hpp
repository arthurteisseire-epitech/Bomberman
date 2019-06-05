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
        static const std::map<ind::Actions, ind::ORIENTATION> keyDirections;
        static const std::map<ind::ORIENTATION, irr::core::vector3df> directionAngles;
    };
}

#endif
