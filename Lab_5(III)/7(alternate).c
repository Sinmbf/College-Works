// Adding and subtracting both matrix
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			c[i][j]=a[i][j]+b[i][j]; // Add
			d[i][j]=a[i][j]-b[i][j]; // Subtract
		}
	}
	// Display
	printf("Sum:\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("%-4d",c[i][j]);
		}
		printf("\n");
	}
	printf("Difference:\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("%-4d",d[i][j]);
		}
		printf("\n");
	}	
