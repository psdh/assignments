/* Program to find out the total number of ways of making a stack of n ( input) cards with Red, Green and Blue cards if no 
 * green card can come on top of another green card.
 * Author : Prabhjyot Singh Sodhi ( 2013A7PS151P)
 * Solution based on the recursive relation  a(n) = 2[ a(n-1) + a ( n-2)]   {where a(n) stands for "a subscript n"}
 */
	
#include <stdio.h>
// Function Declarations

long long int solveG(int n);
long long int solveRB(int n);

// Function Definitions  

/* Function solveRB : int 
 * arguments : int n
 * This function tries to recursively find the total number of ways of placing(adding) n cards to the stack if there is no 
 * constraint that is the previous card is either Red or Blue.
 * Hence it returns 3(either of RGB) for the base case and returns 2*solveRB(n-1) + solveG(n-1) for the recursive case. 
 */

long long int solveRB( int n)
{
	if (n ==1)
		return 3;

	long long int a =2*solveRB(n-1);
	long long int b = solveG(n-1);
	
	return (a+b);
}

/* Function : solveG : int 
 * arguments : int n
 * This function tries to recursively find the number of ways placing(adding) n cards to the stack if the previous card
 * was Green.
 * Hence it returns 2(either R or B but not G) for the base case and return 2*solveRB(n-1) for the recursive case. 
 */

long long int solveG(int n )
{
	if( n ==1)
		return 2;

	return 2*solveRB(n-1);
}


int main(void)
{
	// Declaring and initialising variables
	int n=0;
	long long int count =0;
	
	printf("Enter size of stack for which the number of ways is to be evaluated : \n");
	
	// Accepting input from the user
	scanf("%d",&n);
	
	// computing answer with the use of recursive  functions 
	if(n ==1)
	count = 3;		
	else   
	count =  2*solveRB(n-1) + solveG(n-1);
	
	printf("The number of ways for a %d card stack is :   ",n);
	// Printing out the computed value
	printf("%lld\n",count);
}
