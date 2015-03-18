// Program to make a pyramid ( a right hand triangle,rather) using user input and loop constructs 
// author : Prabhjyot Singh Sodhi
// This is cs50  :)

#include <stdio.h>                    // for printf
#include <cs50.h>                    // for GetInt

int main(void)
{
    printf("Height : ");
    int ht = GetInt();
    
    // checking for valid input
    while(ht > 23 || ht < 0)
    {
        printf("Height : ");
        ht = GetInt();
    }
    
    // declaring loop counter variables
    int i, j, k ;
   
    for(i = 0 ; i < ht ;i++)
    {
        for( j = ht - i - 1 ; j > 0 ; j--)
        {
            printf(" ");
        }       
        for( k = ht - i - 2 ; k < ht ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    // returning zero assuring successful run 
    return 0 ;
}
