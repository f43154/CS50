#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "structs-0.h"

#define STUDENTS 3

int main(void) {
    // type  name of type with square brackets makes it an array
    student students[STUDENTS];
    
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student's name: ");
        students[i].name = GetString();
        
        printf("Student's house: ");
        students[i].house = GetString();
    }
    
    for (int i = 0; i < STUDENTS; i++) {
        printf("%s is in %s\n", students[i].name, students[i].house);
    }
    
    for (int i = 0; i < STUDENTS; i++) {
        free(students[i].name);
        free(students[i].house);
    }
}