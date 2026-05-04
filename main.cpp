#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Crawler.h"
#include "Direction.h"

void printState(int step, const Crawler& c) {
    std::cout << "Step " << step << "\n";
    std::cout << "  Position: ("
              << c.getPosition().first << ", "
              << c.getPosition().second << ")\n";
    std::cout << "  Direction: "
              << directionToString(c.getDirection()) << "\n\n";
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Crawler crawler(101, 0, 0, Direction::North, 10);

    std::cout << "Initial state\n";
    std::cout << "  Position: ("
              << crawler.getPosition().first << ", "
              << crawler.getPosition().second << ")\n";
    std::cout << "  Direction: "
              << directionToString(crawler.getDirection()) << "\n\n";

    // Movement test
    for (int i = 1; i <= 10; i++) {
        crawler.move();
        printState(i, crawler);
    }

    // Path history
    std::cout << "Path history\n";
    int i = 0;
    for (const auto& pos : crawler.getPath()) {
        std::cout << "  " << i++
                  << ": (" << pos.first << ", " << pos.second << ")\n";
    }

    // Edge test
    std::cout << "\nEdge test (start at (0,0), facing North)\n\n";

    Crawler edgeCrawler(102, 0, 0, Direction::North, 10);

    for (int i = 1; i <= 5; i++) {
        edgeCrawler.move();
        printState(i, edgeCrawler);
    }

    return 0;
}