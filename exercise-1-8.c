#include <stdio.h>

int main(){
    int c, nb, nt, nl;

    nb = 0; // Number of blanks
    nt = 0; // Number of tabs
    nl = 0; // Number of newlines
    

    printf("Enter text (Ctrl+D/Ctrl+Z to end):\n");
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++nb;
        }else if (c == '\t')
        {
            ++nt;
        }else if (c == '\n')
        {
            ++nl;
        }
    }
    printf("Blanks: %d, Tabs: %d, Newlines: %d\n", nb, nt, nl);
        
    return 0;
}