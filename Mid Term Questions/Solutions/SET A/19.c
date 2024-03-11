// 19. WAP to input marks of five subjects. Calculate percentage and display the grade according
// to the following:

/*

	Percentage >= 90% : Grade A
	Percentage >= 80% : Grade B
	Percentage >= 70% : Grade C
	Percentage >= 60% : Grade D
	Percentage >= 40% : Grade E
	Percentage <  40% : Grade F
	
*/

#include<stdio.h>

void main(){
	int a[5],i,marks_obtained=0;
	float percentage;
	printf("Enter marks in 5 subjects: ");
	// Take input marks in 5 subjects
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		// Calculate total marks obtained
		marks_obtained+=a[i];
	}
	// Calculate percentage (Assume total marks of all subjects is 100 i.e. 5 subjects = 500)
	percentage=((float)marks_obtained/500)*100; 
	printf("Percentage Obtained: %.2f%%\n",percentage);
	if(percentage>=90){
		printf("Grade: A");
	}
	else if(percentage>=80){
		printf("Grade: B");
	}
	else if(percentage>=70){
		printf("Grade: C");
	}
	else if(percentage>=60){
		printf("Grade: D");
	}
	else if(percentage>=40){
		printf("Grade: E");
	}
	else{
		printf("Grade: F");
	}
}
