#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const int LEN_ALPHABET = 26;
const int ASCII_UPPER = 65;
const int ASCII_LOWER = 97;

int main(int argc, string argv[]) {
    
    if (argc != 2) {
        printf("Try again using two arguments\n");
        return 1;
    }
    
    string key = argv[1];
    string plaintext = GetString();

    for (int i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] == ' ') {
            printf(" ");
        } else {
            for (int j = 0; j < strlen(plaintext); j++ ) {
                key = key[j];
            }
            printf("%c", key[i]);
        }
    }
    
    for (int j = 0; j < (strlen(plaintext)/strlen(key)); j++) {
        printf("%s", key);
    }
    
}