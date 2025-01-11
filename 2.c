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

	/* dynamic array */
	typedef struct {
		int *array;
		size_t used;
		size_t size;
	} Array;

	void initArray(Array *a, size_t initialSize) {
		a->array = malloc(initialSize * sizeof(int));
		a->used = 0;
		a->size = initialSize;		
	}

	void insertArray(Array *a, int element) {
		
	}

	f = fopen("2_input.txt", "r");

	if (f == NULL) {
		printf("Error opening file %p \n", f);
		return 1;
	}


	while (fgets(line, SIZE, f) != NULL && i <= 4) {
		list[i].a = atoi(strtok(line, " ")); 
		list[i].b = atoi(strtok(NULL, " "));
		if(list[i].b != NULL) {printf("%d \n",list[i].b);} 
		i++;
		/*printf("%d \n", list[i].a);*/
		/* printf("%s \n",line);*/
	}		
	fclose(f);
	printf("amongus %d \n", SIZE);

	/* printf("\n ANSWER: %d \n", sum); */

	return 0;
}
