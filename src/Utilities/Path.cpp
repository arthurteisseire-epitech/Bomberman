/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <iostream>
#include "Path.hpp"
#include "include/crossPlatform.hpp"

std::string ind::Path::progPath = ".";

std::string ind::Path::realpath(const std::string &string)
{
    return progPath + '/' + string;
}

void ind::Path::changePath(const std::string &string)
{
    progPath = string.substr(0, string.find_last_of(DIRECTORYSEPARATOR));
}
