#include <stdio.h>
#include <cs50.h>

int main() {
    int value = GetInt();
    const int values[16] = {0, 7, 21, 34, 47, 51, 89, 100, 121, 151, 191, 203, 500, 876, 981, 1000};
    const int n = 16;
    
    if (n < 1) {
        return false;
    } else if (values[0] == value) {
        printf("needle found\n");
        return true;
    } else {
        // FIND MIDPOINT
        int max = n-1;
        int min = 0;
        int midpoint = (max - min) / 2;
        // printf("vmx\tvmn\tmx\tmn\tmd\n");
        
        while (max != min) {
            midpoint = (max - min) / 2;
            
            // Reset boundaries depending...
            if (values[midpoint] > value) {
                max = midpoint;
                // printf("%d\t%d\t%d\t%d\t%d\n", values[max], values[min], max, min, midpoint);
                // printf("> needle not found\n");
            } else if (values[midpoint] != value) {
                printf("needle not found\n");  
                min = midpoint;
                return false;
            } else {
                printf("needle found\n");
                return true;
            }
        }
        printf("needle not found");
        return false;
    }
}