#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    float x,y,z;
    for(y=1.5;y>-1.5;y-=0.1){
        for(x=-1.5;x<1.5;x+=0.05){
            z=x*x+y*y-1;
            putchar(z*z*z-x*x*y*y*y<=0.0?'*':' ');
        }
        system("color 0c");
        putchar('\n');
    }
    printf("                送给小王同学");
    printf("\n\n\n\n\n\n\n");
    getchar();
    return 0;
}
