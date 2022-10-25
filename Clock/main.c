#include <stdio.h>

int main()
{
    int T,HH,MM,sh,sm,angle;
    scanf("%d",&T);
    while(T--){
        scanf("%d:%d",&HH,&MM);
        if(HH>=12){
            HH=HH-12;
        }
        sh=HH*60+MM;
        sm=MM*12;
        if(sh>sm){
            angle=sh-sm;
        }
        else{
            angle=sm-sh;
        }
        if(angle>=360){
            angle=720-angle;
        }
        if(angle%2==0){
            printf("%d\n",angle/2);
        }
        else{
        printf("%d/2\n",angle);
        }
    }
    return 0;
}
