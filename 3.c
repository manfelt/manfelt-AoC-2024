#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000
#define DEBUG 0

int delim_flag, res = 0;
char *c, *p;
FILE *f;
char line[SIZE];
int cur, rowlen, *pcur, mul_flag;
// TODO char bol, row;

struct Lex {
	int cur;
	int row;
} Lexer = {0,0};

struct str_val {
	char c[20];
};

struct operands {
	int a;
	int b;
}; 

int get_index(char* string, char c) {
	char *e = strchr(string, c);
	if (e == NULL) {
		return -1;
	}
	return (int)(e - string);
}

void loop_str(char *s) {
	for(int i = 0; s[i] != '\0'; i++) {
		printf("s[%d] -> %c\n", i, s[i]);
	}
}

char get_ch(int i, char *s) {
	char result = s[i];
	return result;
}

// TODO Gjør om til å motta character istedetfor string.
int expect_int(char i[]) { 
	printf("\n running expect_int with %s",i);
	if (strcmp(i,"1")==0||strcmp(i,"2")==0||strcmp(i,"3")==0||strcmp(i,"4")==0||strcmp(i,"5")==0||strcmp(i,"6")==0||strcmp(i,"7")==0||strcmp(i,"8")==0||strcmp(i,"9")==0||strcmp(i,"0")==0) {
		return 1;
	} else {
		return 0;
	}
}

// unødvendig?
int is_it_mul(int cur) {
	if (1) {
		return 1; 
	}
}

char* concat(const char *s1, const char *s2)
{
	char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for null-terminator
														// malloc errors check?
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

char* memory_alloc(char *c) {
	c = malloc(1 * sizeof(char));	
	return c;
}

int main() {
	struct operands op[SIZE];

	//printf("index : %d \n",cur);
	//*c = get_ch(cur,string);


	// m 109
	// u 117 
	// l 108
	// ( 40 
	// , 44
	// ) 41

	f = fopen("3_input.txt", "r");

	if (f == NULL) {
		printf("Error opening file %p \n", f);
		return 1;
	}	

	int line_count = 1;
	mul_flag = 0;
	int inc = 0;
	char *a = memory_alloc(a);
	char *b = memory_alloc(b);	

	if (DEBUG) {
		printf("\n debug mode on");
	} else {
		printf("\n debug mode off");
	}

	while (fgets(line, SIZE, f) != NULL) {
		printf("\n LINE: %i",line_count);
		rowlen = strlen(line);
		//loop_str(string);
		cur = get_index(line,'m');
		while (cur<rowlen) {
			cur++;
			if (line[cur]==40) {
				if (cur >= 3 && line[cur-1]==108 && line[cur-2]==117 && line[cur-3]==109) {
					mul_flag = 1;
					//struct str_val a = {.c = "0"};
					//struct str_val b = {.c = "0"};
					//if (DEBUG) {
					printf("\n 'mul(' found at cur %d", cur);
					//}
				};
				continue; 
			}
			if (mul_flag) {
				if (DEBUG) {
					printf("\n mul flag set, look for int or ','.");
				}
				char tmp = line[cur];
				//b = concat(&tmp, a);
				if (expect_int(&tmp)) {
					if (DEBUG) {

						printf("\n %c <- this is an integer.",line[cur]);
					}
					if(!delim_flag) {
						inc++;
						strcat(a,&tmp);
						if (DEBUG) {
							printf("\n value of 'a': %s",a);
						}
					} else {
						strcat(b,&tmp);
						if (DEBUG) {
							printf("\n value of 'b': %s",b);
						}
					}	
				}
				else if (line[cur]==44) {
					if (DEBUG) {
						printf("\n %c  delimeter. Expecting next argument",line[cur]);
					}	
					if (!delim_flag) {
						for (int i = 0; i > inc; i++) {
							printf("\n USDHJFKLJS %c", line[cur-i]);
						}
						inc = 0;
						delim_flag=1;
					} else {
						if (DEBUG) {
							printf("\n UNEXPECTED token ',' at index %i. Break", cur);
						}
						mul_flag=0;
						delim_flag=0;
						memset(a, 0, sizeof(a));
						memset(b, 0, sizeof(b));
					}
					// TODO unset mul flag if ')', if neither ')' number or ',' erase a & b values.
				}
				else if (line[cur]==41) {
					//if (DEBUG) {
					printf("\n cparen encountered gracefully, close mul flag, store parameters as results for now");
					//}
					delim_flag=0;
					mul_flag=0;
					int tmp_res = (atoi(a) * atoi(b));
					res += tmp_res;
					printf("\n RESULT of %i, %i multiplied: %i",atoi(a),atoi(b),tmp_res);
					memset(a, 0, sizeof(a));
					memset(b, 0, sizeof(b));
				} else {
					delim_flag=0;
					mul_flag=0;
					memset(a, 0, sizeof(a));
					memset(b, 0, sizeof(b));
					printf("\n UNEXPECTED token '%c' ",line[cur]);
				}
			}
		}
		line_count++;
		printf("\n RESULT THIS LINE: %i",res);
	}
	printf("\n TOTAL RESULT: %i",res);
	free(a);
	free(b);
	return 0;
}
