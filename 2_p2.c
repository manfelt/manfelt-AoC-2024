#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(void) {
	FILE *f;
	char line[SIZE], *p, h[1];
	int sum = 0;
	int i = 1;
	int a, b, j, inc, dec, differ, safe, *ptr, dmp;

	f = fopen("2_input.txt", "r");

	if (f == NULL) {
		printf("Error opening file %p \n", f);
		return 1;
	}


	while (fgets(line, SIZE, f) != NULL/* && i <= 50*/) {
		printf(" %s", line);
		inc = dec = 0;
		safe = dmp = 1;
		a = atoi(strtok(line, " "));

		for (j = 0;j <= 7; j++) {
			p = strtok(NULL, " ");
			if (p) {
				strcpy(h,p);	
				b = atoi(h);
				/*printf(" %d ", b);*/
				/* printf("a %d ", a); */
				/*if (j = 0) { */
				if (a > b && (a - b) <= 3) {
					if (inc) {
						safe = 0;
					}
					dec = 1;
					/* printf(" - "); */
				} else if (a < b && (b - a ) <= 3) {
					if (dec) {
						safe = 0;
					}
					inc = 1;
					/* printf(" + "); */
				} else {
					safe = 0;
					/* printf(" = "); */
				} 
				/*	}*/
				/* printf("b %d ",b); */
				if (!safe && dmp) {
					safe = 1;
					dmp = 0;
				} else {
					ptr = &b;
					a = *ptr;
				}

				if (!safe /* && !dmp */) {
					sum++;
					/* printf("!!!"); */
					j = 7;
					continue;
				}
				/* printf("|"); */
			} else {
				break;
			}
		}
		printf(" l: %d",i);
		printf(" sum :%d ",sum);
		i++;

	}		
	fclose(f);

	sum = SIZE - sum;

	printf("\n ANSWER: %d \n", sum);

	return 0;
}
