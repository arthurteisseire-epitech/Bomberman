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
        PlayerSettings(short maxBombs, short bombRange, short maxBombsPlaced, float speed, short initBombs);

        short maxBombs;
        short bombRange;
        short maxBombsPlaced;
        short initBombs;
        float speed;
    };

    class PlayersSettingsSave {
    public:
        explicit PlayersSettingsSave(short playerID, short maxBombs, short bombRange, short maxBombsPlaced,
                                 float speed, short initBombs);

        PlayerSettings &operator[](short playerID);
        static PlayerSettings &defaultSettings();
    private:
        static std::map<short, PlayerSettings> settingsMap;
    };
}

#endif
