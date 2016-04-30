/*
    For Sunday Coffee & Code (March 20):
    -Figure out why Binary Search doesn't find a needle
        *Linear search works
        *./generate 1000 50 | ./find 127 should find needle
        *./generate 1000 50 | ./find 128 should not find needle
        
*/

/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n) {
    // TODO: implement a searching algorithm

    // LINEAR SEARCH
    // if (n < 0) 
    //     return false;
    // else {
    //     for (int i = 0; i < n; i++) {
    //         if (value == values[i]) 
    //             return true;
    //     }            
    // }
    // return false;

    // BINARY SEARCH
    if (n < 1) {
        return false;
    } else if (values[0] == value) {
        return true;
    } else {
        // FIND MIDPOINT
        int max = n-1;
        int min = 0;
        int midpoint = (max - min) / 2;
        // printf("vmx\tvmn\tmx\tmn\tmd\n");
        
        while (max != min) {
            midpoint = (max - min) / 2;
            // printf("%d\t%d\t%d\t%d\t%d\n", values[max], values[min], max, min, midpoint);
            // Reset boundaries depending...
            if (values[midpoint] > value) {
                max = midpoint;
            } else if (values[midpoint] != value) {
                min = midpoint;
                return false;
            } else {
                return true;
            }
        }
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (values[j] < values[i]) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }    
}