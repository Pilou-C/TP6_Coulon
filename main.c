#include "mastermind.h"
#include "display.h"

int main () {
    srand(time(NULL));
    rules();
    
    char * grid[MAX_ATTEMPTS];
    init_grid(grid);
    
    int comb[SIZE_COMB];
    random_comb(comb);
    
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        printf("\n=> Attempt %d / %d\n", attempts + 1, MAX_ATTEMPTS);
        printf("Enter your %d digits separated by spaces: ", SIZE_COMB);
        
        int propos[SIZE_COMB];
        read_comb(propos);
        
        char result[SIZE_COMB];
        check_result(comb, propos, result);
        
        update_grid(grid, attempts, propos, result);
        display_grid(grid);
        
        if (well_placed(comb, propos) == SIZE_COMB) {
            printf("\nCongratulations! You cracked the code in %d attempts!\n", attempts + 1);
            break;
        }
        
        attempts++;
    }
    
    if (attempts == MAX_ATTEMPTS) {
        printf("\nYou lost! The correct combination was: ");
        display_comb(comb);
    }
    
    free_grid(grid);
    return 0;
}
