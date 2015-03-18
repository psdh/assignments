// Program to find denomination of the amount of money entered according to american currency system  
// author : Prabhjyot Singh Sodhi
// and This is cs50  :)

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    printf("how much change is owed");
    float amt = GetFloat();
 
    // checking for valid input
    while(amt < 0)
    {
        printf("oh hai, How much change is owed");
        amt = GetFloat();
    }
    
    // making intergral amount of money to be solved for
  
    amt = round( amt * 100 );
    
    int cents = amt ;
    int counter_tot = 0;
    int counter_ind;
    
    // starting with the largest denomination 
    // quaters
    if ( cents >= 25 )
    { 
        counter_ind = cents / 25;
        counter_tot += counter_ind;
        cents %= 25;
    }
    // dimes
    if ( cents >= 10 )
    {
        counter_ind = cents / 10;
        counter_tot += counter_ind;
        cents %= 10;
    }
    
    // nickels
    if ( cents >= 5 )
    {
        counter_ind = cents / 5;
        counter_tot += counter_ind;
        cents %= 5 ;
    } 
    
    // the remaining cents    
    counter_tot += cents;
   
    // Final answer just printing the value of the counter 
    // which is the same as the minimum number of coins 
    
    printf("%d\n", counter_tot );

  
    return 0 ;

}
