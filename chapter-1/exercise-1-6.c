#include <stdio.h>

int main(){
    int c;

    printf("Enter a character (or Ctrl+D/Ctrl+Z to signal EOF):\n");
    c = getchar();

    // Use putchar to print the character that was read by getchar()
    if (c != EOF) {
        printf("The character read was: ");
        putchar(c);
        printf("\n"); // Add a newline after the character for clean output
    }
    
    printf("getchar() != EOF is %d\n", c != EOF);

    return 0;
}