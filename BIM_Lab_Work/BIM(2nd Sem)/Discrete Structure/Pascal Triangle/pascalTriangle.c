// WAP to print Pascal's Triangle

#include<stdio.h>

void printPascal(int n){
	int line,i,space;
	for(line=1;line<=n;line++){
		for(space =1; space <=n-line;space++){
			printf("  ");
		}
		// used to represent C(line,i)
		int coef=1;
		for(i=1;i<=line;i++){
			// The first value in a line is always 1
			printf("%4d",coef);
			coef=coef*(line-i)/i;
		}
		printf("\n");
	}
}

// Diver Code
int main(){
	int n=6;
	printPascal(n);
	return 0;
}
