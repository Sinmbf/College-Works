#include <windows.h>
#include <stdio.h>

// Function to move cursor to specified position
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
	int consoleWidth = 100; // assuming a console width of 80 characters
    int consoleHeight = 24; // assuming a console height of 24 lines

    int middleX = consoleWidth / 2;
    int middleY = consoleHeight / 2;
    // Print some text at position (10, 5)
    gotoxy(middleX, middleY);
    printf("Hello, world!");

    return 0;
}

