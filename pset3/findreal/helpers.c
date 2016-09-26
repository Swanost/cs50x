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

int findmiddle(int needle, int haystack[], int left, int right);

bool search(int needle, int haystack[], int size)
{
    // TODO: implement a searching algorithm
    int left = 0;
    int right = size - 1;
    if (left > right)
        return false;
    if (findmiddle(needle, haystack, left, right) == 0)
        return true;
    if (findmiddle(needle, haystack, left, right) != 0)
        return false;
    return 0;
}    

int findmiddle(int needle, int haystack[], int left, int right)
{
    int middle = (left + right) / 2;
    if (left > right)
        return -1;
    if (haystack[middle] == needle)
        return 0;
        
    if (haystack[middle] > needle)
    {
        return findmiddle(needle, haystack, left, middle - 1);
    }
    if (haystack[middle] < needle)
    {
        return findmiddle(needle, haystack, middle + 1, right);
    }

    return 0;
}

/**
 * Sorts array of n values.
 */
void sort(int haystack[], int size)
{
    int tmp;
    // TODO: implement an O(n^2) sorting algorithm
    if (haystack[size] == 1)
        return;
    else
        for (int x = 0 ; x < (size - 1); x++)
        {
            for (int y = 0; y < (size - x - 1); y++)
            {
                if (haystack[y] > haystack[y + 1])
                {
                    tmp = haystack[y];
                    haystack[y] = haystack[y + 1];
                    haystack[y + 1] = tmp;
                    
                }
                // printf("%i ", haystack[y]);
            }
            // printf("\n");
        }
}