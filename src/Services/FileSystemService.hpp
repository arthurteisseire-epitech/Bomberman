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
        UNKNOW
    };

    class FileSystemService {
        public:
            FILE_STATUS exists(std ::string &path);
    };
}
