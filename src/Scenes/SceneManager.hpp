/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_SCENEMANAGER_HPP
#define BOMBERMAN_SCENEMANAGER_HPP

#include <memory>
#include "AScene.hpp"

namespace ind {
    class SceneManager {
    public:
        explicit SceneManager(SceneType sceneType = MAIN_MENU);
        SceneType executeScene(irr::f32 deltaTime) const;
        void buildScene(ind::SceneType type);
    private:
        std::unique_ptr<AScene> _currentScene;
    };
}

#endif //BOMBERMAN_SCENEMANAGER_HPP
