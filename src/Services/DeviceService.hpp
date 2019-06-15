/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** DeviceService.hpp
*/

#ifndef BOMBERMAN_DEVICESERVICE_HPP
#define BOMBERMAN_DEVICESERVICE_HPP

#include <irrlicht/irrlicht.h>

namespace ind {
    class DeviceService {
    public:
        DeviceService();
        ~DeviceService();
        irr::scene::ISceneManager *getSceneManager() const;
        irr::IrrlichtDevice *getDevice() const;
    private:
        irr::IrrlichtDevice *device;
    };
}

#endif
