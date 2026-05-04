#include "Bug.h"

Bug::Bug(int id, int x, int y, Direction dir, int health)
    : id(id), position({x, y}), direction(dir), health(health), alive(true), killerId(-1)
{
    path.push_back(position);
}

Bug::~Bug() {}

bool Bug::isWayBlocked() {
    int x = position.first;
    int y = position.second;

    if (direction == Direction::North && y == 0) return true;
    if (direction == Direction::South && y == 9) return true;
    if (direction == Direction::West  && x == 0) return true;
    if (direction == Direction::East  && x == 9) return true;

    return false;
}

// Getters
int Bug::getId() const { return id; }

std::pair<int,int> Bug::getPosition() const { return position; }

Direction Bug::getDirection() const { return direction; }

int Bug::getHealth() const { return health; }

bool Bug::isAlive() const { return alive; }

int Bug::getKillerId() const { return killerId; }

// Setters
void Bug::setPosition(int x, int y) {
    position = {x, y};
}

void Bug::setDirection(Direction dir) {
    direction = dir;
}

void Bug::takeDamage(int dmg) {
    health -= dmg;
    if (health <= 0) {
        health = 0;
        alive = false;
    }
}

void Bug::setKiller(int id) { killerId = id; }

// Path
void Bug::addToPath(int x, int y) {
    path.push_back({x, y});
}

const std::list<std::pair<int,int>>& Bug::getPath() const {
    return path;
}