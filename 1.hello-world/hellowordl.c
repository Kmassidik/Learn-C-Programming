#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

/*
 * ===== How to Compile and Run This C Program on Linux =====
 *
 * Step 1: Open your terminal and navigate to the folder containing this file.
 *         Use 'cd' command:
 *         cd /path/to/your/file
 *
 * Step 2: Compile the code using gcc (GNU Compiler Collection).
 *
 *         Command:
 *         gcc -std=c17 hello.c -o hello
 *
 *         Explanation:
 *         - 'gcc' is the GNU compiler for C.
 *         - '-std=c17' tells the compiler to use the C17 standard (you can also use c99 or c11).
 *         - 'hello.c' is the name of your C source file.
 *         - '-o hello' specifies the output file name as 'hello'.
 *           This will create an executable named 'hello' in the current directory.
 *
 * Step 3: Run the compiled program.
 *
 *         Command:
 *         ./hello
 *
 *         Explanation:
 *         - './' tells the shell to execute the 'hello' program from the current directory.
 *
 * Step 4: Expected Output:
 *
 *         Hello, World!
 *
 * ==========================================================
 */
