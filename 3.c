#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 1000
#define TOKEN_DEFINE(token, str)

TOKEN_DEFINE("TOKEN_OPAREN", "(")
TOKEN_DEFINE("TOKEN_COMMA",  ",")
TOKEN_DEFINE("TOKEN_CPAREN", ")")
TOKEN_DEFINE("TOKEN_MUL",  "mul")


char next_token() {
        char token;
        /* TODO  unimplemented */

        return token;
}



int main(void) {
        FILE *f;
        char line[SIZE];
        int sum = 0;
        int a, b, cur, bol, row;
        int i = 1;


        f = fopen("3_input.txt", "r");

        if (f == NULL) {
                printf("Error opening file %p \n", f);
                return 1;
        }


        while (fgets(line, SIZE, f) != NULL && i <= 4) {
                a = atoi(strtok(line, " "));





        }
        fclose(f);
        printf("amongus %d \n", SIZE);

        /* printf("\n ANSWER: %d \n", sum); */

        return 0;
}
