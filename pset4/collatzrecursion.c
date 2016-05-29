#include <stdio.h>
#include <cs50.h>

int collatz(int num) {
    if (num == 1) {
        return 0;
    } else if (num % 2 == 0) {
        return 1 + collatz(num/2);
        // counter++;
        printf("\nNumber divides by 2\n");
        printf("Number = %i\n", num);
    } else {
        return 1 + collatz(3*num + 1);  
        // counter++;   
        printf("\nNumber divides by 3\n");
        printf("Number = %i\n", num);   
        
    }
}

int main(void) {
    int num;
    do {
        printf("A positive number please: ");
        num = GetInt();
    } while (num < 1);

    num = collatz(num);

    // printf("\nCounter = %i\n", counter);
    printf("\nNumber = %i\n", num);
}