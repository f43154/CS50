#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    string s = GetString();
    for (int i = 0, n = strlen(s); i < n; i ++) {
        if (s[i] == ' ') {
            printf(" ");
        } else {
            printf("#");
        }
        // printf("%c", s[i]);
    }
}