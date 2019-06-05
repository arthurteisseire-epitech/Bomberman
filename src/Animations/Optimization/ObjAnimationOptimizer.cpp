/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Taz
*/

#include <stdexcept>
#include "ObjAnimationOptimizer.hpp"
#include "Services/Singleton.hpp"
#include "Services/FileSystemService.hpp"

ind::animations::optimization::ObjAnimationOptimizer::ObjAnimationOptimizer(
    std::string &folder) : _folder(folder)
{
    services::FILE_STATUS status = SingleTon<services::FileSystemService>
        ::getInstance().exists(folder);

    if (status != services::FILE_STATUS::DIRECTORY)
        throw std::invalid_argument("Unable to open directory : " + folder);
}

void ind::animations::optimization::ObjAnimationOptimizer::serialize()
{

}

void ind::animations::optimization::ObjAnimationOptimizer::deserialize()
{

}

/* std::vector<std::string>& get_file_list(const std::string& path)
{
    if (!path.empty())
    {
        namespace fs = boost::filesystem;

        fs::path apk_path(path);
        fs::recursive_directory_iterator end;

        for (fs::recursive_directory_iterator i(apk_path); i != end; ++i)
        {
            const fs::path cp = (*i);
        //    m_file_list.push_back(cp.string());
        }
    }
 //   return m_file_list;
} */