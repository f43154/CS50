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
        printf("Please try again with two arguments\n");
        return 1;
     }
    
    // Input String
    string s = GetString();
    string k = argv[1];
    
    // Get String Lengths
    int s_len = strlen(s);
    int k_len = strlen(k);
    
    // Declare Int Representation
    int s_int[s_len];
    int k_int[k_len];
    
    // Convert s (ASCII) to Int
    for (int i = 0; i < s_len; i++) {
        s_int[i] = s[i];
    }
    
    // Loop through k
    for (int i = 0; i < k_len; i++) {
        // Convert k (ASCII) to Int
        k_int[i] = k[i];
        
        // Calculate key offset
        if (isupper(k_int[i])) 
            k_int[i] = k_int[i] - ASCII_UPPER;
        else 
            k_int[i] = k_int[i] - ASCII_LOWER;         
    }   
    
    // Declaring: Turn o_int into appropriate shifting number
    int o_int[s_len];
    
    // Add k to s = o
    int j = 0;
    
    for (int i = 0; i < s_len; i++) {
        o_int[i] = s_int[i];
        int s_off;
        
        // Calculate message offset
        if (isupper(s_int[i])) {
            s_off = ASCII_UPPER;
            o_int[i] = ((((s_int[i] - s_off) + k_int[(j % k_len)]) % LEN_ALPHABET ) + s_off ); // (((s - offset) + k) loop alpha) + offset
            j = (j + 1) % strlen(k);
        }    else if (islower(s_int[i])) {
            s_off = ASCII_LOWER;
            o_int[i] = ((((s_int[i] - s_off) + k_int[(j % k_len)]) % LEN_ALPHABET ) + s_off ); // (((s - offset) + k) loop alpha) + offset
            j = (j + 1) % strlen(k);
        } else
            printf(" ");
            
        // printf("%c = %d\n", o_int[i], o_int[i]);
        printf("%c", o_int[i]);
    }
    printf("\n");
}