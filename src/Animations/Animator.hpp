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
                Animator();
                ~Animator();
                void update();
                Animator &registerAnimation(std::string id, std::string path, std::string textures, irr::scene::ISceneManager &manager);
                Animator &playAnimation(bool loop = true);
                Animator &stopAnimation();
                Animator &setCurrentAnimation(std::string id);
                Animator &resetCurrentAnimationToZeroThenSet(std::string id);
                void setAnimationPosition(const irr::core::vector3df &position);
                const irr::core::vector3df &getAnimationPosition();
            private:
                std::string _nextAnimationId = "";
                std::string _currentAnimationId = "";
                bool _waitForCurrentAnimationToFinish = false;
                std::unique_ptr<ind::animations::AnimatedMesh> *_currentAnimation = nullptr;
                std::map<std::string, std::unique_ptr<ind::animations::AnimatedMesh>> *_animations = nullptr;
        };
    }
}
