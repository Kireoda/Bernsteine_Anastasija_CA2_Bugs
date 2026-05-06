#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>
#include <string>
#include "Direction.h"

class Bug {
protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int health;
    bool alive;
    std::list<std::pair<int,int>> path;
    int killerId;

public:
    // Constructor
    Bug(int id, int x, int y, Direction dir, int health);

    // Virtual destructor
    virtual ~Bug();

    // Pure virtual functions
    virtual void move() = 0;
    virtual std::string getType() const = 0;

    // Common logic
    bool isWayBlocked() const;

    // Getters
    int getId() const;
    std::pair<int,int> getPosition() const;
    Direction getDirection() const;
    int getHealth() const;
    bool isAlive() const;
    int getKillerId() const;

    // Setters
    void setPosition(int x, int y);
    void setDirection(Direction dir);
    void takeDamage(int dmg);
    void setKiller(int id);

    // Path
    void addToPath(int x, int y);
    const std::list<std::pair<int,int>>& getPath() const;
};

#endif