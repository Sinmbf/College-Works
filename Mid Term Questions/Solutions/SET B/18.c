// 18. Create a program in C that calculates the total fare for a bus journey based on the
// distance travelled and the age of the passenger. If the passenger is under 12 years old,
// they pay half fare; if they are over 60 years old, they pay discounted fare. Display the
// total fare accordingly. Assume fare is Rs 10 per kilometer.

#include<stdio.h>

void main() {
	int age,distance;
	float total_fare,discount;
	printf("Enter your age: ");
	scanf("%d",&age);
	printf("How many kilometers did you travel? ");
	scanf("%d",&distance);
	total_fare=10*distance;
	if(age<12) {
		total_fare=0.5*total_fare;  // Half i.e. 1/2 = 0.5
	} 
	else if(age>60) {
		printf("What is the discount percent? ");
		scanf("%f",&discount);
		discount=((float)discount/100)*total_fare;
		total_fare=total_fare-discount;
	}
	printf("Total fare = %.2f",total_fare);
}
