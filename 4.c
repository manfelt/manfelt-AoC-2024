#include <stdio.h>
#include <string.h>

#define SIZE 1000

FILE *f;
char line[SIZE];

int r(void) {
	printf("fdds");
	if (1) {
		printf("true");
	} else printf("false");
}


int main (void) {

	f = fopen("4_input.txt", "r");

	if (f == NULL) {
		printf("Error opening file %p \n", f);
		return 1;
	}	


	while (fgets(line, SIZE, f) != NULL) {
		int rowlen = strlen(line);
		int cur = 0;

		while (cur<rowlen) {
			//printf("%c",line[cur]);

			cur++;
		
		}

	}

	// TODO reversj


	return 0;
}
