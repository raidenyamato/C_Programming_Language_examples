#include <stdio.h>

#define IN 1
#define OUT 0


int maint(void) 
{
	int c, nl, nw, nc;
	state = OUT;
	nl = nw = nc = 0;
	
	while( (c = getchar()) != EOF ) {
		++nc;
		
		if (c == ' ' || c == '\n' || c == '\t' )
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		} 	

	}
	printf("new lines = %d, new worlds =  %d, new characters = %d\n", nl, nc);




	return 0;
}
