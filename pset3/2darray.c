#include <cs50.h>
#include <stdio.h>

#define DIM_MIN 3
#define DIM_MAX 9
int array[DIM_MIN][DIM_MAX];

int main(int argc, string argv[]) {
    int d = atoi(argv[1]);
    int c = 0;

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            c++;
            array[i][j] = d*d - c;
            if (d*d % 2 == 0) {
                if (array[i][j] == 2) {
                    array[i][j] = 1;
                    printf("%d ", array[i][j]);
                } else if (array[i][j] == 1) {
                    array[i][j] = 2;
                    printf("%d ", array[i][j]);
                } else {
                    printf("%d ", array[i][j]);
                }
            } else {
                printf("%d ", array[i][j]);
            }
        }
        printf("\n");
    }
}