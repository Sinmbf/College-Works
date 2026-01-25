//largest & smallest using DMA function
#include<stdio.h>
#include<stdlib.h>
void read(int *,int);
void sort(int *,int *,int *,int);
void main()
{
	int n,*p,s,l;
	printf("Enter no. of integers : ");
	scanf("%d",&n);
	p=(int *)malloc(sizeof(int)*n);
	if(p==NULL)
	{
		printf("Memory allocation failed.");
		exit(0);
	}
	printf("Enter %d integers : ",n);
	read(p,n);
	sort(p,&l,&s,n);
	printf("\nLargest = %d\nSmallest = %d",l,s);
	free(p);
}
void read(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",p+i);
}
void sort(int *p,int *l,int *s,int n)
{
	int i;
	*l=*s=*p;
	printf("\n%d\n%d\n%d\n",*l,*s,*p);
	for(i=1;i<n;i++)
	{
		if(*(p+i)>*l)
			*l=*(p+i);
		if(*(p+i)<*s)
			*s=*(p+i);			
	}
}

