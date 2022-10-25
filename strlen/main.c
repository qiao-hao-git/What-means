#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
   char c[100];
   fgets(c,100,stdin);
   int n=strlen(c);
   printf("%d\n",n);
    return 0;
}
