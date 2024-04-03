#include <stdio.h>

// Function to print a horizontal line
void printHorizontalLine(int width) {
	int i;
    for (i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

// Function to print a vertical line
void printVerticalLine(int width) {
	int i;
    for (i = 0; i < width; i++) {
        printf("|");
    }
    printf("\n");
}

// Function to print a row of data
void printRow(int id, char *name, int age, int widths[]) {
    printf("| %-*d | %-*s | %-*d |\n", widths[0], id, widths[1], name, widths[2], age);
}

int main() {
    // Sample data
    int ids[] = {1, 2, 3, 4};
    char names[][20] = {"John", "Alice", "Bob", "Emily"};
    int ages[] = {25, 30, 28, 35};
    int i,num_records = sizeof(ids) / sizeof(ids[0]);

    // Calculate column widths
    int widths[] = {4, 20, 4}; // Adjust column widths as needed

    // Print table header
    printHorizontalLine(widths[0] + widths[1] + widths[2] + 7);
    printf("| ID   | Name                 | Age  |\n");
    printHorizontalLine(widths[0] + widths[1] + widths[2] + 7);

    // Print data rows
    for (i = 0; i < num_records; i++) {
        printRow(ids[i], names[i], ages[i], widths);
        if (i < num_records - 1) {
            printHorizontalLine(widths[0] + widths[1] + widths[2] + 7);
        }
    }

    return 0;
}

