#include <sys/types.h>
#include <iostream>
#include <algorithm>
#include <dirent.h>
#include "AnimatedMesh.hpp"

#define EMPTY_FRAME_ERROR "No frame selected"
#define BAD_FRAME_INDEX_ERROR "Required frame index bigger than frame buffer size"

ind::animations::AnimatedMesh::AnimatedMesh(irr::scene::ISceneManager &manager,
    std::string &objfolderpath, std::string &texture) : _folderPath(objfolderpath)
{
    if (this->_folderPath.empty())
        throw "Can not create AnimatedMesh. File path empty.";
    if (this->_folderPath[this->_folderPath.length() - 1] != '/')
        this->_folderPath += "/";
    // TODO : Check if directory exists
    this->loadFolder(manager);
    this->_sceneNode = manager.addAnimatedMeshSceneNode(this);
    this->loadTexture(manager, texture);
    /*
     * visibility = true when Animator.setCurrentAnimation called
     */
    this->_sceneNode->setVisible(false);
}

void ind::animations::AnimatedMesh::loadFolder(irr::scene::ISceneManager &manager)
{
    struct dirent *dp;
    DIR* dir = opendir(this->_folderPath.c_str());
    std::vector<std::string> paths;

    while ((dp = readdir(dir)) != nullptr) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;
        std::string name(dp->d_name);
        if (name.substr(name.find_last_of('.') + 1) != "obj")
            continue;
        std::string path = this->_folderPath + dp->d_name;
        paths.emplace_back(path);
    }
    std::sort(paths.begin(), paths.end());
    for (const auto &path : paths)
        this->_frames.emplace_back(manager.getMesh(path.c_str()));
    this->_frame = this->_frames[0];
    closedir(dir);
}

irr::f32 ind::animations::AnimatedMesh::getAnimationSpeed() const
{
    return 24;
}

irr::scene::IMesh *ind::animations::AnimatedMesh::getMesh(irr::s32 frame,
    irr::s32 detailLevel, irr::s32 startFrameLoop, irr::s32 endFrameLoop)
{
    if (frame > this->_frames.size())
        throw BAD_FRAME_INDEX_ERROR;
    std::cout << "salut3\n";
    if (this->_toZero) {
        if (this->_frameIndex > 0) {
            this->_frameIndex--;
            return this->_frames[this->_frameIndex]->getMesh(0, detailLevel, startFrameLoop, endFrameLoop);
        } else {
            this->_toZero = false;
            return this->_frames[this->_frameIndex]->getMesh(0, detailLevel, startFrameLoop, endFrameLoop);
        }
    }
    this->_frame = this->_frames[(ulong)frame];
    this->_frameIndex = frame;
    return this->_frame->getMesh(0, detailLevel, startFrameLoop, endFrameLoop);
}

irr::u32 ind::animations::AnimatedMesh::getFrameCount() const
{
    return (irr::u32)this->_frames.size();
}

irr::scene::E_ANIMATED_MESH_TYPE ind::animations::AnimatedMesh::getMeshType() const
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return this->_frame->getMeshType();
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
    const irr::core::aabbox3df &box)
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->setBoundingBox(box);
}

void ind::animations::AnimatedMesh::setMaterialFlag(
    irr::video::E_MATERIAL_FLAG flag, bool newvalue)
{
    if (this->_frame == nullptr)
        throw EMPTY_FRAME_ERROR;
    return _frame->setMaterialFlag(flag, newvalue);
}

void ind::animations::AnimatedMesh::setHardwareMappingHint(
    irr::scene::E_HARDWARE_MAPPING newMappingHint,
    irr::scene::E_BUFFER_TYPE buffer)
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

void ind::animations::AnimatedMesh::loadTexture(irr::scene::ISceneManager &manager, std::string &texture)
{
    if (texture.empty())
        return;
    this->_sceneNode->setMaterialTexture(0, manager.getVideoDriver()->getTexture(texture.c_str()));
    this->_sceneNode->setMaterialFlag(irr::video::EMF_LIGHTING, true); // enable dynamic lighting
    this->_sceneNode->getMaterial(0).Shininess = 20.0f; // set size of specular highlights
}

irr::scene::IAnimatedMeshSceneNode *ind::animations::AnimatedMesh::getSceneNode()
{
    return this->_sceneNode;
}

void ind::animations::AnimatedMesh::resetToZero()
{
    this->_toZero = true;
}

const bool ind::animations::AnimatedMesh::getToZero() const
{
    return this->_toZero;
}

