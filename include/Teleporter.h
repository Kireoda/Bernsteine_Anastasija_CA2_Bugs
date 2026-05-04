#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "Bug.h"

class Teleporter : public Bug {
public:
    Teleporter(int id, int x, int y, Direction dir, int health);

    void move() override;
    std::string getType() const override;
};

#endif