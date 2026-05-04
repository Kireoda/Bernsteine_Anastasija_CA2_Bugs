#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

enum class Direction {
    North = 1,
    East,
    South,
    West
};

std::string directionToString(Direction dir);

#endif