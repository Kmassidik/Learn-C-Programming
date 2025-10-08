#include <stdio.h>
#include <ctype.h> // NOTE: Provides functions (like isprint) to classify and convert characters safely.

#define MAXCHAR 128 // Standard ASCII range (0-127)

int main() {

    int charFreq[MAXCHAR] = {0};
    int c;

    // 1. COUNTING LOGIC: Use the ASCII value as the array index.
    while ((c = getchar()) != EOF) {
        if (c < MAXCHAR) {
            ++charFreq[c];
        }
    }

    printf("\n--- Character Frequency Horizontal Histogram ---\n");
    
    // 2. PRINTING LOGIC
    for (int i = 0; i < MAXCHAR; i++) {
        
        // Skip characters that never appeared
        if (charFreq[i] == 0) {
            continue;
        }

        // isprint(i) from ctype.h checks if the character is displayable.
        if (isprint(i)) {
            // Printable characters (A-Z, 0-9, etc.)
            printf(" '%c' : ", i);
        } else if (i == '\n') {
            printf("[NL] : "); // Newline
        } else if (i == '\t') {
            printf("[TAB]: "); // Tab
        } else {
            // Other non-printable characters (using ASCII value)
            printf("[%d]: ", i); 
        }
        
        // Print the bar
        for (int j = 0; j < charFreq[i]; j++) {
            putchar('*');
        }
        
        // Add the newline character to start the next bar on a new line
        putchar('\n'); 
    }

    printf("\n----------------------------------------------\n");
    printf("NOTE: Each '*' represents one occurrence of the character.\n");
    printf("----------------------------------------------\n");

    return 0;
}