#include <stdio.h>

// 1. FUNCTION PROTOTYPE: Tells the compiler the function exists, 
//    what type it returns (float), and what type it takes (float).
float fahr_to_celsius(float fahr);

int main(void)
{
    float fahr;
    int lower, upper, step;

    lower = 0;    // lower limit of temperature scale
    upper = 300;  // upper limit
    step = 20;    // step size

    fahr = lower;
    printf("Fahrenheit  Celsius\n");
    printf("-------------------\n");

    while (fahr <= upper) {
        // CALL THE FUNCTION: The calculation is now done in fahr_to_celsius()
        printf("%10.0f %9.1f\n", fahr, fahr_to_celsius(fahr));
        fahr = fahr + step;
    }

    return 0;
}

// 2. FUNCTION DEFINITION: Contains the logic to perform the conversion.
/* fahr_to_celsius: convert Fahrenheit to Celsius */
float fahr_to_celsius(float fahr)
{
    // C = (5.0 / 9.0) * (F - 32)
    return (5.0 / 9.0) * (fahr - 32.0);
}