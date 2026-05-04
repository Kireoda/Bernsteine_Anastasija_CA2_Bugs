#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(int id, int x, int y, Direction dir, int health, int hopLength);

    void move() override;

    int getHopLength() const;
};

#endif