/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BoardObjectFactory.cpp
*/

#include "BoardObjectFactory.hpp"
#include "Bomb.hpp"
#include "BlockBreakable.hpp"
#include "Wall.hpp"
#include "BombUp.hpp"
#include "FireUp.hpp"
#include "SpeedUp.hpp"
#include "WallPass.hpp"

const ind::BoardObjectFactory::BoardObjectMap ind::BoardObjectFactory::boardObjectMap = {
    {BOMB_NAME,           [](const Position &pos, Board &board) { return new Bomb(pos, board); }},
    {BLOCKBREAKABLE_NAME, [](const Position &pos, Board &) { return new BlockBreakable(pos); }},
    {WALL_NAME,           [](const Position &pos, Board &) { return new Wall(pos); }},
    {BOMBUP_NAME,         [](const Position &pos, Board &) { return new BombUp(pos); }},
    {FIREUP_NAME,         [](const Position &pos, Board &) { return new FireUp(pos); }},
    {SPEEDUP_NAME,        [](const Position &pos, Board &) { return new SpeedUp(pos); }},
    {WALLPASS_NAME,       [](const Position &pos, Board &) { return new WallPass(pos); }},
};

ind::BoardObject *ind::BoardObjectFactory::create(const std::string &type, const ind::Position &pos, ind::Board &board)
{
    return boardObjectMap.at(type)(pos, board);
}
