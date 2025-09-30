#include <stdio.h>

int main() { 
    // printf("experiment with \c "); // warning unknown escape sequence: '\c'
    printf("Experiment with \\c as a literal string\n");
    printf("will not cause error, since '\\c' is treated as a backslash and '\c'\n"); // still be print but wihout "\"
    return 0;
}