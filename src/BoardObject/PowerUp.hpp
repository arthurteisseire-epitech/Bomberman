/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <functional>
#include "BoardObject.hpp"

namespace ind {
    class Player;
    class PowerUp : public BoardObject {
        public:
            PowerUp(Position position, const irr::io::path &path);
            ~PowerUp() override;
            virtual void upgrade(Player &player) = 0;
            Tile getTile() const override;
            irr::scene::ISceneNode *getSceneNode() const;
        private:
            irr::scene::IParticleSystemSceneNode *auraParticle = nullptr;
    };
}
