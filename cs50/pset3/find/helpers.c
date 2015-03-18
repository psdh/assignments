/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // implementing binary search
    
    int flag =0;
    if (n < 0)
    {
        return false;
    }
    else
    {
        int mid;
        int low = 0, high = n - 1;
        // flag variable indicating whether element found or not 
        while ( low <= high)
        {
            mid = ( high + low ) / 2;
            if (values[mid] == value)
            {
                flag = 1;
                break;
            }
            else
                if (value > values[mid])
            {
                low = mid + 1 ;
            }
                else 
            {
                high = mid - 1;
            }
        }
        
        
        
    }
    // if flag is true implies that variable is found
    if (flag == 1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // implement an O(n^2) sorting algorithm  : Selection sort
    // here : implementint Selection sort
    int small, temp ;
    int pos;
    for( int i = 0; i < n ; i++)
    {
        small = values[i];
        pos = i;
        for(int j = i ;j < n ; j++)
        {
            if (values[j] < small)
            {
                small = values[j];
                pos = j;
            }
        }
        
        temp = values[i] ; 
        values[i] = small ;
        values[pos] = temp;
        
    }
      
}

  
