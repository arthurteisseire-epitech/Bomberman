/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** TimeoutObjectBehaviour.hpp
*/

#ifndef BOMBERMAN_TIMEOUTOBJECTBEHAVIOUR_HPP
#define BOMBERMAN_TIMEOUTOBJECTBEHAVIOUR_HPP

#include "IBehaviour.hpp"
#include "TimeoutObject.hpp"

namespace ind {
    class TimeoutObjectBehaviour : public IBehaviour {
    public:
        explicit TimeoutObjectBehaviour(TimeoutObject &obj);
        ~TimeoutObjectBehaviour() override = default;
        void update(float deltaTime) override;

    private:
        TimeoutObject &object;
    };
}

#endif
