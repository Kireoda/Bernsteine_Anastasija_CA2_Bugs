#include "Direction.h"

std::string directionToString(Direction dir) {
    switch (dir) {
        case Direction::North: return "North";
        case Direction::East:  return "East";
        case Direction::South: return "South";
        case Direction::West:  return "West";
        default: return "Unknown";
    }
}