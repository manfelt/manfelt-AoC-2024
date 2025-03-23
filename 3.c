#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string = "from()]mul(317,745)-+?;what()&{mul(67,323)select()~(+/}what()<mul(304,399)";
char delim[] = ",";
char *c, *p;
int cur, num_a, num_b;
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
	printf("\n what %s",i);
	// TODO strcmp() 
	if (i=="1"||i=="2"||i=="3"||i=="4"||i=="5"||i=="6"||i=="7"||i=="8"||i=="9"||i=="0") {
		return 1;
	} else {
		return 0;
	}
}

int is_it_mul(int cur) {
	if (1) {
	return 1; 
	}
}

int main() {
	//loop_str(string);
	cur = get_index(string,'m');
	printf("index : %d \n",cur);
	c = get_ch(cur,string);
	printf("%c\n",c);
	char a[] = "2";
	if (strcmp("a","ab")) {printf("asd");}
	if (expect_int(a)) {
		printf("\n It's number");
	} else {
		printf("\n It's not a number");
	}

	return 0;
}
