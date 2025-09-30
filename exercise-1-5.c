#include <stdio.h>

int main() {
    float cel, fah;
    int low, up, step;

    low = 0;   /* lower limit of temperature table */
    up = 300;  /* upper limit */
    step = 20; /* step size */

    printf("Celsius\tFahr\n");

    for (cel = up; cel >= low; cel -= step) {
        fah = (9.0 / 5.0) * cel + 32.0;
        printf("%3.0f\t%6.2f\n", cel, fah);
    }
    
    return 0;
}