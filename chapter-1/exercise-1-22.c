#include <stdio.h>

#define MAX_COL 20 // The column at which the line should be folded (N)
#define MAX_LINE 1000 // Maximum size for the temporary buffer

int main(void)
{
    int c;             
    int col = 0;       // Current column position (0-based)
    int last_blank = -1; // Index of the last space encountered in the buffer
    int i = 0;         // Current index in the buffer
    char buffer[MAX_LINE]; 

    while ((c = getchar()) != EOF) {
        
        // 1. Store the character in the buffer
        buffer[i] = c;
        
        // 2. Update tracking variables
        if (c == ' ') {
            last_blank = i; // Record the index of the space
        }
        
        // Handle newlines immediately
        if (c == '\n') {
            // Print everything in the buffer, including the newline
            for (int k = 0; k <= i; ++k) {
                putchar(buffer[k]);
            }
            // Reset state
            col = 0;
            i = 0;
            last_blank = -1;
            continue; 
        }
        
        // 3. Check for the fold condition
        if (col == MAX_COL) {
            
            int fold_index;
            // Removed: int remaining_chars; // <-- THIS WAS THE UNUSED VARIABLE
            
            if (last_blank != -1) {
                // Case A: Found a safe break point (last_blank)
                fold_index = last_blank;
                // Removed: remaining_chars = i - last_blank;
            } else {
                // Case B: No space was found before MAX_COL (very long word).
                // Break at MAX_COL (the line must fold).
                fold_index = i;
                // Removed: remaining_chars = 0; 
            }
            
            // a. Print the line segment up to the fold point
            for (int k = 0; k < fold_index; ++k) {
                putchar(buffer[k]);
            }
            
            // b. Insert the newline
            putchar('\n');
            
            // c. Shift remaining characters to the start of the buffer for the next line
            int j = 0;
            for (int k = fold_index + 1; k <= i; ++k) {
                // Skip the space itself if we folded on a space
                if (buffer[k] != ' ') {
                    buffer[j++] = buffer[k];
                }
            }
            
            // d. Reset state for the new line
            i = j - 1; 
            col = j;   
            last_blank = -1;
            
        } else {
            // Increment for the next character
            col++;
            i++;
        }
    }
    
    // Print any remaining characters in the buffer at EOF
    for (int k = 0; k < i; ++k) {
        putchar(buffer[k]);
    }
    
    return 0;
}