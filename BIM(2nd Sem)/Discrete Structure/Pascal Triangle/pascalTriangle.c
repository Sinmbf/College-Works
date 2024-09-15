// WAP to print Pascal's Triangle

#include<stdio.h>

void printPascal(int n){
<<<<<<< HEAD
	for(int line=1;line<=n;line++){
		for(int space =1; space <=n-line;space++){
=======
	int line,i,space;
	for(line=1;line<=n;line++){
		for(space =1; space <=n-line;space++){
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
			printf("  ");
		}
		// used to represent C(line,i)
		int coef=1;
<<<<<<< HEAD
		for(int i=1;i<=line;i++){
=======
		for(i=1;i<=line;i++){
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
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
<<<<<<< HEAD
}
=======
}
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
