#include <stdio.h>
#include <limits.h> // This header defines the limits of integer types

/*
 * K&R Exercise 2-1: Determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing values from standard headers.
 */
int main() {
    printf("--- Ranges from Standard Headers (limits.h) ---\n\n");

    // 1. Signed Integer Types
    printf("--- Signed Types ---\n");
    printf("Min Signed Char: %d\n", SCHAR_MIN);
    printf("Max Signed Char: %d\n", SCHAR_MAX);

    printf("Min Signed Short: %d\n", SHRT_MIN);
    printf("Max Signed Short: %d\n", SHRT_MAX);

    printf("Min Signed Int: %d\n", INT_MIN);
    printf("Max Signed Int: %d\n", INT_MAX);

    printf("Min Signed Long: %ld\n", LONG_MIN);
    printf("Max Signed Long: %ld\n", LONG_MAX);

    // 2. Unsigned Integer Types
    printf("\n--- Unsigned Types ---\n");
    // Unsigned minimum is always 0.
    printf("Max Unsigned Char: %u\n", UCHAR_MAX);
    printf("Max Unsigned Short: %u\n", USHRT_MAX);
    printf("Max Unsigned Int: %u\n", UINT_MAX);
    printf("Max Unsigned Long: %lu\n", ULONG_MAX);
    
    // Note on 'char': CHAR_MIN and CHAR_MAX reflect whether 'char' 
    // is treated as signed or unsigned by default on the system.
    // We explicitly check SCHAR and UCHAR for the guaranteed signed/unsigned ranges.

    return 0;
}