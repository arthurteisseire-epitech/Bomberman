/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <stdlib.h>
#include <irrlicht/irrlicht.h>
#include <cstdlib>
#include <fstream>
#include "WallPass.hpp"
#include "SpeedUp.hpp"
#include "FireUp.hpp"
#include "DeviceService.hpp"
#include "Bomb.hpp"
#include "BoardBehaviour.hpp"
#include "Explosion.hpp"
#include "BlockBreakable.hpp"
#include "Ground.hpp"
#include "BombUp.hpp"
#include "PowerUp.hpp"
#include "Board.hpp"
#include "Position.hpp"
#include "Player.hpp"
#include "Singleton.hpp"
#include "PlayerFactory.hpp"
#include "BoardObjectFactory.hpp"

ind::Board::Board(Position size_) :
    size(size_)
{
    initMap();
    initPlayers();
}

void ind::Board::initPlayers()
{
    std::ifstream fs("players.txt");

    if (fs.good()) {
        loadPlayers(fs);
    } else {
        ind::Position cornersPos[4] = {ind::Position(0, 0), ind::Position(this->size.x - 1, this->size.y - 1),
                                       ind::Position(this->size.x - 1, 0),
                                       ind::Position(0, this->size.y - 1)};
        ind::PlayerNumber pNbArr[4] = {ind::PLAYER_ONE, ind::PLAYER_TWO, ind::AI1, ind::AI2};
        const unsigned short pNb = ind::PlayersSettingsSave::getPlayerNumber();
        const unsigned short AINb = ind::PlayersSettingsSave::getAINumber();

        for (unsigned short pIdx = 0; pIdx < pNb; ++pIdx)
            this->players.emplace_back(ind::PlayerFactory::create(pNbArr[pIdx], cornersPos[pIdx], *this));
        for (unsigned short AIIdx = pNb; AIIdx < pNb + AINb; ++AIIdx)
            this->players.emplace_back(ind::PlayerFactory::create(pNbArr[AIIdx], cornersPos[AIIdx], *this));
    }
}

void ind::Board::initMap()
{
    std::ifstream fs("map.txt");

    initGround();
    if (fs.good()) {
        loadMap(fs);
    } else {
        initBlocks();
        initWall();
    }
    cleanCorners();
}

void ind::Board::initGround()
{
    ground.reserve(size.x);
    for (int i = 0; i < size.x; ++i) {
        ground.emplace_back();
        ground[i].reserve(size.y);
        for (int j = 0; j < size.y; ++j) {
            ground[i].emplace_back(new Ground(Position(i, j)));
        }
    }
}

void ind::Board::initBlocks()
{
    map.reserve(size.x);
    for (int i = 0; i < size.x; ++i) {
        map.emplace_back();
        map[i].reserve(size.y);
        for (int j = 0; j < size.y; ++j) {
            if ((rand() & 1) == 0)
                map[i].emplace_back(new BlockBreakable(Position(i, j)));
            else
                map[i].emplace_back(nullptr);
        }
    }
}

void ind::Board::initWall()
{
    for (int x = 0; x < size.x; ++x) {
        if (x % 2 == 1)
            for (int y = 0; y < size.y; ++y)
                if (y % 2 == 1)
                    map[x][y].reset(new Wall(Position(x, y)));
    }
}

void ind::Board::cleanCorners()
{
    emptyTile(map[0][0]);
    emptyTile(map[1][0]);
    emptyTile(map[0][1]);
    emptyTile(map[0][size.y - 1]);
    emptyTile(map[0][size.y - 2]);
    emptyTile(map[1][size.y - 1]);
    emptyTile(map[size.x - 1][size.y - 1]);
    emptyTile(map[size.x - 1][size.y - 2]);
    emptyTile(map[size.x - 2][size.y - 1]);
    emptyTile(map[size.x - 1][0]);
    emptyTile(map[size.x - 2][0]);
    emptyTile(map[size.x - 1][1]);
}

ind::Tile ind::Board::getInfoAtCoord(Position coord) const
{
    return getInfoAtCoord(coord.x, coord.y);
}

ind::Tile ind::Board::getInfoAtCoord(int x, int y) const
{
    auto &tile = map[x][y];

    if (tile == nullptr)
        return EMPTY;
    return tile->getTile();
}

ind::Position ind::Board::getSize() const
{
    return size;
}

void ind::Board::emptyTile(std::shared_ptr<BoardObject> &tile)
{
    tile = nullptr;
}

void ind::Board::emptyTile(ind::Position position)
{
    return emptyTile(map[position.x][position.y]);
}

void ind::Board::explodeTile(const ind::Position &position)
{
    explosionManager.addExplosion(position);
}

void ind::Board::placeBomb(const ind::Position &position, int power, const std::function<void(Bomb *)> &f)
{
    auto bomb = new Bomb(position, *this, power, f);

    map[position.x][position.y].reset(bomb);
    timeoutObjectManager.addObject(map[position.x][position.y], bomb);
}

void ind::Board::removeDeadObjects()
{
    auto deadObjects = timeoutObjectManager.popDeadObjects();
    for (auto &row : map)
        for (auto &tile : row)
            if (std::find(deadObjects.begin(), deadObjects.end(), tile) != deadObjects.end())
                tile = nullptr;
    explosionManager.removeDeadExplosions();
}

void ind::Board::putPowerUp(const ind::Position &position)
{
    PowerUp *powerUp = nullptr;
    auto r = rand() % 3;

    if (rand() % 50 == 0) {
        powerUp = new WallPass(position);
    } else {
        if (r == 0)
            powerUp = new SpeedUp(position);
        else if (r == 1)
            powerUp = new BombUp(position);
        else
            powerUp = new FireUp(position);
    }
    this->map[position.x][position.y] = std::shared_ptr<PowerUp>(powerUp);
}

ind::PowerUp *ind::Board::getPowerUp(const ind::Position &position)
{
    auto *ptr = dynamic_cast<PowerUp *>(this->map[position.x][position.y].get());
    return ptr;
}

void ind::Board::killDeadPlayers()
{
    players.erase(std::remove_if(players.begin(), players.end(), [](std::unique_ptr<Player> &player) {
        return !player->isAlive();
    }), players.end());
}

std::vector<std::unique_ptr<ind::Player>> &ind::Board::getPlayers()
{
    return this->players;
}

void ind::Board::update(float deltaTime)
{
    for (auto &row : map)
        for (auto &tile : row)
            if (tile)
                tile->update(deltaTime);
    for (auto &player : players)
        player->update(deltaTime);
    removeDeadObjects();
    killDeadPlayers();
    explosionManager.update(deltaTime);
}

bool ind::Board::isOnExplosion(const Position &position) const
{
    return explosionManager.isExplosionAt(position);
}

std::vector<ind::Bomb *> ind::Board::getAllBombs() const
{
    std::vector<Bomb *> bombs;

    for (auto &row : this->map)
        for (auto &tile : row)
            if (tile && tile->getTile() == BOMB)
                bombs.push_back(dynamic_cast<Bomb *>(tile.get()));
    return bombs;
}

bool ind::Board::in(const Position &pos) const
{
    return pos.x >= 0 && pos.x < size.x && pos.y >= 0 && pos.y < size.y;
}

std::vector<ind::Position> ind::Board::getAllExplosionsPositions() const
{
    return explosionManager.getAllExplosionsPositions();
}

bool ind::Board::isWalkable(const ind::Position &pos) const
{
    if (!in(pos))
        return false;

    const auto &type = getInfoAtCoord(pos.x, pos.y);
    return type != BLOCKBREAKABLE && type != WALL && type != BOMB;
}

void ind::Board::save()
{
    std::ofstream fs;
    std::ofstream playerFile;

    fs.open("map.txt");
    playerFile.open("players.txt");

    if (fs.good()) {
        for (const auto &row : map)
            saveRow(row, fs);
        fs.close();
    }
    if (playerFile.good()) {
        savePlayers(playerFile);
        fs.close();
    }
}

void ind::Board::saveRow(const std::vector<std::shared_ptr<ind::BoardObject>> &row, std::ofstream &fs)
{
    for (const auto &tile : row)
        if (tile)
            saveTile(tile, fs);
}

void ind::Board::saveTile(const std::shared_ptr<ind::BoardObject> &tile, std::ofstream &fs)
{
    if (tile->getTile() != BOMB)
        fs << tile->toString() << std::endl;
}

void ind::Board::savePlayers(std::ofstream &fs)
{
    for (const auto &player : players)
        fs << *player << std::endl;
}

void ind::Board::loadMap(std::ifstream &fs)
{
    map.reserve(size.x);
    for (int i = 0; i < size.x; ++i) {
        map.emplace_back();
        map[i].reserve(size.y);
        for (int j = 0; j < size.y; ++j)
            map[i].emplace_back(nullptr);
    }

    std::string line;
    while (std::getline(fs, line)) {
        try {
            initTileFromLine(line);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void ind::Board::initTileFromLine(std::string line)
{
    int x = std::stoi(line);
    line = line.substr(line.find(',') + 1);
    int y = std::stoi(line);
    line = line.substr(line.find(' ') + 1);

    if (x >= size.x || y >= size.y || x < 0 || y < 0)
        return;
    auto tile = BoardObjectFactory::create(line, Position(x, y), *this);
    map[x][y].reset(tile);
}

void ind::Board::loadPlayers(std::ifstream &fs)
{
    std::string line;
    while (std::getline(fs, line)) {
        try {
            initPlayerFromLine(line);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void ind::Board::initPlayerFromLine(std::string line)
{
    int x = std::stoi(line);
    line = line.substr(line.find(',') + 1);
    int y = std::stoi(line);
    line = line.substr(line.find(' ') + 1);
    auto n = static_cast<PlayerNumber>(std::stoi(line));

    if (x >= size.x || y >= size.y || x < 0 || y < 0)
        return;
    emptyTile(map[x][y]);
    players.emplace_back(PlayerFactory::create(n, Position(x, y), *this));
}
