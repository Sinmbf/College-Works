<<<<<<< HEAD
// WAP to find the GCD of two numbers using Euclidean Algorith
=======
// WAP to find the GCD of two numbers using Euclidean Algorithm
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f

#include<stdio.h>
void main(){
	int a,b,x,y,z;
	printf("Enter two numbers: ");
	scanf("%d%d",&a,&b);
	x=a;
	y=b;
	while(y!=0){
		z=x%y;
		x=y;
		y=z;
	}
<<<<<<< HEAD
}
=======
	printf("The GCD of %d and %d is %d\n", a, b, x);
}
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
