/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <utility>
#include "AScene.hpp"
#include "DeviceService.hpp"
#include "Singleton.hpp"

ind::AScene::AScene() :
    _progPath(SingleTon<std::string>::getInstance()),
    _manager(SingleTon<DeviceService>::getInstance().getSceneManager())
{
}

std::ostream& operator<<(std::ostream& out, const ind::SceneType type)
{
    std::string s;
    switch(type) {
        case ind::MAIN_MENU:
            s = "MAIN_MENU"; break;
        case ind::GAME:
            s = "GAME"; break;
        case ind::OPTIONS:
            s = "OPTIONS"; break;
        case ind::EXIT:
            s = "EXIT"; break;
        default:
            s = "UNKNOWN_TYPE";
    }
    return out << std::string(s);
}