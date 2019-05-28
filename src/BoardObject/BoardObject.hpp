/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BoardObject.hpp
*/

#ifndef BOMBERMAN_BOARDOBJECT_HPP
#define BOMBERMAN_BOARDOBJECT_HPP

#include <irrlicht/irrlicht.h>
#include <string>
#include "AbstractEntity.hpp"
#include "Orientation.hpp"
#include "Position.hpp"
#include "Tile.hpp"

namespace ind {
    class BoardObject : public AbstractEntity {
    public:
        BoardObject(irr::scene::ISceneManager *mgr, Position position, const irr::io::path &path);
        ~BoardObject();

        virtual Tile getTile() const = 0;
        const Position &getPosition() const;

    protected:
        Position position;
        irr::video::ITexture *texture;
        irr::scene::ISceneNode *node;
    };
}

#endif
