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
    printf("--- Ranges by Direct Computation ---\n\n");

    // --- 1. UNSIGNED TYPES (Max Value) ---
    // Max Unsigned = ~0 cast to the unsigned type
    
    printf("--- Unsigned Types ---\n");
    // Max Unsigned Char: (~0 is all 1s, cast to uchar takes the rightmost 8 bits)
    printf("Max Unsigned Char:  %u\n", (unsigned char) ~0);
    // Max Unsigned Short:
    printf("Max Unsigned Short: %u\n", (unsigned short) ~0);
    // Max Unsigned Int:
    printf("Max Unsigned Int:   %u\n", (unsigned int) ~0);
    // Max Unsigned Long:
    printf("Max Unsigned Long:  %lu\n", (unsigned long) ~0);

    // --- 2. SIGNED TYPES (Min and Max Values) ---
    
    printf("\n--- Signed Types ---\n");

    // Signed CHAR:
    char uc_max = (unsigned char) ~0;
    char c_max = uc_max >> 1; // Max Signed = Max Unsigned / 2
    printf("Max Signed Char:  %d\n", c_max);
    printf("Min Signed Char:  %d\n", c_max + 1); // Min Signed = Max Signed + 1 (wraps around)

    // Signed SHORT:
    short us_max = (unsigned short) ~0;
    short s_max = us_max >> 1;
    printf("Max Signed Short: %d\n", s_max);
    printf("Min Signed Short: %d\n", s_max + 1);

    // Signed INT:
    int ui_max = (unsigned int) ~0;
    int i_max = ui_max >> 1;
    printf("Max Signed Int:   %d\n", i_max);
    printf("Min Signed Int:   %d\n", i_max + 1);

    // Signed LONG:
    long ul_max = (unsigned long) ~0;
    long l_max = ul_max >> 1;
    printf("Max Signed Long:  %ld\n", l_max);
    printf("Min Signed Long:  %ld\n", l_max + 1);

    return 0;
}