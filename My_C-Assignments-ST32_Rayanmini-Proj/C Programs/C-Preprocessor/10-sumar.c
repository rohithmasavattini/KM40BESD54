#include <stdio.h>
#define SUMARRAY(array,elements) \
int total=0,i;  \
for( i=0; i<elements ; i++) \
total += array[i]; \
printf( "%d", total );    

int main( void )
{
    int arr[5] = {1, 2, 3, 4, 5};

    printf( "The sum is: ");
    SUMARRAY(arr,5)
    printf("\n");

    return 0;
}

