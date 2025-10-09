#include <stdio.h>

#define lower 0
#define upper 300
#define step 20


float fahr_to_celcius(float fahr){

    float res = (fahr - 32.0) * (5.0 / 9.0);
    return res;
}

int main(){

    float fahr;

    fahr = lower;
    printf("Fahr\tCelsius\n");
    printf("------------------\n");

    while (fahr <= upper)
    {
        /* code */
        printf("%10.0f %9.2f\n", fahr, fahr_to_celcius(fahr));
        fahr = fahr + step;
    }
    
    return 0;
}