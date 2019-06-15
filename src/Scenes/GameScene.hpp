/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_GAMESCENE_HPP
#define BOMBERMAN_GAMESCENE_HPP

#include <irrlicht/ISceneManager.h>
#include <string>
#include "AScene.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Animations/AnimatedMesh.hpp"

namespace ind {
    class GameScene : public AScene {
    public:
        explicit GameScene();
        SceneType execute(irr::f32 deltaTime) final;
        SceneType type() final;
        void pause();
        void resume();

    private:
        Board _map;
        irr::core::vector3df _cameraTargetSave;
    };
}

#endif
