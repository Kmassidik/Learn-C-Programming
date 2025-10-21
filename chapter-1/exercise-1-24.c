#include <stdio.h>

// Function to check for syntax errors
void check_syntax_errors();

// Global flags and counters to track state:
//  * - in_comment: 1 if inside a /* ... */ comment, 0 otherwise
//  * - in_single_quote: 1 if inside a '...' single quote, 0 otherwise
//  * - in_double_quote: 1 if inside a "..." double quote, 0 otherwise
//  * - paren_count, brace_count, bracket_count: Counts of open (,{,[

int in_comment = 0;
int in_single_quote = 0;
int in_double_quote = 0;

int paren_count = 0;    // ()
int brace_count = 0;    // {}
int bracket_count = 0;  // []

int main() {
    printf("Starting C syntax error check. Enter your C code (press Ctrl+D to signal EOF):\n");
    check_syntax_errors();
    return 0;
}

void check_syntax_errors() {
    int c, prev_c = 0;
    int line_num = 1;

    // Loop through all characters from standard input
    while ((c = getchar()) != EOF) {
        
        // --- 1. Line Counting ---
        if (c == '\n') {
            line_num++;
        }

        // --- 2. State Check and Update: Comments ---
        // If we are NOT in quotes, check for comment transitions
        if (!in_single_quote && !in_double_quote) {
            
            // Start of a block comment: '/*'
            if (!in_comment && prev_c == '/' && c == '*') {
                // Backtrack prev_c to avoid miscounting it as a '/' 
                // outside of the comment context in the next iteration.
                // This is a subtle point, often handled by pushing back 'prev_c' 
                // or restructuring the loop, but for simplicity here we just enter the state.
                in_comment = 1;
                // We've processed '/' and '*' as the start, so skip to next char
                prev_c = 0; // Reset prev_c to ensure '/' doesn't interact with the next char
                continue; 
            } 
            // End of a block comment: '*/'
            else if (in_comment && prev_c == '*' && c == '/') {
                in_comment = 0;
                // We've processed '*' and '/' as the end
                prev_c = 0;
                continue; 
            }
            // Skip line comments: '//' (basic check)
            else if (!in_comment && prev_c == '/' && c == '/') {
                // Simple version: Skip until newline
                while ((c = getchar()) != EOF && c != '\n');
                line_num++; // Increment line count since we skipped to the end of the line
                prev_c = 0;
                continue;
            }
        }

        // If we are currently inside a block comment, ignore all characters
        if (in_comment) {
            prev_c = c;
            continue;
        }


        // --- 3. State Check and Update: Quotes ---

        // Single Quote: '
        if (c == '\'' && !in_double_quote) {
            // Check for escaped quote: '\''
            if (prev_c != '\\') {
                in_single_quote = !in_single_quote;
            }
        }
        
        // Double Quote: "
        if (c == '\"' && !in_single_quote) {
            // Check for escaped quote: "\""
            if (prev_c != '\\') {
                in_double_quote = !in_double_quote;
            }
        }

        // If we are currently inside any quotes, ignore all structural characters
        if (in_single_quote || in_double_quote) {
            // Special handling for the next iteration: ignore backslash if it was escaped
            // e.g. "a\\" -> 'prev_c' is 'a', 'c' is '\', inside double quote, 'prev_c' becomes '\'.
            // next char is '\', 'prev_c' is '\', 'c' is '\', 'prev_c' is now considered escaped.
            // This is complex and often requires a state for 'is_escaped'.
            // For this basic K&R exercise, we'll keep it simple by just checking prev_c != '\'.
            
            // For now, only update prev_c and continue
            prev_c = c;
            continue;
        }
        
        // --- 4. Structural Character Check (Only runs if NOT in comments or quotes) ---
        
        switch (c) {
            case '(':
                paren_count++;
                break;
            case ')':
                paren_count--;
                if (paren_count < 0) {
                    printf("\n*** ERROR: Unbalanced parenthesis ')' at line %d\n", line_num);
                    paren_count = 0; // Reset or leave negative (here we reset for better error isolation)
                }
                break;

            case '[':
                bracket_count++;
                break;
            case ']':
                bracket_count--;
                if (bracket_count < 0) {
                    printf("\n*** ERROR: Unbalanced bracket ']' at line %d\n", line_num);
                    bracket_count = 0;
                }
                break;

            case '{':
                brace_count++;
                break;
            case '}':
                brace_count--;
                if (brace_count < 0) {
                    printf("\n*** ERROR: Unbalanced brace '}' at line %d\n", line_num);
                    brace_count = 0;
                }
                break;

            case '/':
            case '*': 
            case '\'':
            case '\"':
            case '\\':
                // These are characters that might start or end a state, 
                // but their primary role is handled in sections 2 & 3.
                // We keep them here just to ensure 'prev_c' is updated correctly
                // before the next iteration, which is crucial for multi-character sequences.
                break;

            default:
                // All other characters are ignored for structural checks
                break;
        }

        // Update the previous character for the next iteration's look-back
        prev_c = c;
    }

    // --- 5. Final Check at EOF ---

    if (in_comment) {
        printf("\n*** ERROR: Unterminated block comment at end of file.\n");
    }
    if (in_single_quote) {
        printf("\n*** ERROR: Unterminated single quote at end of file.\n");
    }
    if (in_double_quote) {
        printf("\n*** ERROR: Unterminated double quote at end of file.\n");
    }

    if (paren_count != 0) {
        printf("\n*** ERROR: Unbalanced parentheses. %d missing ')'\n", paren_count);
    }
    if (bracket_count != 0) {
        printf("\n*** ERROR: Unbalanced brackets. %d missing ']'\n", bracket_count);
    }
    if (brace_count != 0) {
        printf("\n*** ERROR: Unbalanced braces. %d missing '}'\n", brace_count);
    }

    if (paren_count == 0 && bracket_count == 0 && brace_count == 0 &&
        !in_comment && !in_single_quote && !in_double_quote) {
        printf("\nSyntax check complete: No rudimentary errors found.\n");
    }
}