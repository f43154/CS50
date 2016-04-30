#include <cs50.h>
#include <stdio.h>

int main() {
    int array[5] = {4, 8, 1, 9, 2};
    int n = 5;
    
    for (int i = 0; i < n; i++) {
        printf("Before sort array[i] = %d\n", array[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    printf("After sort array[i] = %d\n", array[i]);
    }
}