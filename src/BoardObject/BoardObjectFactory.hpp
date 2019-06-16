/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BoardObjectFactory.hpp
*/

#ifndef BOMBERMAN_BOARDOBJECTFACTORY_HPP
#define BOMBERMAN_BOARDOBJECTFACTORY_HPP

#include <map>
#include "Board.hpp"
#include "BoardObject.hpp"

namespace ind {
    class BoardObjectFactory {
    public:
        static BoardObject *create(const std::string &type, const Position &pos, Board &board);
    private:
        typedef std::map<const std::string, std::function<BoardObject *(const Position &pos, Board &board)>> BoardObjectMap;
        static const BoardObjectMap boardObjectMap;
    };
}

#endif
