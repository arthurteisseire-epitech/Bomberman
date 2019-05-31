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
    private:
        Board _map;
        std::string _rootPath;
        std::vector<std::unique_ptr<Player>> players;
        ind::animations::AnimatedMesh *mesh = nullptr;
        irr::scene::IMeshSceneNode *initializePlayerCube() const;
        void initRootPath();
    };
}

#endif
