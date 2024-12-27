#include <stdio.h>
#include <stdlib.h>



int main(void){
	/* Essentially calculates the difference between two arrays of an array in absolute value */	

	int arr[2][6] = {
		{3,4,2,1,3,3},
		{4,3,5,3,9,3}
	};



/*	int a = abs(1); */
	size_t n = sizeof(arr) / sizeof(arr[0]);

	int a[] = {};
	int i, j, k;

	printf("Distance: \n");

	/* output each array element's value */
	for ( i = 0; i < 6; i++ ) {
		*(a+i) = abs(arr[0][i] - arr[1][i]);
		/*for ( j = 0; j < 2; j++ ) {
			printf("a[%d][%d] = %d\n", j,i, arr[j][i] );
		} */
	printf("[%d]", a[i]);
	}
	
	printf("\n");

	return 0;
}    
