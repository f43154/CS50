#include <stdio.h>
#include <stdlib.h>

float add_floats(float first, float second) {
    return first + second;
}

int main(void) {
    float result = add_floats(3.14,1.62);
    printf("Result for 3.14 + 1.62: %0.2f\n", result);
    return 0;
}