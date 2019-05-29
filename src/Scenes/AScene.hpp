/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#ifndef BOMBERMAN_ASCENE_HPP
#define BOMBERMAN_ASCENE_HPP

#include <string>
#include <irrlicht/irrTypes.h>
#include <irrlicht/ISceneManager.h>

namespace ind {
    enum SceneType {
        MAIN_MENU,
        OPTIONS,
        GAME,
        END
    };

    class AScene {
    public:
        AScene();
        virtual ~AScene() = default;
        virtual SceneType execute(irr::f32 deltaTime) = 0;
        virtual SceneType type() = 0;
    protected:
        const std::string _progPath;
        irr::scene::ISceneManager *_manager;
    };
}

std::ostream& operator<<(std::ostream& out, ind::SceneType type);

#endif //BOMBERMAN_ASCENE_HPP
