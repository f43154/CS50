#include <stdio.h>
#include <cs50.h>

int board[3][9];
int finish[3][9];

int main(int argc, string argv[]) {
    int d = atoi(argv[1]);
    int c = 0;
    int up = 1;
    int check = 0;

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            c++;
            board[i][j] = d*d - c;
            if (d*d % 2 == 0) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == 1) {
                    board[i][j] = 2;
                }
            }
            printf("\t%d", board[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");

    int check = 1;
    int counter = 1;    
    
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (board[i][j] == check) {
                check++;
                counter++;
            } else
                counter--;
        }
        if (counter == d*d - 1)
            return true;
    }
    return false;
}