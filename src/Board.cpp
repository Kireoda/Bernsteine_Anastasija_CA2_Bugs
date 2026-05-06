#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Teleporter.h"
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iostream>

Board::Board() {}

Board::~Board() {
    clear();
}

std::map<std::pair<int,int>, std::vector<Bug*>> Board::buildCellMap() const {
    std::map<std::pair<int,int>, std::vector<Bug*>> cellMap;

    for (auto bug : bugs) {
        if (!bug->isAlive()) continue;

        auto pos = bug->getPosition();
        cellMap[pos].push_back(bug);
    }

    return cellMap;
}

void Board::tapBoard() {
    if (bugs.empty()) {
        std::cout << "No bugs loaded\n";
        return;
    }

    // Collect alive bugs
    std::vector<Bug *> aliveBugs;
    for (auto bug: bugs) {
        if (bug->isAlive()) {
            aliveBugs.push_back(bug);
        }
    }

    if (aliveBugs.empty()) {
        std::cout << "No alive bugs\n";
        return;
    }

    // Pick one bug to freeze
    int freezeIndex = rand() % aliveBugs.size();
    Bug *frozenBug = aliveBugs[freezeIndex];

    std::cout << "Frozen bug ID: " << frozenBug->getId() << "\n";

    // Move all others
    for (auto bug: bugs) {
        if (!bug->isAlive()) continue;
        if (bug == frozenBug) continue;

        bug->move();
    }
    resolveFights();
    std::cout << "Tap complete - bugs have moved \n";
}

void Board::clear() {
    for (auto bug : bugs) {
        delete bug;
    }
    bugs.clear();
}

void Board::loadFromFile(const std::string& filename) {
    clear();

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;

        // Read type
        std::getline(ss, token, ';');
        char type = token[0];

        // Read common fields
        std::getline(ss, token, ';');
        int id = std::stoi(token);

        std::getline(ss, token, ';');
        int x = std::stoi(token);

        std::getline(ss, token, ';');
        int y = std::stoi(token);

        std::getline(ss, token, ';');
        Direction dir = static_cast<Direction>(std::stoi(token));

        std::getline(ss, token, ';');
        int health = std::stoi(token);

        if (type == 'C') {
            bugs.push_back(new Crawler(id, x, y, dir, health));
        }
        else if (type == 'H') {
            std::getline(ss, token, ';');
            int hopLength = std::stoi(token);

            bugs.push_back(new Hopper(id, x, y, dir, health, hopLength));
        }
        else if (type == 'T') {
            bugs.push_back(new Teleporter(id, x, y, dir, health));
        }
    }

    std::cout << "Loaded " << bugs.size() << " bugs\n";
}

void Board::displayAllBugs() const {
    if (bugs.empty()) {
        std::cout << "No bugs loaded\n";
        return;
    }

    for (const auto &bug: bugs) {
        std::cout << "ID: " << bug->getId()
                << " | Type: " << bug->getType()
                << " | Pos: (" << bug->getPosition().first << ", "
                << bug->getPosition().second << ")"
                << " | Dir: " << directionToString(bug->getDirection())
                << " | Health: " << bug->getHealth()
                << " | Status: ";
                if (bug->isAlive()) {
                    std::cout << "Alive";
                } else {
                    std::cout << "Eaten by " << bug->getKillerId();
                }

        const Hopper* hopper = dynamic_cast<const Hopper*>(bug);
        if (hopper) {
            std::cout << " | Hop: " << hopper->getHopLength();
        }

        std::cout << "\n";
    }
}

void Board::findBugById(int id) const {
    for (const auto& bug : bugs) {
        if (bug->getId() == id) {
            std::cout << "Bug found:\n";
            std::cout << "  ID: " << bug->getId() << "\n";
            std::cout << "  Type: " << bug->getType() << "\n";
            std::cout << "  Position: ("
                      << bug->getPosition().first << ", "
                      << bug->getPosition().second << ")\n";
            std::cout << "  Direction: "
                      << directionToString(bug->getDirection()) << "\n";
            std::cout << "  Health: " << bug->getHealth() << "\n";
            std::cout << "  Status: "
                      << (bug->isAlive() ? "Alive" : "Dead") << "\n";
            return;
        }
    }

    std::cout << "Bug with ID " << id << " not found\n";
}
void Board::displayCells() const {
    if (bugs.empty()) {
        std::cout << "No bugs loaded\n";
        return;
    }

    auto cellMap = buildCellMap();

    std::cout << "\nBoard:\n\n";

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {

            std::pair<int,int> cell = {x, y};

            if (cellMap.find(cell) == cellMap.end()) {
                std::cout << "[   ]";
            } else {
                const auto& bugsInCell = cellMap[cell];

                std::string type = bugsInCell[0]->getType();
                int id = bugsInCell[0]->getId();

                char symbol = type[0]; // C, H, T

                std::cout << "[" << symbol << id << "]";
            }
        }
        std::cout << "\n";
    }
}

void Board::resolveFights() {
    auto cellMap = buildCellMap();

    std::random_device rd;
    std::mt19937 g(rd());

    for (auto &[cell, bugsInCell]: cellMap) {
        if (bugsInCell.size() < 2) continue;

        std::cout << "\nFight at (" << cell.first << "," << cell.second << ")\n";

        // Shuffle bugs
        std::shuffle(bugsInCell.begin(), bugsInCell.end(), g);

        // Pair them
        for (size_t i = 0; i + 1 < bugsInCell.size(); i += 2) {
            Bug *b1 = bugsInCell[i];
            Bug *b2 = bugsInCell[i + 1];

            std::cout << "  " << b1->getId()
                    << " vs " << b2->getId() << "\n";

            // fighting rounds
            for (int r = 0; r < 3; r++) {

                int dmg1 = rand() % 6;
                int dmg2 = rand() % 6;

                b1->takeDamage(dmg2);
                b2->takeDamage(dmg1);

                bool b1Dead = !b1->isAlive();
                bool b2Dead = !b2->isAlive();

                if (b1Dead && b2Dead) {
                    b1->setKiller(b2->getId());
                    b2->setKiller(b1->getId());
                    break;
                }

                if (b1Dead) {
                    b1->setKiller(b2->getId());
                    break;
                }

                if (b2Dead) {
                    b2->setKiller(b1->getId());
                    break;
                }
            }
        }
    }
}

void Board::testDeadBehavior() {
    if (bugs.empty()) {
        std::cout << "No bugs loaded\n";
        return;
    }

    // Pick first bug and kill it
    Bug *deadBug = bugs[0];
    deadBug->takeDamage(999); // guaranteed death

    std::cout << "Killed bug ID: " << deadBug->getId() << "\n";

    auto before = deadBug->getPosition();

    // Tap board (movement + fights)
    tapBoard();

    auto after = deadBug->getPosition();

    std::cout << "Position before: (" << before.first << "," << before.second << ")\n";
    std::cout << "Position after : (" << after.first << "," << after.second << ")\n";

    if (before == after) {
        std::cout << "Dead bug did NOT move \n";
    } else {
        std::cout << "ERROR: Dead bug moved \n";
    }

    std::cout << "Dead bug status: "
              << (deadBug->isAlive() ? "Alive" : "Dead") << "\n";
}

void Board::testFights() {
    if (bugs.size() < 3) {
        std::cout << "Need at least 3 bugs\n";
        return;
    }

    // Force several bugs into same cell (3+ for odd case)
    std::pair<int, int> cell = {5, 5};

    int count = 0;
    for (auto bug: bugs) {
        if (bug->isAlive()) {
            bug->setPosition(cell.first, cell.second);
            count++;
            if (count >= 4) break;
        }
    }

    std::cout << "Forced " << count << " bugs into (5,5)\n";

    // Run fights only
    resolveFights();

    // Show result
    displayAllBugs();
}

void Board::displayLifeHistory() const {
    if (bugs.empty()) {
        std::cout << "No bugs loaded\n";
        return;
    }

    std::cout << "\nLife History:\n\n";

    for (const auto& bug : bugs) {
        std::cout << "ID: " << bug->getId()
                  << " | Type: " << bug->getType() << "\n";

        std::cout << "  Path: ";

        const auto& path = bug->getPath();
        for (const auto& pos : path) {
            std::cout << "(" << pos.first << "," << pos.second << ") ";
        }

        std::cout << "\n";

        std::cout << "  Status: ";
        if (bug->isAlive()) {
            std::cout << "Alive";
        } else {
            std::cout << "Eaten by " << bug->getKillerId();
        }

        std::cout << "\n\n";
    }
}
int Board::countAlive() const {
    int count = 0;

    for (auto bug : bugs) {
        if (bug->isAlive()) {
            count++;
        }
    }

    return count;
}

void Board::runSimulation() {
    if (bugs.empty()) {
        std::cout << "No bugs loaded\n";
        return;
    }

    int round = 1;

    while (countAlive() > 1) {

        std::cout << "\n========== Round "
                  << round
                  << " ==========\n";

        tapBoard();
        displayCells();

        std::cout << "\nAlive bugs remaining: "
                  << countAlive()
                  << "\n";

        displayAllBugs();

        std::this_thread::sleep_for(
            std::chrono::seconds(1)
        );

        round++;
    }

    std::cout << "\nSimulation complete\n";

    for (auto bug : bugs) {
        if (bug->isAlive()) {
            std::cout << "Last Bug Standing: "
                      << bug->getId()
                      << " ("
                      << bug->getType()
                      << ")\n";
        }
    }
}