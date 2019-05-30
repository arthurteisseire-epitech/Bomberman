/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_PLAYERSSETTINGS_HPP
#define BOMBERMAN_PLAYERSSETTINGS_HPP

#include <map>

namespace ind {
    struct PlayerSetting {
        PlayerSetting(short maxBombs, short bombRange, short maxBombsPlaced, float speed);
        short _maxBombs;
        short _bombRange;
        short _maxBombsPlaced;
        float _speed;
    };

    class PlayersSettings {
    public:
        explicit PlayersSettings(short playerID = 0, short maxBombs = 10, short bombRange = 5, short maxBombsPlaced = 1,
                                float speed = 30.0f);

        void changeSettings(short playerID = 0, short maxBombs = 10, short bombRange = 5, short maxBombsPlaced = 1,
                                 float speed = 30.0f);
        static PlayerSetting getSettings(short playerID = 0);
    private:
        static std::map<short, PlayerSetting> _settingsMap;
    };
}

#endif
