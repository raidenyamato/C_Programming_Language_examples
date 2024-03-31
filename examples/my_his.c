#include <stdio.h>

#define MAXLEN 10
#define MINLEN 0

void print_array(int[]);
void print_horizontal(int[]);
void print_vertical(int[]);

int main(void) 
{
	int i, c, len;
	int lenfreq[MAXLEN];
	
	for (i = 0; i < MAXLEN; i++)
		lenfreq[i] = 0;

	len = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (len > 0) 
				lenfreq[len]++;
			len = 0;
		} else {
			len++;
		}
	}

	
	print_array(lenfreq);
	print_horizontal(lenfreq);	
	print_vertical(lenfreq);	

	return 0;
}



void print_array(int array[])
{
	int i;
	for (i = 0; i < MAXLEN; i++) 
		printf("%2d => %d\n", i, array[i]);
}




void print_horizontal(int lenfreq[]) 
{
	int i, j;
	for (i = 1; i < MAXLEN; i++) {
		printf("%2d | ", i);
		for (j = 0; j < lenfreq[i]; j++)
			putchar('#');
		putchar('\n');
	}




}


void print_vertical(int lenfreq[])
{
	int i,j;
	for (i = 9; i > MINLEN; i--) {
		for (j = 1; j < MAXLEN; j++) {
			if (lenfreq[j] >= i) {
				putchar('#');
			} else {
				putchar(' ');
			}	
		} 
		putchar('\n');	
	}

	for (i = 1; i < MAXLEN; i++)
	{
		printf("%d", i);
	}
	

}












