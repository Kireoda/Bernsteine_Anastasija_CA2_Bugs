#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Crawler.h"
#include "Hopper.h"
#include "Direction.h"
#include "Board.h"

void printCrawlerState(int step, const Crawler& c) {
    std::cout << "Step " << step << "\n";
    std::cout << "  Position: ("
              << c.getPosition().first << ", "
              << c.getPosition().second << ")\n";
    std::cout << "  Direction: "
              << directionToString(c.getDirection()) << "\n\n";
}

void printHopperState(int step, const Hopper& h) {
    std::cout << "Step " << step << "\n";
    std::cout << "  Position: ("
              << h.getPosition().first << ", "
              << h.getPosition().second << ")\n";
    std::cout << "  Direction: "
              << directionToString(h.getDirection()) << "\n";
    std::cout << "  Hop Length: "
              << h.getHopLength() << "\n\n";
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // -------- CRAWLER TEST --------
    Crawler crawler(101, 0, 0, Direction::North, 10);

    std::cout << "Crawler initial state\n";
    std::cout << "  Position: ("
              << crawler.getPosition().first << ", "
              << crawler.getPosition().second << ")\n";
    std::cout << "  Direction: "
              << directionToString(crawler.getDirection()) << "\n\n";

    for (int i = 1; i <= 10; i++) {
        crawler.move();
        printCrawlerState(i, crawler);
    }

    std::cout << "Crawler path history\n";
    int i = 0;
    for (const auto& pos : crawler.getPath()) {
        std::cout << "  " << i++
                  << ": (" << pos.first << ", " << pos.second << ")\n";
    }

    // -------- HOPPER TEST --------
    std::cout << "\nHopper test\n\n";

    Hopper hopper(201, 5, 5, Direction::East, 10, 3);

    std::cout << "Hopper initial state\n";
    std::cout << "  Position: ("
              << hopper.getPosition().first << ", "
              << hopper.getPosition().second << ")\n";
    std::cout << "  Direction: "
              << directionToString(hopper.getDirection()) << "\n";
    std::cout << "  Hop Length: "
              << hopper.getHopLength() << "\n\n";

    for (int j = 1; j <= 5; j++) {
        hopper.move();
        printHopperState(j, hopper);
    }

    std::cout << "Hopper path history\n";
    int k = 0;
    for (const auto& pos : hopper.getPath()) {
        std::cout << "  " << k++
                  << ": (" << pos.first << ", " << pos.second << ")\n";
    }

    // -------- BOARD TEST --------
    std::cout << "\nBoard load test\n\n";

    Board board;
    board.loadFromFile("../data/bugs.txt");

    std::cout << "\nAll bugs:\n";
    board.displayAllBugs();

    return 0;
}