#include <iostream>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h> // For Windows-specific Sleep
#else
#include <unistd.h> // For Unix-like systems usleep()
#endif

using namespace std;

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;
const int NUM_COLUMNS = 80;
const int NUM_ROWS = 25;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayMatrixRain() {
    // Array to hold the characters in each column
    char columns[NUM_COLUMNS][NUM_ROWS];

    // Initialize the columns with random characters
    for (int col = 0; col < NUM_COLUMNS; ++col) {
        for (int row = 0; row < NUM_ROWS; ++row) {
            columns[col][row] = ' ';
        }
    }

    // Main loop to display the matrix rain
    while (true) {
        // Update each column
        for (int col = 0; col < NUM_COLUMNS; ++col) {
            int new_row = rand() % NUM_ROWS;
            columns[col][new_row] = static_cast<char>(rand() % 256);
            if (new_row > 0) {
                columns[col][new_row - 1] = ' ';
            } else {
                columns[col][NUM_ROWS - 1] = ' ';
            }
        }

        // Display each column
        for (int row = 0; row < NUM_ROWS; ++row) {
            for (int col = 0; col < NUM_COLUMNS; ++col) {
                // Set color for green text on black background
                if (row > 0) {
                    cout << "\033[32m"; // Green text
                } else {
                    cout << "\033[0m"; // Reset text color
                }
                cout << columns[col][row];
            }
            cout << endl;
        }

        // Slow down the loop to control the speed of falling characters
#ifdef _WIN32
        Sleep(50); // Windows Sleep in milliseconds
#else
        usleep(50000); // Unix-like system usleep in microseconds (50 milliseconds)
#endif

        // Clear the screen for the next frame
        clearScreen();
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Display the Matrix rain effect
    displayMatrixRain();

    return 0;
}
