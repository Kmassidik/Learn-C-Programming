#include <stdio.h>
#define MAXLINE 1000

int my_getline(char s[], int lim);
void reverse(char s[]);

int main(){
    char line[MAXLINE];

    printf("--- Input akan dibalik per baris ---\n\n");

    while (my_getline(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

void reverse(char s[]){
    int i,j;
    int len = 0;
    char temp;

    while (s[len] != '\0')
    {
        len++;
    }

    i = 0;

    if (len > 0 && s[len - 1] == '\n') {
        j = len - 2;
    } else {
        j = len - 1;
    }

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        
        i++;
        j--;
    }
}

int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';
    
    return i;
}