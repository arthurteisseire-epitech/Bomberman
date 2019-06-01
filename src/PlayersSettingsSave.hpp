/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_PLAYERSSETTINGSSAVE_HPP
#define BOMBERMAN_PLAYERSSETTINGSSAVE_HPP

#include <map>
#include <bits/unique_ptr.h>

namespace ind {
    struct PlayerSettings {
        PlayerSettings(short bombRange, short maxBombsPlaced, float speed);

        short bombPower;
        short maxBombsPlaced;
        float speed;
    };

    class PlayersSettingsSave {
    public:
        explicit PlayersSettingsSave(short playerID, short bombRange, short maxBombsPlaced, float speed);

        PlayerSettings &operator[](short playerID);
        static PlayerSettings &defaultSettings();
    private:
        static std::map<short, PlayerSettings> settingsMap;
    };
}

#endif
