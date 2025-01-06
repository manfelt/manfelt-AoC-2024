#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file;
	char line[1000];
	int sum = 0;
	int i = 1;
	int distance;

	struct ab{
		int a;
		int b;
	};

	struct ab list[sizeof(line)];
	

	file = fopen("1_input.txt", "r");

	if (file == NULL) {
		printf("Error opening file %s \n", file);
		return 1;
	}

	while (fgets(line, sizeof(line), file) 	!= NULL) {
		list[i].a = atoi(strtok(line, " ")); 
		list[i].b = atoi(strtok(NULL, "\n"));
		distance = abs(list[i].a - list[i].b);
		sum += distance;
		printf("# %d, a %d b %d, distance %d, sum  %d \n",i,list[i].a,list[i].b,distance, sum);
		i++;
		/* printf("%d \n",i); */

	}	
	
	fclose(file);

	printf("\n ANSWER: %d \n", sum);



	return 0;
}
