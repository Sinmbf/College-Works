#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();

    // Set line color
    attron(COLOR_PAIR(1));

    // Draw a line
    int x1 = 10, y1 = 10;
    int x2 = 40, y2 = 20;
    for (int x = x1; x <= x2; x++) {
        int y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
        mvaddch(y, x, '*');
    }

    // Refresh the screen
    refresh();

    // Wait for user input
    getch();

    // End ncurses
    endwin();

    return 0;
}

