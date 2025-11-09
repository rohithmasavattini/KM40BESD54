#include<stdio.h>
int main()
{
        char ch;
        printf("Enter an alphabet :\n");
        scanf("%c",&ch);
        switch(ch>=97 && ch<=122 || ch>=65 && ch<=90)
        {
                case 1:
                        printf("Alphabet\n");
                        break;
                default:
                        printf("Not alphabet\n");
        }
        return 0;
}
