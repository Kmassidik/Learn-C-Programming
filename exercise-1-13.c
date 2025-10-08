#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX_LENGTH 10     /* Max word length to track (1 to 10) */
#define ARRAY_SIZE (MAX_LENGTH + 1)

int main()
{
    int c;
    int state = OUT;
    int current_length = 0;
    int length_counts[ARRAY_SIZE] = {0};
    int max_freq = 0; // Needed for the vertical histogram

    // ------------------------------------------------------------------
    // 1. COUNTING WORD LENGTHS (Input Phase)
    // ------------------------------------------------------------------
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            // Word ended
            if (state == IN) {
                if (current_length > 0) {
                    // Get index (all words 10+ go into index 10)
                    int index = (current_length <= MAX_LENGTH) ? current_length : MAX_LENGTH;
                    length_counts[index]++;

                    // Update max frequency for the vertical histogram
                    if (length_counts[index] > max_freq) {
                        max_freq = length_counts[index];
                    }
                }
                current_length = 0;
            }
            state = OUT;
        } else {
            // Character is part of a word
            state = IN;
            current_length++;
        }
    }

    // Handle case where input ends mid-word (EOF)
    if (state == IN && current_length > 0) {
        int index = (current_length <= MAX_LENGTH) ? current_length : MAX_LENGTH;
        length_counts[index]++;
        
        if (length_counts[index] > max_freq) {
            max_freq = length_counts[index];
        }
    }

    printf("\n\n--- 1. Horizontal Histogram ---\n");
    printf("NOTE: Each '*' represents one word of that length.\n");
    printf("--------------------------------------\n");

    for (int i = 1; i <= MAX_LENGTH; ++i) {
        // Label the row
        if (i < MAX_LENGTH) {
            printf("Len %2d: | ", i);
        } else {
            printf("Len >%d: | ", MAX_LENGTH - 1);
        }

        // Print the bar
        for (int j = 0; j < length_counts[i]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }

    printf("\n\n--- 2. Vertical Histogram ---\n");
    printf("NOTE: Graph is printed top-down, with rows representing frequency.\n");
    printf("--------------------------------------\n");

   
    for (int row = max_freq; row > 0; --row) {
        printf("%3d |", row); // Y-Axis (Frequency) Label

        for (int i = 1; i < ARRAY_SIZE; ++i) {
            if (length_counts[i] >= row) {
                printf(" * ");
            } else {
                printf("   "); // Print a blank space
            }
        }
        printf("\n"); 
    }

    // Print the X-Axis Line
    printf("----");
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        printf("---");
    }
    printf("\n    ");

    // Print the X-Axis Labels (The word lengths)
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        printf(" %d ", i);
    }
    printf("\n");

    return 0;
}