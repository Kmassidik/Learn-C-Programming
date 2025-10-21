#include <stdio.h>
#define MAXLINE 1000
#define MIN_LENGTH 80

int my_getline(char s[], int lim);

int main(){
    int len;
    char line[MAXLINE];

    printf("--- Printing lines longer than %d characters ---\n\n", MIN_LENGTH);

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        if (len > MIN_LENGTH)
        {
            printf("Length (%d): %s", len, line);
        }
    }
    
    return 0;
}

int my_getline(char destination_array[], int limit)
{
    int current_char, index_counter;

    // Read up to limit-1 characters
    for (index_counter = 0; 
         index_counter < limit - 1 && 
         (current_char = getchar()) != EOF && 
         current_char != '\n'; 
         ++index_counter) 
    {
        destination_array[index_counter] = current_char;
    }
    
    // If we stopped on a newline, put it in the buffer and count it
    if (current_char == '\n') {
        destination_array[index_counter] = current_char;
        ++index_counter;
    }
    
    // Null-terminate the string
    destination_array[index_counter] = '\0';
    
    return index_counter; 
}