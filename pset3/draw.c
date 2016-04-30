#include <stdio.h>
#include <cs50.h>

#define DIM_MIN 3
#define DIM_MAX 9
int array[DIM_MIN][DIM_MAX];

int main(int argc, string argv[]) {
    int d = atoi(argv[1]);
    printf("  ");

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (board[i][j] == 0) {
                printf("  _");
            } else if (board[i][j] < 10) {
                printf("  %d", board[i][j]);
            } else {
                printf(" %d", board[i][j]);
            }
        }
        printf("\n  ");
    }
}