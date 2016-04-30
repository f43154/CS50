#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const int LEN_ALPHABET = 26;
const int ASCII_UPPER = 65;
const int ASCII_LOWER = 97;

int main(int argc, string argv[]) {
    
    if (argc != 2) {
        printf("Try inputing a second argument in command line\n");
        return 1;
    }
    
    int key = atoi(argv[1]);
    string plaintext = GetString();
    
    for (int j = 0; j < strlen(argv[1]); j++) {
        
        if (isupper(key[j])) {
            int upperkey = (((key[j] - ASCII_UPPER) % LEN_ALPHABET) + ASCII_UPPER);
            
        } else if (islower(key[j])) {
            
            int lowerkey = (((key[j] - ASCII_LOWER) % LEN_ALPHABET) + ASCII_LOWER);
            
        } 
        
    }
    
    for (int i = 0; i < strlen(plaintext); i++) {
        
        if (isupper(plaintext[i])) {
            
            int upperletter = plaintext[i];
            int newascii = (upperletter + key[j]);
            int ciphertext = (((newascii-ASCII_UPPER) % LEN_ALPHABET)+ASCII_UPPER);
            printf("%c", ciphertext);
            
        } else if (islower(plaintext[i])) {
            
            int lowerletter = plaintext[i];
            int newascii = (lowerletter + key[j]);
            int ciphertext = (((newascii-ASCII_LOWER) % LEN_ALPHABET)+ASCII_LOWER);
            printf("%c", ciphertext);
            
        } else {
            
            printf("%c", plaintext[i]);
            
        }
        
    }
    
    printf("\n");
    
}