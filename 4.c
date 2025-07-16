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
	if(pre >= 4) {pre = 0;}

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
	if(pre >= 4) {pre = 0;}

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
	// 	n: 0 - 139
	//	horizontal scan from n position
	int flag, rev_flag = 0;
	int result = 0;

	for(int i=0;i<Y;i++) {
		//	printf("%c \n",mat[i][n]);
		flag = verify(mat[i][n],flag);
		if (flag >= 4) {
			//		printf("FLAG %i \n",flag);
			result++;
			flag = 0;
		}
		rev_flag = verify_reverse(mat[i][n],rev_flag);
		if (rev_flag >= 4) {
			result++;
			rev_flag = 0;
			//		printf("REV FLAG %i \n",result);
		}
	}
	return result;
}

int scan_vertical(char mat[][Y], int n) {
	// 	n: 0 - 139
	//	vertical scan from n position
	int flag, rev_flag = 0;
	int result = 0;

	for(int i=0;i<Y;i++) {
		//printf("%c \n",mat[n][i]);
		flag = verify(mat[n][i],flag);
		if (flag >= 4) {
			flag = 0;
			result++;
			//	printf("FLAG %i \n",result);
		}
		rev_flag = verify_reverse(mat[n][i],rev_flag);
		if (rev_flag >= 4) {
			rev_flag = 0;
			result++;
			//	printf("REV FLAG %i \n",result);
		}
	}
	return result;
}

int scan_up_left_diag(char mat[][Y], int x, int y) {
	//	x: (0) - (136), y (0) - (136)
	//	from upper left to lower right;
	int flag, rev_flag = 0;
	int result = 0;
	int n = Y;
	//	if (x > y) {
	//		n = X-x;
	//	} else {n = Y-y;}
	printf("\n BEG\n");

	if (n > 3) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				//	printf("%c,",mat[i][j]);
				if((i+x)==(j+y)) {
					printf("n:%i, x/i:%i, y:j%i ",n,j,i);
					printf("*%c *,\n ",mat[j][i]);

					flag = verify(mat[j][i],flag);
					if (flag >= 4) {
						flag = 0;
						result++;
						printf("FLAG %i \n",result);
					}

					rev_flag = verify_reverse(mat[j][i],rev_flag);
					if (rev_flag >= 4) {
						rev_flag = 0;
						result++;
						printf("REV FLAG %i \n",result);
					}
				}
			}
		}
	}
	printf("\n END\n");
	return result;
}

int scan_up_right_diag(char mat[][Y], int x, int y) {
	//	x: (0) - (-136), y (0) - (136)
	//	from upper right to lower left
	int flag, rev_flag = 0;
	int result = 0;
	int n = Y;
	//	if (x > y) {
	//		n = X-x;
	//	} else {n = Y-y;}

	if (n > 3) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				//	printf("%c,",mat[i][j]);
				if(((i+x)+(j+y))==(n-1)) {
					printf("n:%i, x/i:%i, y/j:%i ",n,i,j);
					printf("*%c *,\n ",mat[i][j]);

					flag = verify(mat[i][j],flag);
					if (flag >= 4) {
						flag = 0;
						result++;
						printf("FLAG %i \n",result);
					}

					rev_flag = verify_reverse(mat[i][j],rev_flag);
					if (rev_flag >= 4) {
						rev_flag = 0;
						result++;
						printf("REV FLAG %i \n",result);
					}
				}
			}
		}
	}
	return result;
}

int main_search(char matrix[][Y]) {
	int result = 0;
	int i = 0;

	while (i<139) {
		result += scan_vertical(matrix,i);
		result += scan_horizontal(matrix,i);
		i++;
	}

	i = -136;

	while (i<136) {
		result += scan_up_right_diag(matrix,i,0);
		i++;
	}

	i = 0;

	while (i<136) {
		result += scan_up_left_diag(matrix,i,0);
		i++;
	}

	i = 1;

	while (i<136) {
		result += scan_up_left_diag(matrix,0,i);
		i++;
	}

	return result;
}

int main (void) {

	// X 88
	// M 77
	// A 65
	// S 83

	/*
	 *   |0|1|2|..|140|x
	 *   |1|
	 *   |2|
	 *   |..|
	 *   |140|
	 *   y
	 */

	int j = 0;

	f = fopen("4_input.txt", "r");

	if (f == NULL) {
		printf("Error opening file %p \n", f);
		return 1;
	}


	while (fgets(line, SIZE, f) != NULL) {

		// populate array matrix from file buffer.
		for (int i=0;i<X;i++) {
			matrix[i][j] = line[i];
		}
		j++;
	}

	char *a;
	a = malloc(1 * sizeof(char));


	int result = 0;
	result = main_search(matrix);
	printf("\n%i\n",result);

	return 0;
}
