#include <stdio.h>
#include <cs50.h>

/* 

FOR THURSDAY MARCH 31st

    -Find out why i can't swap by doing:
    
    board[x1][y1] = tile; >> coordinates for blank tile replace value with user input "tile"
    board[x1][y1-1] = 0;  >> coordinates for the position in the board that equals "tile" is replaced with blank or 0
    


 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 
bool move(int tile)
{
    // TODO
    return false;
}

int tile
check whether tile is on edge
adjacent
    if (board[tilex + 1][tiley + 1] == tile)
        swap();
    else if ()
        swap();
    else if () 
        swap();
    else if () 
        swap();
    else
        Invalid move

void swap(int coordinatesX1, int coordinatesY1, int coordinatesX2, int coordinatesY2)
    swaps board[coordinatesX1][coordinatesY1] with board[coordinatesX2][coordinatesY2]
    
*/
#define DIM_MIN 3
#define DIM_MAX 9
int board[DIM_MIN][DIM_MAX];


int main(int argc, string argv[]) {
    int d = atoi(argv[1]);
    int c = 0;

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            c++;
            board[i][j] = d*d - c;
            printf("\t%d", board[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    int x1 = 0;
    int y1 = 0;
    
    int tile = GetInt();
    int zero = 0;

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            // CHECK IF TILE IS ON EDGE
            
            // Find and save cooredinates of _
            if (board[i][j] == zero) {
                x1 = i;
                y1 = j;

                // Check where tile is relative to _    
                if (board[x1+1][y1] == tile) {
                    // printf("right\n");
                    board[x1][y1] = tile;
                    board[x1+1][y1] = zero;
                    
                } else if (board[x1][y1+1] == tile) {
                    // printf("down\n");
                    board[x1][y1] = tile;
                    board[x1][y1+1] = zero;
                    
                } else if (board[x1][y1-1] == tile) {
                    // printf("left\n");
                    board[x1][y1] = tile;
                    board[x1][y1-1] = zero;
                    
                } else if (board[x1-1][y1] == tile) {
                    // printf("up\n");
                    board[x1][y1] = tile;
                    board[x1-1][y1] = zero;
                } else {
                    printf("Illegal move\n");
                    return 0;
                }
                
            }
        }
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            printf("\t%d", board[i][j]);
        }
        printf("\n");
    }
}