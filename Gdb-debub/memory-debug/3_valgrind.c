/* This Program That Tries to Access Memory Beyond the End of an Array */

#include <stdlib.h>
#include <stdio.h>

 int main(void)
 {
  char *chptr;
  char *chptr1;
  int i  = 0;
  chptr  = (char *) malloc(512);
  chptr1 = (char *) malloc (512);
      for (i; i <= 511; i++)  {
       chptr[i] = '?';
       chptr1[i] = chptr[i];
    }

  free(chptr1);
  free(chptr);

}
