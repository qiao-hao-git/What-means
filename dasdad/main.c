#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char    str1[]="cdef";
    char    str2[]="abcdefg";
    printf("%s",strstr(str2,str1)   );
    return 0;
}
