#include <stdio.h>

int main(void) {
	int chr;
	while ((chr = getchar()) != EOF) {
		if (chr == '\t')
			printf("\\t");
		else if (chr == '\b')
			printf("\\b");
		else if (chr == '\\')
			printf("\\\\");
		else 
			putchar(chr);

	}
	return 0;
}
