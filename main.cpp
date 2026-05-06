#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Board.h"

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

            default:
                std::cout << "Invalid option\n";
        }

    } while (choice != 8);

    return 0;
}