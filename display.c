#include "display.h"

void rules() {
    printf("=== MASTERMIND ===\n");
    printf("Find the %d-digit combination. Each digit is between 1 and %d.\n", SIZE_COMB, NB_COLORS);
    printf("Feedback rules:\n");
    printf(" 'o' : Correct digit and position\n");
    printf(" 'x' : Correct digit but wrong position\n");
    printf(" '-' : Wrong digit\n");
    printf("You have %d attempts. Good luck!\n", MAX_ATTEMPTS);
}

void init_grid(char * grid[]) {
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        grid[i] = (char *)malloc(18 * sizeof(char));
        strcpy(grid[i], "- - - - | - - - -");
    }
}

void free_grid(char * grid[]) {
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        free(grid[i]);
    }
}

void update_grid(char * grid[], int attempts, int propos[], char result[]) {
    for (int i = 0; i < SIZE_COMB; i++) {
        grid[attempts][i * 2] = propos[i] + '0';
        grid[attempts][10 + i * 2] = result[i];
    }
}

void display_grid(char * grid[]) {
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("Attempt %d: %s\n", i + 1, grid[i]);
    }
}
