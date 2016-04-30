#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main() {
    float a = GetFloat();
    float b = GetFloat();
    float c = GetFloat();
    float d = GetFloat();
    printf("Float = %.2f\n", a * 100);
    printf("a + b + c + d = %.2f\n", a + b + c + d);
    printf("a is %.2f\nb is %.2f\nc is %.2f\nd is %.2f\n", a, b, c, d);
}