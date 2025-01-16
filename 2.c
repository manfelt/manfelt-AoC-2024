#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(void) {
        FILE *f;
        char line[SIZE], *p, h[1];
        int sum = 0;
        int i = 1;
        int a, b, j, increasing, differ, safe;

        f = fopen("2_input.txt", "r");

        if (f == NULL) {
                printf("Error opening file %p \n", f);
                return 1;
        }


        while (fgets(line, SIZE, f) != NULL && i <= 9) {
                a = atoi(strtok(line, " "));
                printf("\n");
                printf("%d ", a);
                for (j = 0;j <= 7; j++){
                        p = strtok(NULL, " ");
                        if (p) {
                                strcpy(h,p);
                                b = atoi(h);
                                printf("%d ",b);
                                if (j = 0) {
                                        if (a > b && (b - a) <= 3) {
                                                increasing = 0;
                                                printf(" increase ");
                                        } else if (a < b && (a - b) <= 3) {
                                                increasing = 1;
                                                printf(" decrease ");
                                        } else {
                                                safe = 0;
                                        }
                                }
                                a = b;
                                if (!safe) {
                                        sum++;
                                        printf("not safe");
                                        continue;
                                }
                        } else {
                                break;
                        }
                }
                i++;
        }
        fclose(f);
        printf("\namongus %d \n", SIZE);

        /* printf("\n ANSWER: %d \n", sum); */

        return 0;
}
