#include <stdio.h>

float fahrToCel(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}

int main()
{
    float fahr;
    int lower, upper, step;
    
    lower = 20; /* lower limit of temperature table */
    upper = 300;
    step = 20;
    
    fahr = lower;
    
    printf("Fahr Cels\n");
    printf("=========\n");
    
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fahrToCel(fahr));
        fahr = fahr + step;
    }
    return 0;
}
