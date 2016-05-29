#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    printf("Say something: ");
    string s = GetString();
    if (s == NULL) {
        return 1;
    }
    
    string t = malloc((strlen(s) + 1) * sizeof(char));
    if (t == NULL) {
        free(s);
        return 1;
    }
    
    for (int i = 0; i <= strlen(s); i++) {
        t[i] = s[i];
    }
    
    printf("Capitalizing copy...\n");
    if (strlen(t) > 0) {
        t[0] = toupper(t[0]);
    }
    printf("Original: %s\n", s);
    printf("Copy:     %s\n", t);
}