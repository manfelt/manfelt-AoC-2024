#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(void) {
	FILE *f;
	char line[SIZE];
	int sum = 0;
	int i = 1;
	int j, k;

	struct ab{
		int a;
		int b;
	};

	struct ab list[SIZE];


	f = fopen("2_input.txt", "r");

	if (f == NULL) {
		printf("Error opening file %p \n", f);
		return 1;
	}


	while (fgets(line, SIZE, f) != NULL) {
		list[i].a = i; /* atoi(strtok(line, "\n")); */
		list[i].b = i; /* atoi(strtok(NULL, "\n")); */
		i++;
		printf("%d \n",list[i].a);
	}		
	fclose(f);
	printf("amongus %d \n", SIZE);

	/* printf("\n ANSWER: %d \n", sum); */

	return 0;
}
