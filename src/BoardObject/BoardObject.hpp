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

#define BOMB_NAME "bomb"
#define BLOCKBREAKABLE_NAME "blockbreakable"
#define WALL_NAME "wall"
#define BOMBUP_NAME "bombup"
#define FIREUP_NAME "fireup"
#define SPEEDUP_NAME "speedup"
#define WALLPASS_NAME "wallpass"

namespace ind {
    class BoardObject : public AbstractEntity {
    public:
        BoardObject(Position position, const std::string &path);
        ~BoardObject() override;

        virtual Tile getTile() const = 0;
        virtual std::string toString() const;

        const Position &getPosition() const;

    protected:
        void createGraphicalCube(int height = 0);

        Position position;
        irr::video::ITexture *texture;
        irr::scene::ISceneNode *node;
    };
}

#endif
