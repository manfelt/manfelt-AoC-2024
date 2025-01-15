#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(void) {
        FILE *f;
        char line[SIZE], *p, h[1];
        int sum = 0;
        int i = 1;
        int a, b, j, k;

        f = fopen("2_input.txt", "r");

        if (f == NULL) {
                printf("Error opening file %p \n", f);
                return 1;
        }


        while (fgets(line, SIZE, f) != NULL && i <= 4) {
                a = atoi(strtok(line, " "));
                for (j= 0;j <= 6; j++){
                        p = strtok(NULL, " ");
                        if (p) {
                                strcpy(h,p);
                                b = atoi(h);
                                printf("%d\n",b);
                        } else {
                                break;
                        }
                }
                i++;
        }
        fclose(f);
        printf("amongus %d \n", SIZE);

        /* printf("\n ANSWER: %d \n", sum); */

        return 0;
}
