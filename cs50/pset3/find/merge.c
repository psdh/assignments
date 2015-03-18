#include <stdio.h>
#include <cs50.h>

int* merge( int a[] , int n , int b[] , int m  );
int* sort(int a[] , int n ) ;

int main(void)
{
    printf("Enter size of array to be sorted  :");
    int n = GetInt();
    
    int a[n];
    
    printf("\n Enter the elements of the array one by one \n");
    for(int i = 0 ; i < n ;i ++)
    {
        printf(" array[%d] : ? ", i);
        a[i] = GetInt();
    }
    
    int*c =  sort(a , n ) ; 
    
    for(int i =0 ; i < n ; i++ )
    printf("\n %d " , c[i]) ;
    return 0 ;    
     
}

int* merge( int a[] , int n , int b[] , int m  )
{
   int i =0 , j=0 , k=0;
   int* c = malloc( (m+n) * sizeof(int));
   for(; i < n && j < m ; k++ )
   {
      if(a[i] < b[j])
      {
        c[k] = a[i];
        i++;
      }
      else 
      {
        c[k] = b[j] ;
        j++; 
      }
   }
    
    while(j < m ) 
    {
        c[k] = b[j] ;
        j++;
        k++;
    }  
    while(i < n ) 
    {
        c[k] = a[i] ;
        i++;
        k++;
    }  
    return c;
}

int* sort(int a[] , int n ) 
{   
    if(n < 2 )
    return a ; 
    else
    {
        int* a1 = sort( a , n/2 );
        int* a2 = sort( a + n/2 ,n - n/2);
        int*c =merge(a1, n/2 , a2 , n - n/2);
        return c ;
    } 
}

