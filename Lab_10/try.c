#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    char ch;
    int p;
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    // Move to the 10th position
    fseek(file,9,0);
    ch=fgetc(file);
    printf("Character at the 10th position: %c",ch);
    fclose(file);
    return 0;
}

