#include <stdio.h>

#define MAXLINE 1000


int main(){
    int i;
    int c;
    char s[MAXLINE];
    int lim = MAXLINE;

    i = 0;

    while (i < lim - 1)
    {
        if (((c = getchar()) ==  EOF))
        {
            break;
        }
        
        if (c == '\n')
        {
            break;
        }

        s[i] = c;
        i++;
    }
    
    s[i] = '\0';
    printf("Starting read: %s\n",s);    

    return 0;
}