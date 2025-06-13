#include <stdio.h>
#include <string.h>

#define SIZE 1000
#define WIDTH 140
#define HEIGHT 140

FILE *f;
char line[SIZE];
int res;


struct diagonal_mem {
	int x; 

};


int scan_horizontal(char *line) {
	int i = 0;
	int result = 0;
	int flag_lvl = 0;
	while (i<WIDTH) {
		switch (line[i])	{
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
					result++;
				}
				break;
		}
		i++;
	}
	return result;
}


void search_diagonals() {}

int main (void) {

	// X 88 
	// M 77
	// A 65
	// S 83


	f = fopen("4_input.txt", "r");

	if (f == NULL) {
		printf("Error opening file %p \n", f);
		return 1;
	}	


	while (fgets(line, SIZE, f) != NULL) {
		int rowlen = strlen(line);
		int cur = 0;

		int bob = scan_horizontal(line);

		printf("\n result: %d", bob);

		while (cur<rowlen) {
			//printf("%c",line[cur]);

			cur++;

		}


		res = cur;


	}
	printf("\n%d",res);

	// TODO reversj


	return 0;
}
