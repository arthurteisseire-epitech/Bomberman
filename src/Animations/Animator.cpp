#include <iostream>
#include "Animator.hpp"

ind::animations::Animator::Animator()
{
    this->_animations = new std::map<std::string, std::unique_ptr<ind::animations::AnimatedMesh>>;
}

ind::animations::Animator &ind::animations::Animator::registerAnimation(std::string id, std::string modelPath, std::string texture, irr::scene::ISceneManager &manager)
{
    if (modelPath.empty())
        return *this;
    // TODO : check if folder exists

    ind::animations::AnimatedMesh *mesh = nullptr;

    try
    {
        mesh = new ind::animations::AnimatedMesh(manager, modelPath, texture);

        if (this->_animations->count(id) > 0)
            std::cerr << "Unable to register animation because id '" << id << "' already taken" << std::endl;
        else
            this->_animations->emplace(id, mesh);
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
    return *this;
}

ind::animations::Animator::~Animator()
{
    free(this->_animations);
}

ind::animations::Animator &ind::animations::Animator::resetCurrentAnimationToZeroThenSet(std::string id)
{
    if (this->_currentAnimation != nullptr) {
        this->_waitForCurrentAnimationToFinish = true;
        this->_currentAnimation->get()->resetToZero();
        this->_nextAnimationId = std::move(id);
    }
    return *this;
}

ind::animations::Animator &ind::animations::Animator::setCurrentAnimation(std::string id)
{
    if (this->_currentAnimationId == id)
        return *this;
    if (this->_animations->count(id) == 0)
        throw std::invalid_argument("Animation " + id + " doesn't exists");
    if (this->_currentAnimation != nullptr)
        this->stopAnimation();
    this->_currentAnimation = &this->_animations->at(id);
    this->_currentAnimation->get()->getSceneNode()->setCurrentFrame(0);
    this->_currentAnimationId = id;
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
    /*
    * TODO : Implement logic
    */
    this->_currentAnimation->get()->getSceneNode()->setVisible(false);
    this->_currentAnimation = nullptr;
    return *this;
}

void ind::animations::Animator::setAnimationPosition(const irr::core::vector3df &position)
{
    for (const auto &animation : *this->_animations)
        animation.second->getSceneNode()->setPosition(position);
}

const irr::core::vector3df &ind::animations::Animator::getAnimationPosition()
{
    if (this->_currentAnimation != nullptr)
        return this->_currentAnimation->get()->getSceneNode()->getPosition();
    return std::move(irr::core::vector3df(0, 0, 0));
}

void ind::animations::Animator::update()
{
    if (this->_currentAnimation != nullptr && this->_waitForCurrentAnimationToFinish) {
        if (!this->_currentAnimation->get()->getToZero()) {
            this->stopAnimation();
            this->setCurrentAnimation(this->_nextAnimationId);
            this->_nextAnimationId = "";
            this->_waitForCurrentAnimationToFinish = false;
        }
    }
}