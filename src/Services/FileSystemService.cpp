/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Taz
*/

#include "FileSystemService.hpp"

/*
 * TODO : Use boost
 */

services::FILE_STATUS services::FileSystemService::exists(std::string &path)
{
    struct stat info;

    if (stat(path.c_str(), &info ) != 0 )
        return FILE_STATUS::CANNOT_ACCESS;
    else if (info.st_mode & S_IFDIR)
        return FILE_STATUS::DIRECTORY;
    else if (info.st_mode & S_IFREG)
        return FILE_STATUS::FILE;
    return FILE_STATUS::UNKNOWN;
}
