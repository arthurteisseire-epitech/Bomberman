/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include "FullPath.hpp"

std::string ind::FullPath::progPath = "./";

std::string ind::FullPath::concatenate(std::string &string)
{
    string = progPath + string;
    return string;
}

void ind::FullPath::changePath(const std::string &string)
{
    progPath = string;
}
