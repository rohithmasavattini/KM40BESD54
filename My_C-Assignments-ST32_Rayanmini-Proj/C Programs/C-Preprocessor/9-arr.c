#include <stdio.h>
#define SUMARRAY(array,elements) \
int i;  \
for( i=0; i<elements ; i++) \
printf("%d ",arr[i]);    

int main( void )
{
    int arr[5] = {1, 2, 3, 4, 5};

    printf( "elements of an array: ");
    SUMARRAY(arr,5)
    printf("\n");

    return 0;
}

