#include <stdio.h>
#include <ctype.h>

int htoi(char s[]) {
    int i = 0;      // Index for the string
    int n = 0;      
    int hex_digit;  
    
    // --- 1. Skip optional "0x" or "0X" prefix ---
    // Correction for Line 9: Use s[i]
    if (s[i] == '0') { 
        i++;
        // Correction for Line 12: Use s[i]
        if (s[i] == 'x' || s[i] == 'X') {
            i++;
        }
    }
    
    // ... the rest of the logic remains correct
    for (; s[i] != '\0'; i++) {
        
        // Convert the current character to its numerical value
        if (s[i] >= '0' && s[i] <= '9') {
            // Digits 0-9
            hex_digit = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            // Lowercase a-f
            hex_digit = 10 + (s[i] - 'a');
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            // Uppercase A-F
            hex_digit = 10 + (s[i] - 'A');
        } else {
            // If an invalid character is encountered, stop processing
            break;
        }
        
        // Accumulate the result: n = n * 16 + hex_digit
        n = n * 16 + hex_digit;
    }
    
    return n;
}

int main() {
    // Array of test cases
    char *tests[] = {
        "1A",       // Simple uppercase
        "0xf",      // Simple lowercase with prefix
        "0XDEAD",   // Mixed case and longer
        "0x100",    // Power of 16
        "12345",    // All digits (same as base 10)
        "FF",       // Max 2-digit hex
        "GAB",      // Invalid character (should stop at 'G')
        ""          // Empty string
    };
    
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i;

    printf("--- hexatodecimal() Test Cases ---\n");
    printf("Input String | Equivalent Decimal Value\n");
    printf("----------------------------------------\n");

    for (i = 0; i < num_tests; i++) {
        printf("%-12s | %d\n", tests[i], htoi(tests[i]));
    }
    
    return 0;
}