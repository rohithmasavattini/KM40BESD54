#include <stdio.h>
int changed_endian(int num);
int main()
{
 int number=1;
 int new_number;
 new_number=changed_endian(number);
 printf("New number is %d", new_number);
 return 0;
}

int changed_endian(int num)
{
int byte0, byte1, byte2, byte3;
byte0 = (num & 0x000000FF) >> 0 ;
byte1 = (num & 0x0000FF00) >> 8 ;
byte2 = (num & 0x00FF0000) >> 16 ;
byte3 = (num & 0xFF000000) >> 24 ;
return((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));
}

