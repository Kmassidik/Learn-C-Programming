#include <stdio.h>
#define MAXLINE 1000 

int my_getline(char s[], int lim);
int remove_trailing(char s[]);

int main(void)
{
    int len;                
    char line[MAXLINE];     

    printf("--- Input akan diproses: menghapus spasi/tab di akhir baris dan baris kosong ---\n\n");

    while ((len = my_getline(line, MAXLINE)) > 0) {
        
        len = remove_trailing(line);
        
        if (len > 0) {
            printf("%s", line);
        }
    }

    return 0;
}


int remove_trailing(char s[])
{
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }

    i--; 

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {
        

        if (s[i] == '\n') {
            i--; 
        } else {
            i--; 
        }
    }

    if (i >= 0) {

        while (s[i + 1] != '\0' && s[i + 1] != '\n') {
            i++;
        }
        
        if (s[i] != '\n') {
             i++;
             s[i] = '\n';
        }
        
        s[i+1] = '\0';
        return i + 1;
    } else {
        s[0] = '\0';
        return 0;
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