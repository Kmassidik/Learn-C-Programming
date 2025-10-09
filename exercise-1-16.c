#include <stdio.h>
#define MAXLINE 100 // Use a moderate limit for the buffer

int my_getline(char destination_array[], int limit);
void copy(char to_array[], char from_array[]);

int main(void)
{
    int current_len;   
    int max_len;        
    int current_char;   
    
    char line[MAXLINE];    
    char longest[MAXLINE]; 

    max_len = 0;
    
    while ((current_len = my_getline(line, MAXLINE)) > 0) {
        
        if (line[current_len - 1] != '\n') {
            
            while ((current_char = getchar()) != EOF && current_char != '\n') {
                current_len++; 
            }
           
            if (current_char == '\n') {
                current_len++;
            }
        }
        
        
        if (current_len > max_len) {
            max_len = current_len;
            
            copy(longest, line); 
        }
    }
    
    // Final output
    if (max_len > 0) {
        printf("\nLongest line found (Length: %d):\n", max_len);
        printf("%s", longest);
        
        if (max_len > MAXLINE) {
            printf("\n--- (Line truncated; only first %d characters printed) ---\n", MAXLINE - 1);
        }
    }

    return 0;
}

int my_getline(char destination_array[], int limit)
{
    int current_char, index_counter;

    for (index_counter = 0; 
         index_counter < limit - 1 && 
         (current_char = getchar()) != EOF && 
         current_char != '\n'; 
         ++index_counter) 
    {
        destination_array[index_counter] = current_char;
    }
    
    if (current_char == '\n') {
        destination_array[index_counter] = current_char;
        ++index_counter;
    }
    
    destination_array[index_counter] = '\0';
    
    return index_counter; 
}

void copy(char to_array[], char from_array[])
{
    int index_counter = 0;
    
    while ((to_array[index_counter] = from_array[index_counter]) != '\0')
        ++index_counter;
}