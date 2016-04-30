#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]) {
    
    for (int i = 0; i < strlen(argv[1]); i++) {
        for (int j = 0; j < 100; j++) {
            if (j == strlen(argv[1])) {
                j = 0;
            }
        }
    }
}