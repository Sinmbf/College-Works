//Shiv to Vola & Krishna to Shyam in sample.txt
#include <stdio.h>
#include <string.h>
void main()
{
    FILE *fp1, *fp2;
    char s[100];
    int err;
    fp1 = fopen("sample.txt","r");
    fp2 = fopen("temp.txt","w");
    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening files.\n");
        return;
    }
    while(fscanf(fp1,"%s",s)!=EOF)
    {
    	printf("%s",s);
        if (strcmp(s,"Shiv")==0)
            strcpy(s,"Vola");
        if (strcmp(s,"Krishna")==0)
            strcpy(s,"Shyam");
        fprintf(fp2,"%s ",s);
    }
    fclose(fp2);
    fclose(fp1);
    err = remove("sample.txt");
    if (err!=0)
        printf("Delete error.");
    err = rename("temp.txt","sample.txt");
    if (err!=0)
        printf("Rename error.");
    else
        printf("File updated successfully.");
}
