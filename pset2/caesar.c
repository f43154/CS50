#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const int LEN_ALPHABET = 26;
const int ASCII_UPPER = 65;
const int ASCII_LOWER = 97;
//const means you can't change it; it's a global constant 
//Don't make global variables because your functions that rely on global variables can change global variables
//Replaces "LEN_ALPHABET" with 26 so you don't see a random number 26

int main(int argc, string argv[]) {
    
    //This makes sure two arguments are passed
    if (argc != 2) {
        printf("Try inputing a second argument in command line\n");
        return 1;
    }
    
    //1) GET THE KEY
    //Turn the second arugment argv[1] from string into integer
    int key = atoi(argv[1]);
    
    //2) GET THE PLAINTEXt; saved as "plaintext"
    string plaintext = GetString();
    //printf("This is the string of plaintext: %s\n", plaintext);
    
    //3) ENCIPHER plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        
        if (isupper(plaintext[i])) {
            
            //printf("upper");
            int upperletter = plaintext[i];
            int newascii = (upperletter + key);
            int ciphertext = (((newascii-ASCII_UPPER) % LEN_ALPHABET)+ASCII_UPPER);
            //4) PRINT CIPHER CHARACTER
            printf("%c", ciphertext);
            
        } else if (islower(plaintext[i])) {
            
            //printf("lower");
            int lowerletter = plaintext[i];
            // "newascii" is changing anyways so I can use the same name here
            int newascii = (lowerletter + key);
            int ciphertext = (((newascii-ASCII_LOWER) % LEN_ALPHABET)+ASCII_LOWER);
            //4) PRINT CIPHER CHARACTER
            printf("%c", ciphertext);
            
        } else {
            
            printf("%c", plaintext[i]);
            
        }
        
    }
    
    printf("\n");
    
}