/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "KeyService.hpp"

bool ind::KeyService::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        this->keyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return false;
}

bool ind::KeyService::isKeyPressed(irr::EKEY_CODE key) const
{
    return this->keyDown[key];
}

ind::KeyService::KeyService()
{
    for (bool & i : this->keyDown)
        i = false;
}
