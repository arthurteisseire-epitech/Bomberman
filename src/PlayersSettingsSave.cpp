/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include "PlayersSettingsSave.hpp"

std::map<short, ind::PlayerSettings> ind::PlayersSettingsSave::settingsMap = {
        {0, ind::PlayerSettings(5, 1, 30.0f)}
};

short unsigned ind::PlayersSettingsSave::playerNumber = 1;

ind::PlayerSettings::PlayerSettings(unsigned short bombRange, unsigned short maxBombsPlaced, float speed)
        : bombPower(bombRange), maxBombsPlaced(maxBombsPlaced), speed(speed)
{
}

ind::PlayersSettingsSave::PlayersSettingsSave(unsigned short playerID, unsigned short bombRange,
                                              unsigned short maxBombsPlaced, float speed)
{
    settingsMap.emplace(playerID, PlayerSettings(bombRange, maxBombsPlaced, speed));
}

ind::PlayerSettings &ind::PlayersSettingsSave::operator[](short playerID)
{
    if (settingsMap.find(playerID) == settingsMap.end())
        settingsMap.emplace(playerID, PlayerSettings(0, 0, 0));
    return settingsMap.at(playerID);
}

ind::PlayerSettings &ind::PlayersSettingsSave::defaultSettings()
{
    return settingsMap.at(0);
}

void ind::PlayersSettingsSave::addPlayer()
{
    ++playerNumber;
}

void ind::PlayersSettingsSave::removePlayer()
{
    --playerNumber;
}

short unsigned ind::PlayersSettingsSave::getPlayerNumber()
{
    return playerNumber;
}

short unsigned ind::PlayersSettingsSave::getMaxPlayers()
{
    return maxPlayers;
}
