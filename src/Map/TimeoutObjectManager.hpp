/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** TimeoutObjectManager.hpp
*/

#ifndef BOMBERMAN_TIMEOUTOBJECTMANAGER_HPP
#define BOMBERMAN_TIMEOUTOBJECTMANAGER_HPP

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "TimeoutObject.hpp"

namespace ind {
    template<typename T>
    class TimeoutObjectManager {
    public:
        TimeoutObjectManager() = default;

        void addObject(const std::shared_ptr<T> &obj, TimeoutObject *timeoutObject)
        {
            auto pair = std::pair<std::shared_ptr<T>, TimeoutObject *>(obj, timeoutObject);
            objects.push_back(pair);
        }

        std::vector<std::shared_ptr<T>> popDeadObjects()
        {
            std::vector<std::shared_ptr<T>> deadObjects = {};

            objects.erase(std::remove_if(objects.begin(), objects.end(),
                                         [&](std::pair<std::shared_ptr<T>, TimeoutObject *> &pair) {
                                             bool match = pair.second->getTime() <= 0;
                                             if (match)
                                                 deadObjects.emplace_back(pair.first);
                                             return match;
                                         }), objects.end());
            return deadObjects;
        }

    private:
        std::vector<std::pair<std::shared_ptr<T>, TimeoutObject *>> objects;
    };
}

#endif
