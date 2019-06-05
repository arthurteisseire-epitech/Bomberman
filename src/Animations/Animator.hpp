/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Taz
*/

#pragma once

#include <string>
#include <map>
#include <memory>
#include "Position.hpp"
#include "AnimatedMesh.hpp"

namespace ind {
    namespace animations {
        class Animator {
        public:
            ~Animator();
            void update();
            void registerAnimation(std::string id, std::string path, std::string textures,
                                   irr::scene::ISceneManager &manager);
            Animator &playAnimation(bool loop = true);
            Animator &stopAnimation();
            Animator &setCurrentAnimation(std::string id);
            Animator &setCurrentAnimationSpeed(irr::s32 speed);
            Animator &setAnimationsScale(const irr::core::vector3df &scale);
            Animator &setAnimationsRotation(const irr::core::vector3df &rotation);
            Animator &setAnimationsPosition(const irr::core::vector3df &position);
            const irr::core::vector3df &getCurrentAnimationPosition();
        private:
            std::string _currentAnimationId = "";
            std::unique_ptr<ind::animations::AnimatedMesh> *_currentAnimation = nullptr;
            std::map<std::string, std::unique_ptr<ind::animations::AnimatedMesh>> _animations;
        };
    }
}