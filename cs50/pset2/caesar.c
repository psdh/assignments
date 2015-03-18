// Program to encrypt a given string via caesar encyption method : pset2 
// author : Prabhjyot Singh Sodhi
// This is cs50  :)

#include <stdio.h>
#include <cs50.h>
#include <string.h>
// for toupper and tolower functions 
#include <ctype.h> 

// for using command line argument 
int main(int argc, char* argv[])
{
    // argc must be 2 for making sure the key is entered
    if (argc != 2 )
    {
        printf("Error");
        return 1;
    }
    else
    {
        // conversion of string pointer to integer
        int k =  atoi(argv[1]);
        string inp = GetString();
        int n = strlen(inp);
        char encrp[n];
        
        for(int i = 0 ; i < n ; i++) 
        {
            // having different algorithms for capital and small 
            // and special symbols
            if (isupper(inp[i]))
            {
                encrp[i] = 65 + ( inp[i] + k - 65 ) % 26 ;
            }
            else
                if (islower(inp[i]))
            {
                encrp[i] = 'a' + ( inp[i] + k - 'a' ) % 26 ;
                
                }
                else
            {
                encrp[i] = inp[i] ;
            }
            
            printf("%c", encrp[i] );
        }    
        printf("\n");

    }
    return 0 ;
} 
