#pragma once

#include <Services/LoadingService.hpp>
#include "AScene.hpp"

namespace ind {
    class LoadingScene : public ind::AScene
    {
        public: LoadingScene();
        public: ~LoadingScene() override = default;
        public: SceneType execute(irr::f32 deltatime) override;
        public: SceneType type() override;
        private: LoadingService _loadingService;
    };
}