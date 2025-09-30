#include <stdio.h>

int main(){
    int c;

    printf("Enter a character (or Ctrl+D/Ctrl+Z to signal EOF):\n");
    c = getchar();
    printf("getchar() != EOF is %d\n", c != EOF);

    return 0;
}