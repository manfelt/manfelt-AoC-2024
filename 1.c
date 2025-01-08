#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int max = 99999;
	FILE *file;
	char line[1000];
	int sum = 0;
	int i = 1;
	int distance, lowa, lowb, lowest, j, indexa, indexb;

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
	
	lowa = lowb = max;
	printf("lowa:%d \n",lowa);

	for (i = 1; i <= sizeof(line); i++) {
		for (j = 1; j <= sizeof(line); j++) {
			if ( list[j].a <= lowa ) {
				lowa = list[j].a;
				indexa = j;	
			
			}
		}
		for (j = 1; j <= sizeof(line); j++) {
			if ( list[j].b <= lowb ) {
				lowb = list[j].b;
				indexb = j;

			}
		}	
		list[indexa].a = max;
		list[indexb].b = max;

		printf("%d %d\n",lowa, lowb);

		distance = abs(lowa - lowb);
		lowb = lowa = max;
		sum += distance;
	/*	printf("# %d, a %d b %d, distance %d, sum  %d \n",i,list[i].a,list[i].b,distance, sum); */
	}


	printf("\n ANSWER: %d \n", sum);

	return 0;
