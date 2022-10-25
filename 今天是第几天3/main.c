#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,year,month,day;
    int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d",&T);
    if(T>=1&&T<=200){
        while(T--){
            scanf("%d%d%d",&year,&month,&day);
            int i,sum=0;
            if(((year%4==0)&&(year%100!=0))||(year%400==0)){
                monthday[1]=29;
            }
            else{
                monthday[1]=28;
            }
            for(i=0;i<month-1;i++){
                sum+=monthday[i];
            }
            sum+=day;
            printf("%d\n",sum);
        }
    }
    return 0;
}
