#include <stdio.h>

#define TAB_STOP 4 

int main(void)
{
    int c;          
    int pos = 1;    
    int spaces;     

    printf("--- Detab Program (Revisi - Tab Stop setiap %d kolom) ---\n\n", TAB_STOP);
    
    while ((c = getchar()) != EOF) {
        
        if (c == '\t') {
            spaces = TAB_STOP - ((pos - 1) % TAB_STOP);
            
            for (int i = 0; i < spaces; ++i) {
                putchar(' ');
            }
            
            pos = pos + spaces;
        } else if (c == '\n') {
            putchar(c);
            pos = 1; 
        } else {
            putchar(c);
            pos++;
        }
    }

    return 0;
}