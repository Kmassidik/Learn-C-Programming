/*
 ============================================================================
 |  C Data Types Summary Table (based on Wikipedia)
 ============================================================================
 | Type                      | Explanation                              | Size (bits) | Format    | Range                      | Suffix       |
 |--------------------------|------------------------------------------|-------------|-----------|----------------------------|--------------|
 | _Bool / bool             | Boolean type (true/false)                | 1 (exact)   | %d        | 0 (false), 1 (true)        | —            |
 | char                     | Character type                           | ≥8          | %c        | [CHAR_MIN, CHAR_MAX]       | —            |
 | signed char              | Signed character                         | ≥8          | %c        | [-128, +127] approx.       | —            |
 | unsigned char            | Unsigned character                       | ≥8          | %c        | [0, 255]                   | —            |
 | short / short int        | Short integer                            | ≥16         | %hd       | [-32,768, +32,767]         | —            |
 | unsigned short           | Unsigned short                           | ≥16         | %hu       | [0, 65,535]                | —            |
 | int / signed int         | Standard integer                         | ≥16         | %d or %i  | [-32,768, +32,767] or more | —            |
 | unsigned int             | Unsigned integer                         | ≥16         | %u        | [0, 65,535] or more        | u or U       |
 | long / signed long       | Long integer                             | ≥32         | %ld       | [-2,147,483,648 to +...]   | l or L       |
 | unsigned long            | Unsigned long integer                    | ≥32         | %lu       | [0, 4,294,967,295]         | ul or UL     |
 | long long                | Very long integer                        | ≥64         | %lld      | ~[-9e18, +9e18]            | ll or LL     |
 | unsigned long long       | Very long unsigned integer               | ≥64         | %llu      | [0, ~1.8e19]               | ull or ULL   |
 | float                    | Single precision float                   | 32          | %f        | ~±1.2e-38 to ±3.4e+38      | f or F       |
 | double                   | Double precision float                   | 64          | %lf       | ~±2.2e-308 to ±1.8e+308    | —            |
 | long double              | Extended precision float                 | ≥80         | %Lf       | Varies                     | L or l       |
 ============================================================================
*/

#include <stdio.h>
#include <stdbool.h> // Enables use of 'bool' alias

int main() {
    // Boolean: stores 0 (false) or 1 (true)
    bool isReady = true;

    // Character types
    char letter = 'A';
    signed char signedChar = -100;
    unsigned char unsignedChar = 200;

    // Integer types
    short myShort = -32000;
    unsigned short myUShort = 65000;

    int myInt = 12345;
    unsigned int myUInt = 4294967295U;

    long myLong = 1000000L;
    unsigned long myULong = 4000000000UL;

    long long myLongLong = 9223372036854775807LL;
    unsigned long long myULongLong = 18446744073709551615ULL;

    // Floating-point types
    float myFloat = 3.14f;
    double myDouble = 3.1415926535;
    long double myLongDouble = 3.141592653589793238L;

    // Output values
    printf("Boolean: %d\n", isReady);
    printf("Char: %c\n", letter);
    printf("Signed char: %d\n", signedChar);
    printf("Unsigned char: %u\n", unsignedChar);

    printf("Short: %hd\n", myShort);
    printf("Unsigned short: %hu\n", myUShort);

    printf("Int: %d\n", myInt);
    printf("Unsigned Int: %u\n", myUInt);

    printf("Long: %ld\n", myLong);
    printf("Unsigned Long: %lu\n", myULong);

    printf("Long Long: %lld\n", myLongLong);
    printf("Unsigned Long Long: %llu\n", myULongLong);

    printf("Float: %.2f\n", myFloat);
    printf("Double: %.10f\n", myDouble);
    printf("Long Double: %.15Lf\n", myLongDouble);

    return 0;
}


/*
 ============================================================================
 |                   ✅ DOs and ❌ DON'Ts with C Data Types
 ============================================================================
 ✅ DO:
 - Use 'int' for general-purpose whole numbers.
 - Use 'unsigned' only if you're certain the value will never be negative.
 - Use 'float' or 'double' for decimal numbers, not 'int'.
 - Use correct format specifiers in printf (%d, %ld, %llu, etc.).
 - Use 'bool' for logical conditions (true/false).
 - Use suffixes (e.g., L, LL, U) for constant values when needed.

 ❌ DON'T:
 - ❌ Don’t store decimal numbers in 'int' — use 'float' or 'double'.
 - ❌ Don’t forget to match printf specifiers with the type (e.g., %lf for double).
 - ❌ Don’t assume data types are always the same size on every system.
 - ❌ Don’t use signed types when you only need positive values — prefer unsigned.
 - ❌ Don’t use 'char' for strings — use char arrays (e.g., char str[10]).
 ============================================================================
*/
