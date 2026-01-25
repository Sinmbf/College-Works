// WAP to verify the formula for the sum of the first n natural numbers using the mathematical
// induction

#include<stdio.h>

// Function to calculate the sum using the formula
int sumUsingFormula(int n){
	return (n*(n+1))/2;
}

// Function to calculate the sum using iteration
int sumUsingIteration(int n){
	int sum=0,i;
	for(i=1;i<=n;i++){
		sum+=i;
	}
	return sum;
}

void main(){
	int n,sumByFormula,sumByIteration;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	sumByFormula=sumUsingFormula(n);
	sumByIteration=sumUsingIteration(n);
	if(sumByFormula==sumByIteration){
		printf("The formula and iteration yield the same result.Formula is verified");
	}
	else{
		printf("There is a deviation between the formula and iteration. Verification failed");
	}
}