#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <map>
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
    void displayLifeHistory() const;
    void tapBoard();
    void resolveFights();
    int countAlive() const;
    void runSimulation();
    void testFights();
    void testDeadBehavior();

    // Utility
    void clear();

    void displayCells() const;

    std::map<std::pair<int, int>, std::vector<Bug *> > buildCellMap() const;
};

#endif
