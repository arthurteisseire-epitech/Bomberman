/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_PLAYERSSETTINGSSAVE_HPP
#define BOMBERMAN_PLAYERSSETTINGSSAVE_HPP

#include <map>
#include <memory>

namespace ind {
    struct PlayerSettings {
        PlayerSettings(unsigned short bombRange, unsigned short maxBombsPlaced, float speed);

        short unsigned bombPower;
        short unsigned maxBombsPlaced;
        float speed;
    };

    class PlayersSettingsSave {
    public:
        explicit PlayersSettingsSave(unsigned short playerID, unsigned short bombRange, unsigned short maxBombsPlaced,
                                     float speed);

        PlayerSettings &operator[](short playerID);
        static PlayerSettings &defaultSettings();
        static void addPlayer();
        static void removePlayer();
        static short unsigned getPlayerNumber();
        static short unsigned getMaxPlayers();
        static unsigned short getAINumber();
        static void removeAI();
        static void addAI();
    private:
        static std::map<short, PlayerSettings> settingsMap;
        static short unsigned playerNumber;
        static const short unsigned maxPlayers = 2;
        static unsigned short aiNumber;
    };
}

#endif
