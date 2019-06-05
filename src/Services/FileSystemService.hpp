/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Taz
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <sys/stat.h>

namespace services
{
    enum FILE_STATUS {
        CANNOT_ACCESS,
        FILE,
        DIRECTORY,
        UNKNOWN
    };

    class FileSystemService {
        public:
            FILE_STATUS exists(std ::string &path);
    };
}
