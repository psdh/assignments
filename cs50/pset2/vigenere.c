// Program to encrypt a given string via vigenere encyption method : pset2 
// author : Prabhjyot Singh Sodhi
// This is cs50  :)

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// for using command line arguments

int main(int argc, char* argv[])
{
    // making sure that there are only a single keyword
    if (argc != 2)
    {
        printf("Error");
        return 1;
    }
    else
    {
        int i = 0;
        // storing keyword into a string variable
        string key = argv[1];
         
        int len = strlen(key);
        int flag = 0 ;  
    
        int key2[len];
        // making sure that the keyword does not contain any numerical values
        // making the new key2 that stores the 
        // individual keys as numerical value      
        for( i = 0; i < len ;i++)
        {
            if (isupper(key[i]))          
            {
                key2[i] = key[i] - 65; 
            }
            else
            if (islower(key[i]))
            {
                key2[i] = key[i] - 97;
            }
            else
            {
                if (isdigit(key[i]))
                {
                    flag = 1 ;
                }
            }    
        }
        
        // exiting program in case of wrong keyword
        if (flag == 1)
        {
            printf("Error");
            return 1;
        }
        else
        {
            int k =0;
            string to_be_enc =GetString();
     
            int len2  = strlen(to_be_enc);
    
            int j=0;
            // encrypting each letter and not changing any special symbols
            for(i = 0 , j = 0; i < len2 ; i++, j++)
            {
                k = j % len;
                
                if (isupper(to_be_enc[i]))
                {
                    to_be_enc[i] = 'A' + (to_be_enc[i] + key2[k] - 'A' ) % 26;
                }
                else
                if (islower(to_be_enc[i]))
                {
                    to_be_enc[i] = 'a' + (to_be_enc[i] + key2[k] - 'a' ) % 26;
                }
                else
                if (!isalpha(to_be_enc[i]))
                {
                    j--;
                } 
                printf("%c",to_be_enc[i]);
            }
        
            printf("\n");
            return 0 ;
        }   
    }
}   
