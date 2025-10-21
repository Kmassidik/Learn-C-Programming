#include <stdio.h>

// Define the state constants
#define IN_CODE 0
#define IN_SINGLE_QUOTE 1
#define IN_DOUBLE_QUOTE 2
#define IN_COMMENT_ML 3  // Multi-line: /* ... */
#define IN_COMMENT_SL 4  // Single-line: // ...

int main(void)
{
    int c, next_c;
    int state = IN_CODE;

    while ((c = getchar()) != EOF) {
        
        // Peek at the next character without consuming it
        next_c = getchar();
        ungetc(next_c, stdin); 

        switch (state) {
            case IN_CODE:
                if (c == '\'' && next_c != '\\') { // Start of single-quote, ignore escaped chars
                    state = IN_SINGLE_QUOTE;
                    putchar(c);
                } else if (c == '\"' && next_c != '\\') { // Start of double-quote
                    state = IN_DOUBLE_QUOTE;
                    putchar(c);
                } else if (c == '/' && next_c == '*') { // Start of multiline comment /*
                    state = IN_COMMENT_ML;
                    getchar(); // Consume '*'
                } else if (c == '/' && next_c == '/') { // Start of single-line comment //
                    state = IN_COMMENT_SL;
                    getchar(); // Consume '/'
                } else {
                    putchar(c);
                }
                break;

            case IN_SINGLE_QUOTE:
                if (c == '\'') {
                    state = IN_CODE;
                } else if (c == '\\' && next_c != EOF) {
                    // Handle escaped characters (e.g., '\'', '\"', '\\')
                    putchar(c);
                    c = getchar();
                }
                putchar(c);
                break;
            
            case IN_DOUBLE_QUOTE:
                if (c == '\"') {
                    state = IN_CODE;
                } else if (c == '\\' && next_c != EOF) {
                    // Handle escaped characters (e.g., '\n', '\"', '\\')
                    putchar(c);
                    c = getchar();
                }
                putchar(c);
                break;

            case IN_COMMENT_ML:
                if (c == '*' && next_c == '/') { // End of multiline comment */
                    state = IN_CODE;
                    getchar(); // Consume '/'
                }
                // Discard all other characters
                break;

            case IN_COMMENT_SL:
                if (c == '\n') { // End of single-line comment
                    state = IN_CODE;
                    putchar(c);
                }
                // Discard all other characters
                break;
        }
    }
    return 0;
}