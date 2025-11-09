#include<stdio.h>
int main()
{
char ch;
printf("Enter a character :\n");
scanf("%c",&ch);
(ch>=65 && ch<=90)||(ch>=97 && ch<=122)? printf("Alphabet\n"):printf("not alphabet\n");  
        
		
return 0;
}

