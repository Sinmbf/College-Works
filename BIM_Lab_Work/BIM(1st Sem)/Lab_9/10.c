// 10. Write a function to add two dates entered by user. Make structure named Date to store
// the elements day, month and year to store the dates. Pass the structure to the function.

#include<stdio.h>

struct Date{
	int day;
	int month;
	int year;
}d[2];

// Function that return a structure
struct Date addDate(struct Date d[]);

void main(){
	struct Date result;
	int i;
	for(i=0;i<2;i++){
		printf("Enter date %d:\n",i+1);
		printf("Year: ");
		scanf("%d",&d[i].year);
		printf("Month: ");
		scanf("%d",&d[i].month);
		printf("Day: ");
		scanf("%d",&d[i].day);
		printf("\n");
	}
	result=addDate(d);
	printf("Result:\nYear: %d\nMonth: %d\nDay: %d\n",result.year,result.month,result.day);
}

struct Date addDate(struct Date d[2]){
	struct Date res;
	res.day=d[0].day+d[1].day;
	res.month=d[0].month+d[1].month;
	res.year=d[0].year+d[1].year;
	if(res.day>31){
		res.day-=31;
		res.month++;
	}
	if(res.month>12){
		res.month-=12;
		res.year++;
	}
	return res;
}
