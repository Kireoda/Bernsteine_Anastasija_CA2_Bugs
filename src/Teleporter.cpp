#include "Teleporter.h"
#include <cstdlib>

Teleporter::Teleporter(int id, int x, int y, Direction dir, int health)
    : Bug(id, x, y, dir, health) {}

void Teleporter::move() {
    if (!alive) return;

    int x = rand() % 10;
    int y = rand() % 10;

    position = {x, y};
    addToPath(x, y);
}

std::string Teleporter::getType() const {
    return "Teleporter";
}