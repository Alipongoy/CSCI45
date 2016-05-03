#include <stdio.h>
int input_number(){
	int x;
	scanf("%i", &x);
	return x;
}
void print_number(int x) {
	printf("%i\n",x);
}

void print_string(char *str) {
	printf("%s",str);
}
