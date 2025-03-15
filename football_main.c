#include "football.h"
#include <stdio.h>


int main(int argc, char *argv[]) {
    int score;
    while (1) { // while loop to prompt the user to enter the score
        printf("Enter the NFL score\n(Enter 0 or 1 to STOP): "); 
        scanf("%d", &score);

        // Terminate the program if score is 0 or 1
        if (score == 0 || score == 1) {
            break;
        } else if (score < 0) { // if it is a negative number, prints an error message and continues the loop
            printf("Invalid score. Please enter a non-negative number.\n");
            continue;
        }

        // Call the function to print the combinations
        print_combinations(score);

        // Call the function to count the combinations and display the count
        int count = count_combinations(score);
        printf("Total combinations: %d\n", count);
    }

    return 0;
}