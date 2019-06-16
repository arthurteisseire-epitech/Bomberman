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
    enum PowerType {
        SPEEDUP,
        BOMBUP,
        WALLPASS,
        FIREUP
    };

    class Player;

    class PowerUp : public BoardObject {
    public:
        PowerUp(Position position, const std::string &path);
        ~PowerUp() override;
        virtual void upgrade(Player &player) = 0;
        virtual PowerType getType() const = 0;
        Tile getTile() const override;
        irr::scene::ISceneNode *getSceneNode() const;
    private:
        irr::scene::IParticleSystemSceneNode *auraParticle = nullptr;
    };
}
