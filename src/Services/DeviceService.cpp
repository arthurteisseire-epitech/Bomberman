/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** DeviceService.cpp
*/

#include "DeviceService.hpp"
#include "KeyService.hpp"
#include "Singleton.hpp"

ind::DeviceService::DeviceService()
{
    device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2du(1920, 1080),16,false,true);
    if (device == nullptr)
        exit(84);
    device->setEventReceiver(&(SingleTon<KeyService>::getInstance()));
    device->setWindowCaption(L"Bomberman");
}

irr::scene::ISceneManager *ind::DeviceService::getSceneManager() const
{
    return device->getSceneManager();
}

irr::IrrlichtDevice *ind::DeviceService::getDevice() const
{
    return device;
}

ind::DeviceService::~DeviceService()
{
    device->drop();
}
