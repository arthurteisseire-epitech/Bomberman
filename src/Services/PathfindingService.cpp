/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by antoine_dh,
*/

#include <map>
#include "PathfindingService.hpp"

static const std::array<ind::Position, 4> DIRECTIONS = {
    ind::Position(1, 0),
    ind::Position(0, 1),
    ind::Position(-1, 0),
    ind::Position(0, -1),
};

std::vector<ind::Position> ind::PathfindingService::searchPath(
    const ind::Board &board, const ind::Position &from, const ind::Position &to)
{
    State state(board);

    if (state.closed[from.x][from.y].distance < 0
        or state.closed[to.x][to.y].distance < 0)
        return std::vector<ind::Position>();
    state.closed[from.x][from.y].distance = 1;
    state.closed[from.x][from.y].heuristic = heuristicDistance(from, to);
    state.open.push(state.closed[from.x][from.y]);
    while (not state.open.empty()) {
        Node node = state.open.top();
        state.open.pop();
        if (node == to) {
            state.backtrack(from, to.x, to.y, state.closed[to.x][to.y].distance);
            return state.path;
        }
        state.checkNeighbors(node, to);
    }
    return std::vector<ind::Position>();
}

int ind::PathfindingService::heuristicDistance(const ind::Position &a,
    const ind::Position &b)
{
    return (abs(b.x - a.x) + abs(b.y - a.y));
}

void ind::PathfindingService::State::backtrack(const Position &begin, int x,
    int y, int distance)
{
    Position closest = Position(-1, -1);

    path.insert(path.begin(), Position(x, y));
    if (begin == Position(x, y))
        return;
    for (size_t i = 0 ; i < 4 ; ++i) {
        Position p = Position(x + DIRECTIONS[i].x, y + DIRECTIONS[i].y);
        if (p.x > mapSize.x - 1 or p.y > mapSize.y - 1 or
            p.x < 0 or p.y < 0 or closed[p.x][p.y].distance < 1)
            continue;
        if ((closest.x == -1 and
            std::find(path.begin(), path.end(), p) == path.end()) or
            (closed[p.x][p.y].distance < distance)) {
            distance = closed[p.x][p.y].distance;
            closest = Position(p.x, p.y);
        }
    }
    if (closest.x != -1 and closest.y != -1)
        backtrack(begin, closest.x, closest.y, distance);
}

ind::PathfindingService::Node::Node(int x, int y, int distance, int heuristic)
    : Position(x, y), distance(distance), heuristic(heuristic)
{
}

ind::PathfindingService::Node::Node()
    : Position(0, 0), distance(0), heuristic(0)
{
}

ind::PathfindingService::State::State(const ind::Board &board)
    : closed(static_cast<unsigned long>(board.getSize().x)),
    mapSize(board.getSize())
{
    std::map<Tile, int> tiletypes {
        {Tile::EMPTY, 0},
        {Tile::POWERUP, 0},
        {Tile::BLOCKBREAKABLE, -1},
        {Tile::BOMB, -1},
        {Tile::EXPLOSION, -1},
        {Tile::WALL, -1},
    };

    for (int x = 0 ; x < mapSize.x ; ++x) {
        closed[x].resize(static_cast<unsigned long>(mapSize.y));
        for (int y = 0 ; y < mapSize.y ; ++y) {
            closed[x][y] = Node(x, y, tiletypes[board.getInfoAtCoord(x, y)]);
        }
    }
}

void ind::PathfindingService::State::checkNeighbors(
    const ind::PathfindingService::Node &u, const Position &to)
{
    Node neighs[4];

    for (size_t i = 0 ; i < 4 ; ++i) {
        neighs[i].x = u.x + DIRECTIONS[i].x;
        neighs[i].y = u.y + DIRECTIONS[i].y;
        if (neighs[i].x > mapSize.x - 1 or (neighs[i].x < 0) or
            neighs[i].y > mapSize.y - 1 or (neighs[i].y < 0) or
            closed[neighs[i].x][neighs[i].y].distance < 0)
            continue;
        neighs[i].distance = u.distance + 1;
        neighs[i].heuristic = neighs[i].distance +
            PathfindingService::heuristicDistance(neighs[i], to);
        Node &node = closed[neighs[i].x][neighs[i].y];
        if (neighs[i].distance < 1 or node.heuristic != 0)
            continue;
        open.push(neighs[i]);
        node.heuristic = neighs[i].heuristic;
        if (node.distance == 0 or node.distance > neighs[i].distance)
            node.distance = neighs[i].distance;
    }
}
