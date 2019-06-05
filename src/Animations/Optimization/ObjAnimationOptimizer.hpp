/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Taz
*/

#pragma once

#include <string>
#include "IAnimatedMeshOptimizer.hpp"

namespace ind {
    namespace animations {
        namespace optimization {

            class ObjAnimationOptimizer : public IAnimatedMeshOptimizer
            {
                public:
                    ObjAnimationOptimizer(std::string &folder);
                    void serialize() override;
                    void deserialize() override;
                private:
                    std::string _folder;
            };

        }
    }
}
