/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Created by abel,
*/

#include "Indie.hpp"

ind::Indie::Indie()
{
    this->device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(1920, 10880));
}
