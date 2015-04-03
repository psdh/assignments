#include <stdio.h>
#include <stdlib.h>


int* merge(int* a, int* b, int sa, int sb)
{
    int* c = (int *) malloc(sizeof(int)*(sa+sb));
    int i, j, k;
    i = j = k = 0;
    while( i < sa && j < sb)
    {
        if( a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while(i < sa)
        c[k++] = a[i++];
    while(j < sb)
        c[k++] = b[j++];
    return c;
}


int* mergesort(int* a, int size)
{
    if(size == 1)
        return a;

    int* first = mergesort(a, size/2);
    int* second = mergesort(a + size/2, size-size/2);
    return merge(first, second, size/2, size-size/2);
}


// will read values from the file and feed into fucntions
int main(int argv, char* argc[])
{
    FILE *fp;
    fp = fopen(argc[1], "r");

    int size;
    fscanf(fp, "%d\n", &size);
    int* arr = (int*) malloc(sizeof(int) * size);
 
    printf("%d\n", size);
    
    int i = 0;
   
    for(i = 0; i < size; i++)
        fscanf(fp, "%d", &arr[i]);
    
    fclose(fp);

    arr = mergesort(arr, size);
    
    fp = fopen("output", "w");

    for(i = 0; i < size; i++)
        fprintf(fp, "%d\n", arr[i]);

}
