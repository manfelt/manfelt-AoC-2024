#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000


FILE *f;
char line[SIZE];

int main (void) {



	f = fopen("5_input.txt", "r");

	if (f == NULL) {
		printf("Error opening file %p \n", f);
		return 1;
	}	


	while (fgets(line, SIZE, f) != NULL) {


	}

	char *a;
	a = malloc(1 * sizeof(char));



	return 0;
}
