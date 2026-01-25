#include<stdio.h>
#include<math.h>

void main() {
	int a,b,c;
	float discriminant,root1,root2,real_part,real_part2,initial_imaginary_part,imaginary_part1,imaginary_part2;
	printf("Enter the coefficient of x square: ");
	scanf("%d",&a);
	if(a==0){
		printf("The coefficient of \'a' must not equal zero!");
		return;
	}
	printf("Enter the coefficient of x: ");
	scanf("%d",&b);
	printf("Enter the value of constant: ");
	scanf("%d",&c);
	discriminant=pow(b,2)-4*a*c;
	if(discriminant>0) {
		root1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
		root2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
		printf("Root 1 = %g\n",root1);
		printf("Root 2 = %g\n",root2);
	}
	else{
		real_part=(float)-b/(2*a);
		initial_imaginary_part=pow(b,2)-4*a*c;
		imaginary_part1=sqrt(initial_imaginary_part*-1)/(2*a);
		imaginary_part2=-sqrt(initial_imaginary_part*-1)/(2*a);
		printf("Imaginary Roots: \nRoot 1 = %g%+gi\nRoot 2 = %g%+gi\n",real_part,imaginary_part1,real_part,imaginary_part2);
	}
}
