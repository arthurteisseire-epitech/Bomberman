/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include "Path.hpp"

std::string ind::Path::progPath = ".";

std::string ind::Path::assetPath(std::string &string)
{
    string = "/assets/" + progPath + string;
    return string;
}

void ind::Path::changePath(const std::string &string)
{
    progPath = string;
    if (progPath.back() == '/')
        progPath = progPath.substr(0, progPath.size() - 1);
}
