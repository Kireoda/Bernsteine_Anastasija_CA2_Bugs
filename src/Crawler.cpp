#include "Crawler.h"
#include <cstdlib>

Crawler::Crawler(int id, int x, int y, Direction dir, int health)
    : Bug(id, x, y, dir, health) {}

void Crawler::move() {
    if (!alive) return;

    while (isWayBlocked()) {
        int r = rand() % 4 + 1;
        direction = static_cast<Direction>(r);
    }

    int x = position.first;
    int y = position.second;

    // Move 1 step
    switch (direction) {
        case Direction::North: y--; break;
        case Direction::South: y++; break;
        case Direction::East:  x++; break;
        case Direction::West:  x--; break;
    }

    // Update position
    position = {x, y};

    // Record path
    path.push_back(position);
}

std::string Crawler::getType() const {
    return "Crawler";
}
