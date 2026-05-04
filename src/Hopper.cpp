#include "Hopper.h"
#include <cstdlib>

Hopper::Hopper(int id, int x, int y, Direction dir, int health, int hopLength)
    : Bug(id, x, y, dir, health), hopLength(hopLength) {}

int Hopper::getHopLength() const {
    return hopLength;
}

std::string Hopper::getType() const {
    return "Hopper";
}

void Hopper::move() {
    if (!alive) return;

    while (isWayBlocked()) {
        int r = rand() % 4 + 1;
        direction = static_cast<Direction>(r);
    }

    int x = position.first;
    int y = position.second;

    // Move step by step up to hopLength
    for (int i = 0; i < hopLength; i++) {
        int nextX = x;
        int nextY = y;

        switch (direction) {
            case Direction::North: nextY--; break;
            case Direction::South: nextY++; break;
            case Direction::East:  nextX++; break;
            case Direction::West:  nextX--; break;
        }

        // Check boundary
        if (nextX < 0 || nextX > 9 || nextY < 0 || nextY > 9) {
            break; // stop at edge
        }

        x = nextX;
        y = nextY;
    }

    position = {x, y};
    path.push_back(position);
}