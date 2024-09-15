// WAP to display the truth table of p^q, pvq and p-->q.

#include<stdio.h>
int And(int p, int n){
	if(p==1 && q==1){
		return 1;
	}
	return 0;
}

int Or(int p, int q){
	if(p==1 || q==1){
		return 1;
	}
	return 0;
}

int implication(int p, int q){
	if(p==1 && q==0){
		return 0;
	}
	return 1;
}

void main(){
	int p,q;
	// For AND
	printf("Truth table for AND:\n");
	printf("p\t q\t p^q\n")
	for(p=0;p<=1;p++){
		for(q=0;q<=q;q++){
			printf("%d\t %d\t %d\n",p,q,And(p,q));
		}
	}
	// For OR
	printf("\nTrutn table for OR:\n");
	printf("p\t q\t pVq\n");
	for(p=0;p<=1;p++){
		for(q=0;q<=1;q++){
			printf("%d\t %d\t %d\n",p,q,Or(p,q));
		}
	}
	// For Implication
	printf("\nTruth table for implication:\n");
	printf("p\t q\t p-->q\n");
	for(p=0;p<=1;p++){
		for(q=0;q<=1;q++){
			printf("%d\t %d\t %d\n",p,q,implication(p,q));
		}
	}
}

