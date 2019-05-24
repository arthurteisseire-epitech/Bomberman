#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include "AnimatedMesh.hpp"

#define EMPTY_FRAME_ERROR "No frame selected"
#define BAD_FRAME_INDEX_ERROR "Required frame index bigger than frame buffer size"

ind::animations::AnimatedMesh::AnimatedMesh(irr::scene::ISceneManager &manager,
    std::string &objfolderpath) : _folderPath(objfolderpath)
{
    if (this->_folderPath.empty())
        throw "Can not create AnimatedMesh. File path empty.";
    if (this->_folderPath[this->_folderPath.length() + 1] != '/')
        this->_folderPath += "/";
    // TODO : Check if directory exists
    this->loadFolder(manager);
}

void ind::animations::AnimatedMesh::loadFolder(irr::scene::ISceneManager &manager)
{
    struct dirent *dp;
    DIR* dir = opendir(this->_folderPath.c_str());

    while ((dp = readdir(dir)) != nullptr) {
        std::string path = this->_folderPath + dp->d_name;
        this->_frames.emplace_back(manager.getMesh(path.c_str()));
        if (this->_frame == nullptr)
            this->_frame = std::unique_ptr<irr::scene::IAnimatedMesh>(this->_frames.at(0));
    }
    closedir(dir);
}

irr::f32 ind::animations::AnimatedMesh::getAnimationSpeed() const
{
    return 1;
}

irr::scene::IMesh *ind::animations::AnimatedMesh::getMesh(irr::s32 frame,
    irr::s32 detailLevel, irr::s32 startFrameLoop, irr::s32 endFrameLoop
)
{
    if (frame > this->_frames.size())
        throw BAD_FRAME_INDEX_ERROR;
    return this->_frames.at((ulong)frame);
}

irr::u32 ind::animations::AnimatedMesh::getFrameCount() const
{
    return (irr::u32)this->_frames.size();
}

irr::scene::E_ANIMATED_MESH_TYPE ind::animations::AnimatedMesh::getMeshType() const
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->getMeshType();
}

void ind::animations::AnimatedMesh::setAnimationSpeed(irr::f32 fps)
{
    // TODO
}

irr::u32 ind::animations::AnimatedMesh::getMeshBufferCount() const
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->getMeshBufferCount();
}

irr::scene::IMeshBuffer *ind::animations::AnimatedMesh::getMeshBuffer(
    irr::u32 nr) const
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->getMeshBuffer(nr);
}

irr::scene::IMeshBuffer *ind::animations::AnimatedMesh::getMeshBuffer(
    const irr::video::SMaterial &material) const
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->getMeshBuffer(material);
}

const irr::core::aabbox3d<irr::f32> &ind::animations::AnimatedMesh::getBoundingBox() const
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->getBoundingBox();
}

void ind::animations::AnimatedMesh::setBoundingBox(
    const irr::core::aabbox3df &box
)
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->setBoundingBox(box);
}

void ind::animations::AnimatedMesh::setMaterialFlag(
    irr::video::E_MATERIAL_FLAG flag, bool newvalue
)
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->setMaterialFlag(flag, newvalue);
}

void ind::animations::AnimatedMesh::setHardwareMappingHint(
    irr::scene::E_HARDWARE_MAPPING newMappingHint,
    irr::scene::E_BUFFER_TYPE buffer
)
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->setHardwareMappingHint(newMappingHint, buffer);
}

void ind::animations::AnimatedMesh::setDirty(irr::scene::E_BUFFER_TYPE buffer)
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->setDirty(buffer);
}


