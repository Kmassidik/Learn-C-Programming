#include <stdio.h>

#define TABINC 8
#define MAXLINE 1000

int next_tab_stop(int col)
{
    return col + (TABINC - (col % TABINC));
}

int main(void)
{
    int c, col, nblanks, ntabs;

    col = 0;      
    nblanks = 0;  

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++nblanks;
        } else {
            if (nblanks > 0) {
                int spaces_to_next_tab = next_tab_stop(col) - (col + nblanks);
                
                ntabs = 0;
                
                while (nblanks >= spaces_to_next_tab && spaces_to_next_tab > 0) {
                    ++ntabs;
                    nblanks -= spaces_to_next_tab;
                    col = next_tab_stop(col);
                    spaces_to_next_tab = next_tab_stop(col) - col; 
                }
               
                while (ntabs-- > 0) {
                    putchar('\t');
                }
                
                while (nblanks-- > 0) {
                    putchar(' ');
                    ++col;
                }
            }
            
            putchar(c);
            
            if (c == '\n') {
                col = 0;
            } else if (c == '\t') {
                col = next_tab_stop(col);
            } else {
                ++col;
            }
            
            nblanks = 0;
        }
    }
    return 0;
}