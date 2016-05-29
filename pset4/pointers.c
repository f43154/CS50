#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("Say something: ");
    char* s = GetString();
    
    if (s == NULL)
        return 1;
        
    for (int i = 0; i < strlen(s); i++) {
        printf("%c\n", *(s+i));
    }
    
    /*
    I've had this and it also works:
    for (int i = 0; i < sizeof(s); i++) {
        printf("%c\n", s[i]);
    }
    */
}