#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000
#define X 140
#define Y 140

FILE *f;
char line[SIZE], matrix[X][Y];
int res;


struct diagonal_mem {
	int x; 

};

int verify(char in, int pre) {
	if(pre > 4) {pre = 0;}

	int flag_lvl = pre;

	switch (in)	{
		case 88:
			flag_lvl = 1;
			break;
		case 77:
			if (flag_lvl != 1) {
				flag_lvl = 0;
			} else {
				flag_lvl++;
			}
			break;
		case 65:
			if (flag_lvl != 2) {
				flag_lvl = 0;
			} else {
				flag_lvl++;
			}
			break;
		case 83:
			if (flag_lvl != 3) {
				flag_lvl = 0;
			} else {
				flag_lvl++;
			}
			break;
	}
	return flag_lvl;
}

int verify_reverse(char in, int pre) {
	if(pre > 4) {pre = 0;}

	int flag_lvl = pre;

	switch (in)	{
		case 83:
			flag_lvl = 1;
			break;
		case 65:
			if (flag_lvl != 1) {
				flag_lvl = 0;
			} else {
				flag_lvl++;
			}
			break;
		case 77:
			if (flag_lvl != 2) {
				flag_lvl = 0;
			} else {
				flag_lvl++;
			}
			break;
		case 88:
			if (flag_lvl != 3) {
				flag_lvl = 0;
			} else {
				flag_lvl++;
			}
			break;
	}
	return flag_lvl;
}

int scan_horizontal(char mat[][Y], int n) {
	printf("horizontal scan from y position: %i",n);
	int flag = 0;
	int result = 0;

	for(int i=0;i<Y;i++) {
		printf("%c \n",mat[i][n]);
		flag = verify(mat[i][n],flag);
		if (flag == 4) {
			printf("FLAG %i \n",flag);
			result++;

		}
	}
	return result;	
}

int scan_vertical(char mat[][Y], int n) {
	printf("vertical scan from x position: %i",n);
	int flag = 0;
	int result = 0;

	for(int i=0;i<Y;i++) {
		printf("%c \n",mat[n][i]);
		flag = verify(mat[n][i],flag);
		if (flag == 4) {
			printf("FLAG %i \n",flag);
			result++;
		}
	}
	return result;	
}

int scan_up_left_diag(char mat[][Y], int x, int y) {
	printf("from upper left to lower right: \n");
	int flag = 0;
	int result = 0;
	int n;
	if (x > y) {
		n = X-x;
	} else {n = Y-y;} 

	if (n > 3) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
			//	printf("%c,",mat[i][j]);

				if((i+x)==(j+y)) {
					printf("*%c *,\n ",mat[i][j]);
				}
			}
		}
	}
	return result;
}

void printPrincipalDiagonal(char mat[][Y], int n) {
	printf("Principal Diagonal: \n");

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i==j) {
				printf("%i , ",mat[i][j]);
			}
		}
	}
}


int main (void) {

	// X 88 
	// M 77
	// A 65
	// S 83

	/* 
	   |0|1|2|..|140|x
	   |1|
	   |2|
	   |..|
	   |140|
	   y
	   */

	int i = 0;

	f = fopen("4_input.txt", "r");

	if (f == NULL) {
		printf("Error opening file %p \n", f);
		return 1;
	}	


	while (fgets(line, SIZE, f) != NULL) {

		// populate array matrix from file buffer.
		for (int j=0;j<X;j++) {
			matrix[j][i] = line[j];
		}
		i++;
	}

	char *a;
	a = malloc(1 * sizeof(char));

//	printPrincipalDiagonal(matrix,Y);

//	scan_horizontal(matrix,1);	

	scan_up_left_diag(matrix,0,1);


	return 0;
}
