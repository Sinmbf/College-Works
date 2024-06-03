#include<stdio.h>
#include<string.h>
struct student {
	int roll;
	char name[20];
	int marks[5];
	int total;
} std[5];
void main() {
	struct student temp;
	char s_name[5][20]= {"C","English","Math","Management","Sanskrit"};
	int count,i,j,max,sum=0;
	float percentage,avg[5],avg1;
	for(i=0; i<5; i++) {
		printf("Name of Student %d:",i+1);
		fflush(stdin);
		gets(std[i].name);
		printf("Roll No. of %s:",std[i].name);
		scanf("%d",&std[i].roll);
	}
	for(i=0; i<5; i++) {
		printf("Enter marks Of %s in 5 subjects:\n",std[i].name);
		for(j=0; j<5; j++) {
			printf("In %s: ",s_name[j]);
			scanf("%d",&std[i].marks[j]);
		}
	}
	printf("Roll\tName\t\tC\t\tEnglish\t\tMaths\t\tManagement\tSanskrit\t");
	for(i=0; i<5; i++) {
		printf("\n%d\t%s",std[i].roll,std[i].name);
		for(j=0; j<5; j++) {
			printf("\t\t%d",std[i].marks[j]);
		}
		printf("\n");
	}
	for(i=0; i<5; i++) {
		for(j=0; j<5; j++) {
			std[i].total+=std[i].marks[j];
		}
	}
	printf("\nTotal marks:\n");
	for(i=0; i<5; i++) {
		printf(" \nOf %s:",std[i].name);
		printf("%d",std[i].total);
	}
	for(i=0; i<5; i++) {
		for(j=i+1; j<5; j++) {
			if(std[i].total<std[j].total) {
				temp=std[i];// helps to store entire details of student
				std[i]=std[j];
				std[j]=temp;
			}
		}
	}
	printf("\nTable arrange in Descending order:\n");
	printf("Roll\tName\t\tC\t\tEnglish\t\tMaths\t\tManagement\tSanskrit\t");
	for(i=0; i<5; i++) {
		printf("\n%d\t%s",std[i].roll,std[i].name);
		for(j=0; j<5; j++) {
			printf("\t\t%d",std[i].marks[j]);
		}
		printf("\n");
	}
	printf("Average marks of entire student:\n");
	for(i=0; i<5; i++) {
		avg[i]=(float)std[i].total/5;
		printf("\nAverage marks of %s is %.2f",std[i].name,avg[i]);

	}
	printf("\nPercentage of Nabaraj Panday:\n");
	percentage=(float)std[1].total/500*100;
	printf("%.2f is the percentage\n",percentage);
	printf("\nName of the topper");
	max=std[0].total;
	for(i=0; i<5; i++) {
		if(max<std[i].total) {
			max=std[i].total;
			count=i;
		}
	}
	printf("\n%s",std[count].name);
	printf("\nAverage marks in C programming\n");
	for(i=0; i<5; i++) {
		sum+=std[i].marks[0];
	}
	avg1=(float)sum/5;
	printf("%.2f",avg1);
}
