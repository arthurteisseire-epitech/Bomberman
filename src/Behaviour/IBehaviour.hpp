/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

namespace ind {

    class IBehaviour {
        public:
            virtual ~IBehaviour() = default;
            virtual void update(float) = 0;
    };
}
