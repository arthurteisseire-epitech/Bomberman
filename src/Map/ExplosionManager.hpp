/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** ExplosionManager.hpp
*/

#ifndef BOMBERMAN_EXPLOSIONMANAGER_HPP
#define BOMBERMAN_EXPLOSIONMANAGER_HPP

#include "TimeoutObjectManager.hpp"
#include "Explosion.hpp"

namespace ind {
    class ExplosionManager {
    public:
        ExplosionManager() = default;
        void update(float deltaTime);
        void addExplosion(const Position &position);
        void removeDeadExplosions();
    private:
        std::vector<std::shared_ptr<Explosion>> explosions;
        TimeoutObjectManager<Explosion> timeoutObjectManager;
    };
}

#endif
