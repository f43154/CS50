#include <stdio.h>
#include <cs50.h>

int main(void) {
    int num;
    do {
        printf("A positive number please: ");
        num = GetInt();
    } while (num < 1);
    
    int counter = 0;
    
    for (int i = 0; i < 1000; i++) {
        if (num == 1)
            num = 1;
        else if (num % 2 == 0) {
            num = num / 2;
            counter++;
            // printf("\nNumber divides by 2\n");
            // printf("Number = %i\n", num);
        } else {
            num = (3 * num) + 1;
            counter++;
            // printf("\nNumber divides by 3\n");
            // printf("Number = %i\n", num);
        }
    }
    
    printf("\nCounter = %i\n", counter);
    // printf("Number = %i\n", num);
}