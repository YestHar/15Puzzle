#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 4; 

void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << grid[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool isSolved(int grid[SIZE][SIZE]) {
    int counter = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] != counter && !(i == SIZE - 1 && j == SIZE - 1)) {
                return false;
            }
            counter++;
        }
    }
    return true;
}

bool isSolvable(int numbers[]) {
    int inversions = 0;
    for (int i = 0; i < SIZE * SIZE; i++) {
        for (int j = i + 1; j < SIZE * SIZE; j++) {
            if (numbers[i] > numbers[j] && numbers[i] != 0 && numbers[j] != 0) {
                inversions++;
            }
        }
    }
    return inversions % 2 == 0;
}

void initializeGrid(int grid[SIZE][SIZE]) {
    int numbers[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++) {
        numbers[i] = i;
    }

    do {
        for (int i = SIZE * SIZE - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            std::swap(numbers[i], numbers[j]);
        }
    } while (!isSolvable(numbers)); 
    
    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = numbers[index++];
        }
    }
}

void swapValues(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

bool move(int grid[SIZE][SIZE], int direction) {

    int row, col;
    bool found = false;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    switch (direction) {
        case 2:  //down
            if (row > 0) {
                swapValues(grid[row][col], grid[row - 1][col]);
                return true;
            }
            break;
        case 8: //up
            if (row < SIZE - 1) {
                swapValues(grid[row][col], grid[row + 1][col]);
                return true;
            }
            break;
        case 6: //right
            if (col > 0) {
                swapValues(grid[row][col], grid[row][col - 1]);
                return true;
            }
            break;
        case 4: //left
            if (col < SIZE - 1) {
                swapValues(grid[row][col], grid[row][col + 1]);
                return true;
            }
            break;
        default:
            std::cout << "Invalid input. Try again." << std::endl;
            break;
    }
    return false;
}



int main() {
    int puzzle[SIZE][SIZE];
    initializeGrid(puzzle);
    std::cout << "Current Puzzle:" << std::endl;
    printGrid(puzzle);

    while (true) {
        if (isSolved(puzzle)) {
            std::cout << "Congratulations! You solved the puzzle." << std::endl;
            break;
        }

        std::string inputDirection;
        int moveDirection;
        std::cout << "Enter move direction (8: Up, 2: Down, 4: Left, 6: Right): ";
        
        std::cin >> inputDirection;
        
        try {
            moveDirection = std::stoi(inputDirection);
        } catch(...) {
            std::cerr << "Wrong input" << std::endl;
            continue;
        }
        


        if (move(puzzle, moveDirection)) {
            std::cout << "Moved successfully." << std::endl;
            printGrid(puzzle);
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}
