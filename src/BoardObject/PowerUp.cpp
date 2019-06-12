/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "PowerUp.hpp"
#include "PowerUpBehaviour.hpp"

ind::PowerUp::PowerUp(ind::Position position, const std::string &path)
    : BoardObject(position, path)
{
    auto *behaviour = new PowerUpBehaviour(*this);
    this->setBehaviour(behaviour);
    this->auraParticle = this->manager->addParticleSystemSceneNode(false);
    auto *emitter = this->auraParticle->createCylinderEmitter(
        irr::core::vector3df(0,0,0), // centre
        5.0f, //rayon
        irr::core::vector3df(0, 0.0f,0), //normale
        1.0f, //taille
        false,
        irr::core::vector3df(0,0.04f,0), //direction
        200,
        300,
        irr::video::SColor(0,255,255,255),
        irr::video::SColor(0,255,255,255),
        1000,
        1010,
        0,
        irr::core::vector2df(0.1f,0.1f),
        irr::core::vector2df(1.0f,1.0f)
    );
    auraParticle->setPosition(irr::core::vector3df(position.x * TILE_SIZE, 0.0f, position.y * TILE_SIZE));
    irr::scene::IParticleAffector* affector =    // creation du modificateur
        auraParticle->createFadeOutParticleAffector(
            irr::video::SColor(0,30,100,100),             // la couleur finale
            1200);                                   // temps necessaire a la modification
    auraParticle->addAffector(affector);       // ajout du modificateur au particle system
    affector->drop();                            // plus besoin de ca
    auraParticle->setEmitter(emitter);
    emitter->drop();
    auraParticle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    auraParticle->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    auraParticle->setMaterialTexture(0, manager->getVideoDriver()->getTexture("assets/light.png"));
    auraParticle->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
}

ind::Tile ind::PowerUp::getTile() const
{
    return POWERUP;
}

ind::PowerUp::~PowerUp()
{
    if (this->auraParticle)
        this->auraParticle->remove();
}

irr::scene::ISceneNode *ind::PowerUp::getSceneNode() const
{
    return this->node;
}
