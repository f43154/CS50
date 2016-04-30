#include <stdio.h>
#include <cs50.h>

int main(void) {
    int number = 0;
    while (number < 10)
        printf("%d\n", number += 2);
}