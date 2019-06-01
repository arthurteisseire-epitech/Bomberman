/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Explosion.cpp
*/

#include "TimeoutObjectBehaviour.hpp"
#include "Explosion.hpp"

ind::Explosion::Explosion(ind::Position position) :
    BoardObject(position, "assets/red.jpg"),
    TimeoutObject(1)
{
    //createGraphicalCube();
    this->particleSystem = this->manager->addParticleSystemSceneNode(false);
    particleSystem->setPosition(irr::core::vector3df(position.x * TILE_SIZE, 0.0f, position.y * TILE_SIZE));
    auto *emitter = particleSystem->createCylinderEmitter(
        irr::core::vector3df(0,0,0), // centre
        5.0f, //rayon
        irr::core::vector3df(0, 0.0f,0), //normale
        1.0f, //taille
        false,
        irr::core::vector3df(0,0.0f,0), //direction
        20,
        30,
        irr::video::SColor(0,255,255,255),
        irr::video::SColor(0,255,255,255),
        500,
        510,
        0,
        irr::core::vector2df(8.0f,8.0f),
        irr::core::vector2df(10.0f,10.0f)
    );
    irr::scene::IParticleAffector* affector =    // creation du modificateur
        particleSystem->createFadeOutParticleAffector(
            irr::video::SColor(0,100,30,30),             // la couleur finale
            1200);                                   // temps necessaire a la modification
    particleSystem->addAffector(affector);       // ajout du modificateur au particle system
    affector->drop();                            // plus besoin de ca
    particleSystem->setEmitter(emitter);
    emitter->drop();
    particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    particleSystem->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    particleSystem->setMaterialTexture(0, manager->getVideoDriver()->getTexture("assets/explosion.png"));
    particleSystem->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
    setBehaviour(new TimeoutObjectBehaviour(*this));
}

ind::Tile ind::Explosion::getTile() const
{
    return EXPLOSION;
}

ind::Explosion::~Explosion()
{
    if (particleSystem)
        particleSystem->remove();
}
