/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <stdlib.h>
#include <irrlicht/irrlicht.h>
#include <cstdlib>
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

ind::Board::Board(Position size_) :
        size(size_)
{
    initGround();
    initBlocks();
    initWall();
    cleanCorners();

    std::unique_ptr<Player> player(PlayerFactory::create(PLAYER_ONE, Position(0, 0), *this));
    std::unique_ptr<Player> player2(PlayerFactory::create(PLAYER_TWO, Position(size.x - 1, size.y - 1), *this));
    std::unique_ptr<Player> ai(PlayerFactory::create(AI, Position(0, size.y - 1), *this));

    players.emplace_back(std::move(player));
    players.emplace_back(std::move(player2));
    players.emplace_back(std::move(ai));
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

void ind::Board::printMap() const
{
    for (auto &it : map) {
        for (const auto &it2: it) {
            if (it2->getTile() != EMPTY)
                std::cout << "o";
            else
                std::cout << "x";
        }
        std::cout << std::endl;
    }
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
    auto *powerUp = new BombUp(position, "assets/bombUp.png");
    this->map[position.x][position.y] = std::shared_ptr<PowerUp>(powerUp);
}

ind::PowerUp *ind::Board::getPowerUp(const ind::Position &position)
{
    auto *ptr = dynamic_cast<PowerUp *>(this->map[position.x][position.y].get());
    return ptr;
}

irr::scene::IMeshSceneNode *ind::Board::initializePlayerCube() const
{
    auto manager = SingleTon<DeviceService>::getInstance().getSceneManager();
    auto cube = manager->addCubeSceneNode(TILE_SIZE, nullptr, -1);

    cube->setPosition(irr::core::vector3df(0, 0, 0));
    cube->setMaterialTexture(0, manager->getVideoDriver()->getTexture("assets/creeper.jpg"));
    return cube;
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
