#include <stdio.h>
#include <cs50.h>

int fact(int n) {
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main(void) {
    int n;
    n = fact(GetInt());
    printf("Factorial: %i\n", n);
}