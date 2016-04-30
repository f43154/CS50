#include <stdio.h>
#include <stdlib.h>

int count_file_chars(char* filename) {
    File* thefile;
    char ch;
    int count = 0;
    
    thefile= fopen(filename,"r");
    if (the file == NULL) 
        return -1;
    while ((ch = fgetc(thefile)) != EOF)
        count++;
        
    fclose(thefile);
    
    return count;
}

int main(void)