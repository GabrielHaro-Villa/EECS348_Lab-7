#include "football.h"
#include <stdio.h>

// Function that counts all the possible combinations
int count_combinations(int points) {
    int count = 0;

    // Loop that counts all the possible combinations
    for (int td2pt = 0; td2pt * 8 <= points; td2pt++) {
        for (int tdfg = 0; tdfg * 7 <= points - td2pt * 8; tdfg++) {
            for (int td = 0; td * 6 <= points - td2pt * 8 - tdfg * 7; td++) {
                for (int fg = 0; fg * 3 <= points - td2pt * 8 - tdfg * 7 - td * 6; fg++) {
                    for (int saf = 0; saf * 2 <= points - td2pt * 8 - tdfg * 7 - td * 6 - fg * 3; saf++) {
                        int total = td2pt * 8 + tdfg * 7 + td * 6 + fg * 3 + saf * 2;
                        if (total == points) {
                            count++;  // Increments count if the total is equal to the points
                        }
                    }
                }
            }
        }
    }
    return count;  // Returns the total count of combinations
}

// Function that prints all possible combinations
void print_combinations(int points) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", points);

    // Loop that prints all the possible combinations
    for (int td2pt = 0; td2pt * 8 <= points; td2pt++) {
        for (int tdfg = 0; tdfg * 7 <= points - td2pt * 8; tdfg++) {
            for (int td = 0; td * 6 <= points - td2pt * 8 - tdfg * 7; td++) {
                for (int fg = 0; fg * 3 <= points - td2pt * 8 - tdfg * 7 - td * 6; fg++) {
                    for (int saf = 0; saf * 2 <= points - td2pt * 8 - tdfg * 7 - td * 6 - fg * 3; saf++) {
                        int total = td2pt * 8 + tdfg * 7 + td * 6 + fg * 3 + saf * 2;
                        if (total == points) {
                            // Print the combination
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdfg, td, fg, saf);
                        }
                    }
                }
            }
        }
    }
}