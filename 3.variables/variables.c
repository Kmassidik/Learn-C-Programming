#include <stdio.h>

int main() {
    // Declaring variables
    int age;
    float height;
    char letter;

    // Initializing variables
    age = 20;        // Use 'age' when you need to store someone's age in years (e.g., for a user profile or age-based access).
    height = 5.5;    // Use 'height' when you need to store a person's height in feet or meters (e.g., for health apps or sports stats).
    letter = 'B';    // Use 'letter' when you need to store a single character, like an initial or grade (e.g., for quizzes or names).

    // Printing variable values
    printf("My age is %d\n", age);
    printf("My height is %.1f feet\n", height);
    printf("My favorite letter is %c\n", letter);

    // Updating variables
    age = 21;        // Use 'age' again when the value changes, like a birthday update.
    height = 5.6;    // Use 'height' again when tracking growth or updated measurements.
    letter = 'C';    // Use 'letter' again when changing a preference, like a new favorite or updated grade.

    // Printing updated values
    printf("\nNow my age is %d\n", age);
    printf("Now my height is %.1f feet\n", height);
    printf("Now my favorite letter is %c\n", letter);

    return 0;
}