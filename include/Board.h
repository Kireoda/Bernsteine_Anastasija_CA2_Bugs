#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "Bug.h"

class Board {
private:
    std::vector<Bug*> bugs;

public:
    Board();
    ~Board();

    // Core
    void loadFromFile(const std::string& filename);
    void displayAllBugs() const;
    void findBugById(int id) const;
    void tapBoard();

    // Utility
    void clear();
};

#endif