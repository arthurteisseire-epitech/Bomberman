/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include "PlayersSettingsSave.hpp"

std::map<short, ind::PlayerSettings> ind::PlayersSettingsSave::settingsMap = {
        {0, ind::PlayerSettings(10, 5, 1, 30.0f, 10)}
};

ind::PlayerSettings::PlayerSettings(short maxBombs, short bombRange, short maxBombsPlaced, float speed, short initBombs)
        : maxBombs(maxBombs), bombRange(bombRange), maxBombsPlaced(maxBombsPlaced), initBombs(initBombs), speed(speed)
{
}

ind::PlayersSettingsSave::PlayersSettingsSave(short playerID, short maxBombs, short bombRange, short maxBombsPlaced,
                                      float speed, short initBombs)
{
    settingsMap.emplace(playerID, PlayerSettings(maxBombs, bombRange, maxBombsPlaced, speed, initBombs));
}

ind::PlayerSettings &ind::PlayersSettingsSave::operator[](short playerID)
{
    if (settingsMap.find(playerID) == settingsMap.end())
        settingsMap.emplace(playerID, PlayerSettings(0, 0, 0, 0, 0));
    return settingsMap.at(playerID);
}

ind::PlayerSettings &ind::PlayersSettingsSave::defaultSettings()
{
    return settingsMap.at(0);
}
