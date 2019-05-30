/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include "PlayersSettings.hpp"

ind::PlayersSettings::PlayersSettings(short playerID, short maxBombs, short bombRange, short maxBombsPlaced,
                                      float speed)
{
    _settingsMap.emplace(playerID, PlayerSetting(maxBombs, bombRange, maxBombsPlaced, speed));
}

void ind::PlayersSettings::changeSettings(short playerID, short maxBombs, short bombRange, short maxBombsPlaced,
                                      float speed)
{
    _settingsMap[playerID] = PlayerSetting(maxBombs, bombRange, maxBombsPlaced, speed);
}

ind::PlayerSetting ind::PlayersSettings::getSettings(short playerID)
{
    return _settingsMap[playerID];
}

ind::PlayerSetting::PlayerSetting(short maxBombs, short bombRange, short maxBombsPlaced, float speed) :
        _maxBombs(maxBombs), _bombRange(bombRange), _maxBombsPlaced(maxBombsPlaced), _speed(speed)
{
}
