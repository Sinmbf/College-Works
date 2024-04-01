#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fptr;
    char str[50], str1[50];
    int num, num1,p;

    fptr = fopen("file6.txt", "wb+");
    if (fptr == NULL) {
        printf("Error opening file6.txt");
        exit(1);
    }

    // Reading from the standard input (keyboard)
    printf("Enter a line of text: ");
    fgets(str,sizeof(str),stdin);
    
    printf("Enter an integer: ");
    scanf("%d", &num);
	// Writing into the file
    fprintf(fptr, "%s%d", str, num);
    
    // Reset the file pointer
    rewind(fptr);
    
    // Read from the file
    fscanf(fptr,"%[^\n]%d",str1,&num1);
    // Display in console
    printf("%s\n%d",str1,num1);

    // Close the file
    fclose(fptr);

    return 0;
}

