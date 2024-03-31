#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0; 					/* lower limit of temperaure scale */
	upper = 300; 				/* upper limit */
	step = 20; 					/* step size */

	fahr = lower;
	
	printf("fahrenhiet to celsius");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}	
		
	printf("\n");
	
	printf("celsious to fahrenheit\n");
	while (celsius >= lower) {
		fahr = celsius / 5.0 * 9.0	+ 32.0;
		printf("%3.1f %6.1f\n", celsius, fahr);
		celsius = celsius - step;	
	}
	
	
}	

