#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

#include <fstream>
#include <sstream>
#include <iostream>

Board::Board() {}

Board::~Board() {
    clear();
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
    }

    std::cout << "Loaded " << bugs.size() << " bugs\n";
}

void Board::displayAllBugs() const {
    for (const auto& bug : bugs) {
        std::cout << "ID: " << bug->getId()
                  << "  Type: " << bug->getType()
                  << ", Position: (" << bug->getPosition().first << ", "
                  << bug->getPosition().second << ")"
                  << ", Dirction: " << directionToString(bug->getDirection())
                  << ", Health: " << bug->getHealth()
                  << ", Status: " << (bug->isAlive() ? "Alive" : "Dead")
                  << "\n";
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
