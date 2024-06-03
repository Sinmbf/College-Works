//Shiv to Vola & Krishna to Shyam in sample.txt
#include <stdio.h>
#include <string.h>
void main()
{
    FILE *fp1;
    char s[100];
    fp1 = fopen("sample.txt","r+");
    if (fp1 == NULL)
    {
        printf("Error opening files.\n");
        return;
    }
    while(fscanf(fp1,"%s",s)!=EOF)
    {
        if (strcmp(s,"Shiv")==0)
            strcpy(s,"Vola");
        if (strcmp(s,"Krishna")==0)
            strcpy(s,"Shyam");
    }
    rewind(fp1);
    fprintf(fp1,"%s",s);
    fclose(fp1);
}
