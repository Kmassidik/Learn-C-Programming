#include <stdio.h>

int main() {
    int c;

    printf("Enter text (Ctrl+D/Ctrl+Z to end):\n");
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }

    return 0;
}