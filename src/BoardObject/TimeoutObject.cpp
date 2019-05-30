/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** TimeoutObject.cpp
*/

#include "TimeoutObject.hpp"

ind::TimeoutObject::TimeoutObject(float livingTime) :
    livingTime(livingTime)
{
}

void ind::TimeoutObject::decreaseTime(float n)
{
    livingTime -= n;
}

float ind::TimeoutObject::getTime() const
{
    return livingTime;
}

