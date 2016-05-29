#include <stdio.h>
#include <cs50.h>

int sum(int n) {
    if (n == 1) 
        return 1;
    else 
        return n + sum(n - 1);
}

int main(void) {
    int n;
    n = sum(GetInt());
    printf("\nSum: %i\n", n);
} 