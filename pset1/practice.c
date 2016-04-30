#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main() {
    int f;
    f = GetFloat();
    if (f % ((int)0.25) == 0) {
        f = f/0.25;
    } else {
        printf("The remainder is %d\n", f % 0.25);
    }
}