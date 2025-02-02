#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define SIZE 1000
#define TOKEN_DEFINE(token, str)

TOKEN_DEFINE("TOKEN_NAME", "TOKEN_NAME")
TOKEN_DEFINE("TOKEN_OPAREN", "(")
TOKEN_DEFINE("TOKEN_COMMA",  ",")
TOKEN_DEFINE("TOKEN_CPAREN", ")")
TOKEN_DEFINE("TOKEN_MUL",  "mul")
 
FILE *f;
char line[SIZE];
int sum = 0;
int cur,bol,row;

struct Lex {
	int cur;
	int bol;
	int row;
	char source[SIZE];

} Lexer = {0,0,0}; 

char chop(char line) {
	char *x;
	/* if newline, increment row */
	/* TODO add 'source' of index 'cur' to 'x' */
	if (x == "\n") {
		bol = cur;
		row += 1;
	}
	return line;
}

char trim_left(char token) {
	return token;
}

char next_token() {
	char token;
	token = trim_left(token);

	return token;
}

void expect_token(struct Lex *Lexer) {
	/* TODO */

	if (!Lexer->cur) {
		printf("sorry, nothing");
		
	

		}
}

int main(void) {
	expect_token(&Lexer);

        f = fopen("3_input.txt", "r");

        if (f == NULL) {
                printf("Error opening file %p \n", f);
                return 1;
        }

	int i;
        while (fgets(line, SIZE, f) != NULL && i <= 4) {
               /* a = atoi(strtok(line, " ")); */
        }


        fclose(f);
        printf("amongus %d \n", SIZE);

        /* printf("\n ANSWER: %d \n", sum); */

        return 0;
}
