#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file;
	char line[1000];
	int sum = 0;
	int i = 1;
	int similarity_score, j, k;

	struct ab{
		int a;
		int b;
	};

	struct ab list[sizeof(line)];


	file = fopen("1_input.txt", "r");

	if (file == NULL) {
		printf("Error opening file %p \n", file);
		return 1;
	}

	while (fgets(line, sizeof(line), file) 	!= NULL) {
		list[i].a = atoi(strtok(line, " ")); 
		list[i].b = atoi(strtok(NULL, "\n"));
		i++;
		/* printf("%d \n",i); */

	}		
	fclose(file);


	for (i = 1; i <= sizeof(line); i++) {
		for (j = 1; j <= sizeof(line); j++) {
			if (list[i].a == list[j].b) {
				similarity_score += list[i].a;
			}
			
			for (k = 1; k <= sizeof(line); k++ ) {
			}
		}
		sum += similarity_score;
		similarity_score = 0;
	}


	printf("\n ANSWER: %d \n", sum);

	return 0;
}
