#include <stdio.h>
#include <cs50.h>

int main(int argc, char* argv[]) {
    int n = argc - 1;
    if (n < 0) {
        return 0;
    } else {
        int max = n-1;
        int min = 0;
        int midpoint = (max - min) / 2;
        printf("max = %d\nmin = %d\nmidpoint = %d\n", max, min, midpoint);
        return 0;
    }
}