/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Taz
*/

#include <future>
#include <condition_variable>
#include <iostream>
#include "LoadingService.hpp"
#include "Singleton.hpp"
#include "DeviceService.hpp"

std::atomic_bool _finish;
std::map<std::string, ind::animations::Animator *> _loadedAnimators;

ind::LoadingService &ind::LoadingService::enqueueAnimator(std::string name,
                                                          std::vector<ind::LoadAnimationData> data)
{
    if (name.empty())
        throw std::invalid_argument("Loading animator : name empty");
    if (this->_animators.count(name) > 0)
        throw std::invalid_argument("Loading animator : name already taken");
    this->_animators.emplace(name, data);
    return *this;
}

void ind::LoadingService::startLoad()
{
    for (auto &infos : this->_animators) {
        auto *animator = new ind::animations::Animator();
        auto *manager = SingleTon<DeviceService>::getInstance().getSceneManager();

        for (auto &info : infos.second) {
            std::async(std::launch::async,
                       [&]() {
                           animator->registerAnimation(info.id,
                                                       info.folderPath,
                                                       info.texture,
                                                       *manager);
                       }).get();
        }
        _loadedAnimators.emplace(infos.first, animator);
    }
    _finish = true;
}

ind::animations::Animator *ind::LoadingService::getAnimator(const std::string &name)
{
    if (_loadedAnimators.count(name) == 0)
        throw std::invalid_argument("No animator with name : " + name);
    return _loadedAnimators[name];
}