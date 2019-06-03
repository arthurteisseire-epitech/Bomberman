#pragma once

#include <irrlicht/ISceneManager.h>
#include <map>
#include <string>
#include <mutex>
#include <atomic>
#include "Animations/Animator.hpp"

namespace ind
{
    struct LoadAnimationData {
        std::string id;
        std::string folderPath;
        std::string texture;
    };

    class LoadingService
    {
        public:
                void startLoad();
                LoadingService &enqueueAnimator(std::string name, std::vector<ind::LoadAnimationData> data);
                ind::animations::Animator *getAnimator(std::string name);
        private:
                std::map<std::string, std::vector<ind::LoadAnimationData>> _animators;
    };
}