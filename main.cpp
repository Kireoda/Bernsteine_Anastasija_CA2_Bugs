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

void showMenu() {
    std::cout << "\nMenu\n";
    std::cout << "1. Initialize board\n";
    std::cout << "2. Display all bugs\n";
    std::cout << "3. Find a bug\n";
    std::cout << "4. Tap board\n";
    std::cout << "5. Life history\n";
    std::cout << "6. Display all cells\n";
    std::cout << "7. Run simulation\n";
    std::cout << "8. Exit\n";
    std::cout << "9. Test crawler\n";
    std::cout << "10. Test hopper\n";
    std::cout << "11. Test fights\n";
    std::cout << "12. Test dead bug behaviour\n";
    std::cout << "Choose option: ";
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Board board;
    int choice;

    do {
        showMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input\n";
            continue;
        }

        switch (choice) {

            case 1:
                board.loadFromFile("../data/bugs.txt");
                break;

            case 2:
                std::cout << "\n";
                board.displayAllBugs();
                break;

            case 3: {
                int id;
                std::cout << "Enter bug ID: ";
                std::cin >> id;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Invalid ID\n";
                    break;
                }
                board.findBugById(id);
                break;
            }

            case 4:
                board.tapBoard();
                break;

            case 5:
                board.displayLifeHistory();
                break;

            case 6:
                board.displayCells();
                break;

            case 7:
                board.runSimulation();
                break;

            case 8:
                board.writeLifeHistoryToFile();
                std::cout << "Exiting...\n";
                break;

            case 9: {
                std::cout << "\nCrawler test\n\n";

                Crawler crawler(101, 0, 0, Direction::North, 10);

                for (int i = 1; i <= 10; i++) {
                    crawler.move();
                    printCrawlerState(i, crawler);
                }

                std::cout << "Path:\n";
                int i = 0;
                for (const auto& pos : crawler.getPath()) {
                    std::cout << "  " << i++
                              << ": (" << pos.first << ", " << pos.second << ")\n";
                }
                break;
            }

            case 10: {
                std::cout << "\nHopper test\n\n";

                Hopper hopper(201, 5, 5, Direction::East, 10, 3);

                for (int i = 1; i <= 5; i++) {
                    hopper.move();
                    printHopperState(i, hopper);
                }

                std::cout << "Path:\n";
                int i = 0;
                for (const auto& pos : hopper.getPath()) {
                    std::cout << "  " << i++
                              << ": (" << pos.first << ", " << pos.second << ")\n";
                }
                break;
            }
            case 11:
                board.testFights();
                break;

            case 12:
                board.testDeadBehavior();
                break;

            default:
                std::cout << "Invalid option\n";
        }

    } while (choice != 8);

    return 0;
}