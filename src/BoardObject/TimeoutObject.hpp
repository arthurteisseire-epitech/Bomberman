/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** TimeoutObject.hpp
*/

#ifndef BOMBERMAN_TIMEOUTOBJECT_HPP
#define BOMBERMAN_TIMEOUTOBJECT_HPP

namespace ind {
    class TimeoutObject {
    public:
        explicit TimeoutObject(float livingTime);

        void decreaseTime(float n);
        float getTime() const;

    private:
        float livingTime;
    };
}

#endif
