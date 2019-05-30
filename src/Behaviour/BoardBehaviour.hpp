/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BoardBehaviour.hpp
*/

#ifndef BOMBERMAN_BOARDBEHAVIOUR_HPP
#define BOMBERMAN_BOARDBEHAVIOUR_HPP

#include "Board.hpp"
#include "IBehaviour.hpp"

namespace ind {
        class BoardBehaviour : public IBehaviour {
        public:
            explicit BoardBehaviour(Board &board);
            ~BoardBehaviour() override = default;
            void update(float deltaTime) override;

        private:
            Board &board;
    };
}

#endif
