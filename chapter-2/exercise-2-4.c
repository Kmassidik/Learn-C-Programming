#include <stdio.h>

/*
 * K&R Exercise 2-4: squeeze(s1, s2) - Delete characters in s1 
 * that match any character in s2.
 */
void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int found_match;

    // i is the index for reading from the original s1
    // j is the index for writing to the modified s1
    for (i = j = 0; s1[i] != '\0'; i++) {
        
        found_match = 0;
        
        // --- Inner Loop: Check if s1[i] exists in s2 ---
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                // If a match is found in s2, set the flag and break 
                // the inner loop immediately (no need to check the rest of s2)
                found_match = 1;
                break;
            }
        }
        
        // --- Outer Loop: Write the character back if no match was found ---
        if (!found_match) {
            // If the character s1[i] is NOT in s2, copy it to the write position s1[j]
            s1[j++] = s1[i];
        }
        // If a match WAS found, we simply increment 'i' (read index) and skip 
        // incrementing 'j' (write index), effectively deleting the character.
    }
    
    // Terminate the new (shorter) string
    s1[j] = '\0';
}


int main() {
    // Test Case 1: Simple deletion
    char s1_test1[] = "programming is fun";
    char s2_test1[] = "io"; // Should remove 'i' and 'o'
    
    printf("--- squeeze(s1, s2) Test Cases ---\n");
    printf("Original s1: \"%s\"\n", s1_test1);
    printf("Characters to delete (s2): \"%s\"\n", s2_test1);
    
    squeeze(s1_test1, s2_test1);
    printf("Result s1: \"%s\"\n\n", s1_test1);

    // Test Case 2: Deleting spaces and vowels
    char s1_test2[] = "The quick brown fox jumps over the lazy dog";
    char s2_test2[] = "aeiou "; // Delete all vowels and spaces
    
    printf("Original s1: \"%s\"\n", s1_test2);
    printf("Characters to delete (s2): \"%s\"\n", s2_test2);
    
    squeeze(s1_test2, s2_test2);
    printf("Result s1: \"%s\"\n\n", s1_test2);

    return 0;
}