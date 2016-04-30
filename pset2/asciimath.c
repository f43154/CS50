#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        
        //Print out the instructions # of strings does not equal 2
        printf("Try inputing a second argument in command line\n");
        
        return 1;
    }
    
    int key = atoi(argv[1]);
    
    int letter = 'C';
    //Changing int letter = 'A' to anything changes the starting letter of the alphabet
    //'A' means compiler will look for the character A; MUST use single quotations
    
    printf("\nCalculating: %c + %d...\n", letter, key);
    
    int result = (letter + key);
    
    printf("The ASCII value of %c is %d.\n\n", result, result);
        
}