#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main() {
    
    int f, q = 0, d = 0, n = 0;
    float c = 0;
    
    do {
        
        printf("How much do you owe? ");
        c = GetFloat();
        f = (int) round(c * 100.00);
        
        if (f % 25 > 0 || f % 25 == 0) {
            //printf("***QUARTERS USED***\n");
            q = f/25;
            f = f % 25;
        };
        if (f % 10 > 0 || f % 10 == 0) {
            //printf("***DIMES USED***\n");
            d = f/10;
            f = f % 10;
        }; 
        if (f % 5 > 0 || f % 5 == 0) {
            //printf("***NICKELS USED***\n");
            n = f/5;
            f = f % 5;
        }; 
        // if (f % 1 > 0) {
        //      Not using the lines below because whatever is leftover after nickels is already in pennies
        //      printf("***PENNIES USED***\n");
        //      p = f/1;
        //      f = f % 1;
        // }
    } while (c < 0);        
    
    // printf("\nWe owe: $%.2f\n", c);
    // printf("Quarters: %d\nDimes: %d\nNickels: %d\nPennies: %d\n", q, d, n, f);
    // printf("TOTAL COINS: %d\n", q + d + n + f);
    printf("%d\n", q + d + n + f);    
}