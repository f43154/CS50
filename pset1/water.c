#include <stdio.h>
#include <cs50.h>

int main() 
{
    printf("How many minutes are your showers? ");
    int showerTime = GetInt();
    printf("minutes:%d\nbottles:%d\n", showerTime, showerTime * 12);
}