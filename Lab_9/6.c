// 6. Create a structure named Date having day, month and year as its members. Store the
// current date in the structure. Now add 45 days to the current date and display the final
// date.

#include<stdio.h>

struct Date {
	int day;
	int month;
	int year;
} d1;

void main() {
	printf("Enter current date:\n");
	printf("Year: ");
	scanf("%d",&d1.year);
	printf("Month: ");
	scanf("%d",&d1.month);
	printf("Day: ");
	scanf("%d",&d1.day);
	d1.day+=45;
	while(d1.day>30){
		d1.month++;
		d1.day-=30;
	}		
//	printf("New Date:\nYear: %d\nMonth: %d\nDay: %d\n",d1.year,d1.month,d1.day);
	printf("%d/%d/%d",d1.year,d1.month,d1.day);
}
