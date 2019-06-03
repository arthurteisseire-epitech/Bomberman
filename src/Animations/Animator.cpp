#include <iostream>
#include "Animator.hpp"

void ind::animations::Animator::registerAnimation(std::string id, std::string modelPath, std::string texture,
                                                  irr::scene::ISceneManager &manager)
{
    if (modelPath.empty())
        return;
    // TODO : check if folder exists
    try {
        if (this->_animations.count(id) > 0)
            std::cerr << "Unable to register animation because id '" << id << "' already taken" << std::endl;
        else
            this->_animations.emplace(id, new ind::animations::AnimatedMesh(manager, modelPath, texture));
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
    //   return *this;
}

ind::animations::Animator &ind::animations::Animator::setCurrentAnimation(std::string id)
{
    if (this->_currentAnimationId == id)
        return *this;
    if (this->_animations.count(id) == 0)
        throw std::invalid_argument("Animation " + id + " doesn't exists");
    if (this->_currentAnimation != nullptr)
        this->stopAnimation();
    this->_currentAnimation = &this->_animations.at(id);
    this->_currentAnimation->get()->getSceneNode()->setCurrentFrame(0);
    this->_currentAnimationId = id;
    return *this;
}

ind::animations::Animator &ind::animations::Animator::setCurrentAnimationSpeed(
        const irr::s32 speed)
{
    if (this->_currentAnimation != nullptr)
        this->_currentAnimation->get()->getSceneNode()->setAnimationSpeed(speed);
    return *this;
}

ind::animations::Animator &ind::animations::Animator::playAnimation(bool loop)
{
    if (this->_currentAnimation == nullptr)
        return *this;
    this->_currentAnimation->get()->getSceneNode()->setCurrentFrame(0);
    this->_currentAnimation->get()->getSceneNode()->setLoopMode(loop);
    this->_currentAnimation->get()->getSceneNode()->setVisible(true);
    return *this;
}

ind::animations::Animator &ind::animations::Animator::stopAnimation()
{
    if (this->_currentAnimation == nullptr)
        return *this;
    this->_currentAnimation->get()->getSceneNode()->setVisible(false);
    this->_currentAnimation = nullptr;
    return *this;
}

ind::animations::Animator &ind::animations::Animator::setAnimationsRotation(
        const irr::core::vector3df &rotation)
{
    for (const auto &animation : this->_animations)
        animation.second->getSceneNode()->setRotation(rotation);
    return *this;
}

ind::animations::Animator &ind::animations::Animator::setAnimationsPosition(const irr::core::vector3df &position)
{
    for (const auto &animation : this->_animations)
        animation.second->getSceneNode()->setPosition(position);
    return *this;
}

const irr::core::vector3df &ind::animations::Animator::getCurrentAnimationPosition()
{
    if (this->_currentAnimation != nullptr)
        return this->_currentAnimation->get()->getSceneNode()->getPosition();
    return std::move(irr::core::vector3df(0, 0, 0));
}

void ind::animations::Animator::update()
{}

ind::animations::Animator &ind::animations::Animator::setAnimationsScale(const irr::core::vector3df &scale)
{
    for (const auto &animation : this->_animations)
        animation.second->getSceneNode()->setScale(scale);
    return *this;
}

ind::animations::Animator::~Animator()
{
    for (const auto &animation : this->_animations)
        animation.second->getSceneNode()->remove();
}