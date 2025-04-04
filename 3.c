#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

char *string = "from()]mul(317,745)-+?;what()&{mul(67,323)select()~(+/}what()<mul(304,399)";
char delim[] = ",";
char *c, *p;
int cur, rowlen, *pcur;
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

int expect_int(char i[]) { 
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
	//c = get_ch(cur,string);
	c = string[4];
	printf("\n %c", c);


	while (cur<rowlen) {
		if (c==0) {
			printf("\n m"); 
			continue;
		} else if (c=="u") {
			printf("\n u");
			continue;
		} else if (c=="l") {
			printf("\n l");
			continue;
		} else if (c=="(") {
			printf ("\n (");
			continue; 
		}
		cur++;
	} 
	/*
	if (strcmp(c,"m")==0) {
		if (strcmp(c,"u")==0) {
			if (strcmp(c,"l")==0) 
				if (strcmp(c,"(")==0) {
				
				} else { break; } 
			} else { break; }
		} else { break; }
	} else { break; }
	*/	

	char a[] = "2";
	if (strcmp("a","ab")) {printf("asd");}
	if (expect_int(a)) {
		printf("\n It's number");
	} else {
		printf("\n It's not a number");
	}

	return 0;
}
