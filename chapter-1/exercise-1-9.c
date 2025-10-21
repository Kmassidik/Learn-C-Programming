#include <stdio.h>

int main(){
    int c, last_was_blank;

    last_was_blank = 0;
    printf("Enter text (Ctrl+D/Ctrl+Z to end):\n");
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
        {
            if (!last_was_blank)
            {
                putchar(' ');
                last_was_blank = 1;
            }
            
        }
        else
        {
            putchar(c);
            last_was_blank = 0;
        }
        
    }
    return 0;

}

