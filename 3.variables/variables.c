/*
=========================================
📘 NOTE: What is a Variable in C?
=========================================

A variable in C is a named location in memory used to store data 
that your program can use and modify during execution.

🔹 Syntax:
   datatype variableName = value;

🔹 Common Types:
   int    - Whole numbers
   float  - Decimal numbers
   double - High-precision decimals
   char   - Single characters
   char[] - Strings (arrays of characters)

🔹 DOs and DON'Ts:
   ✅ Use valid names, proper types, and correct sizes
   ❌ Avoid overflow, invalid characters, and mismatched types
*/

#include <stdio.h>

int main() {
    // ✅ DO: Declare and initialize variables properly
    int age = 25;
    float gpa = 3.75;
    char grade = 'A';
    char name[] = "Alice";

    // ✅ Output variable values
    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Grade: %c\n", grade);
    printf("Name: %s\n", name);

    // 🧠 Let's update a few variables
    age = age + 1;
    gpa = 3.9;
    grade = 'B';

    printf("\n--- After Updates ---\n");
    printf("Updated Age: %d\n", age);
    printf("Updated GPA: %.2f\n", gpa);
    printf("Updated Grade: %c\n", grade);

    // ✅ DO: Use safe string initialization
    char safeString[] = "helloworld";  // Automatically sized
    printf("Safe string: %s\n", safeString);

    // ❌ DON'T: Avoid buffer overflow by not using undersized arrays
    // ⚠️ Removed unsafeString[5] to avoid undefined behavior
    // Instead, let’s demonstrate correct allocation:

    char sizedString[15] = "helloworld";  // 14 + 1 for null terminator
    printf("Correctly sized string: %s\n", sizedString);

    // ✅ Let's take user input too!
    int userAge;
    printf("\nEnter your age: ");
    scanf("%d", &userAge);
    printf("You entered: %d\n", userAge);

    // ✅ Calculating with user input
    int nextYearAge = userAge + 1;
    printf("Next year, you will be: %d\n", nextYearAge);

    return 0;
}
// This code demonstrates variable declaration, initialization, and usage in C.