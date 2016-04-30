#include <stdio.h>
#include <string.h>

int main(void) {
    
    string name = GetString();
    for (int i = 0, n = strlen(name); i < n; i++) {
        //if (name[i] == 0) {
            //capname = toupper(name[i]);
            printf("%s", toupper(name[i]));
        //}
    }
    
    printf("\n");
    
}