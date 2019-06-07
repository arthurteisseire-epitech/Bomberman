/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** ExplosionManager.cpp
*/

#include "ExplosionManager.hpp"

void ind::ExplosionManager::addExplosion(const ind::Position &position)
{
    auto explosion = new Explosion(position);

    explosions.emplace_back(explosion);
    timeoutObjectManager.addObject(explosions.back(), explosion);
}

void ind::ExplosionManager::removeDeadExplosions()
{
    auto deadObjects = timeoutObjectManager.popDeadObjects();

    explosions.erase(
        std::remove_if(explosions.begin(), explosions.end(), [&](const std::shared_ptr<Explosion> &explosion) {
            return std::find(deadObjects.begin(), deadObjects.end(), explosion) != deadObjects.end();
        }), explosions.end());
}

void ind::ExplosionManager::update(float deltaTime)
{
    for (auto &explosion : explosions)
        explosion->update(deltaTime);
}

bool ind::ExplosionManager::isExplosionAt(const ind::Position &position) const
{
    auto it = std::find_if(explosions.begin(), explosions.end(), [&](const std::shared_ptr<Explosion> &explosion) {
        return explosion->getPosition() == position;
    });
    return it != explosions.end();
}

std::vector<ind::Position> ind::ExplosionManager::getAllExplosionsPositions() const
{
    std::vector<Position> positions;

    positions.reserve(explosions.size());
    for (auto &explosion : explosions)
        positions.push_back(explosion->getPosition());
    return positions;
}
