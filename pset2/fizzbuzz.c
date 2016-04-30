#include <stdio.h>
#include <cs50.h>

int main(void) {
    for (int i = 100; i > 0; i--) {
        if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", i);
        }
    }
}