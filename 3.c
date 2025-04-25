#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

char *string = "from()]mul(317,745)-+?;what()&{mul(69,42,0)select()~(+/}what()<mul(304,399)";
int delim_flag = 0;
char *c, *p, a[4], b[4];
int cur, rowlen, *pcur, mul_flag;
// TODO char bol, row;

struct Lex {
	int cur;
	int row;
} Lexer = {0,0};

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
	printf("/n running expect_int with %s",i);
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

int main() {
	struct operands op[SIZE];
	rowlen = strlen(string);
	//loop_str(string);
	cur = get_index(string,'m');
	printf("index : %d \n",cur);
	//*c = get_ch(cur,string);


        // m 109
        // u 117 
        // l 108
        // ( 40 
	// , 44
	// ) 41

	mul_flag = 0;

	while (cur<rowlen) {
		cur++;
		if (string[cur]==40) {
			if (cur >= 3 && string[cur-1]==108 && string[cur-2]==117 && string[cur-3]==109) {
				mul_flag = 1;
				//a = b = "0";
				printf("\n mul( found at cur %d", cur);
			};
			continue; 
		}
		if (mul_flag) {
			printf("\n mul flag set, look for int or ','.");
			char *tmp = string[cur];
			if (expect_int(&tmp)) {
				printf("\n %c <- this is an integer.",string[cur]);
				if(!delim_flag) {
					//strcat(a,string[cur]);
					//printf("\n value of 'a': %s",a);
				} else {
					//strcat(b,string[cur]);
					//printf("\n value of 'b': %s",b);
				}		}
			 else if (string[cur]==44) {
				printf("\n %c  delimeter. Expecting next argument",string[cur]);
				if (!delim_flag) {
					delim_flag=1;
				} else {
					printf("\n unexpected token ',' at index %i.", cur);
					mul_flag=0;
				}
			// TODO unset mul flag if ')', if neither ')' number or ',' erase a & b values.
			}
			 else if (string[cur]==41) {
				printf("\n cparen encountered, close mul flag ");
				delim_flag=0;
				mul_flag=0;
			}
		}
	} 
	return 0;
}
