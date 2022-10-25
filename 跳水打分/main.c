/*运动员跳水时，有n个评委打分，分数为10分制，且有两位小数。得分规则为：去掉最高分和最低分，求剩下分数的平均值，就是运动员的最终得分。

Standard Input
有多组测试数据。第一行是整数T (T <= 100)，表示测试数据的组数，随后有T组测试数据。每一组测试数据占一行，分别为整数n和n个评委的打分，相邻数之间有一个空格。其中，2<n≤100。

Standard Output
对应每组输入，输出该运动员的得分，保留2位小数。*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,T;
    double a[102];
    double t;
    scanf("%d",&T);
    if(T>0&&T<=100){
        while(T--){
            scanf("%d",&n);
            if(n>2&&n<=100){
                for(int i=0;i<n;i++){
                    scanf("%lf ",&a[i]);
                }
                for(int i=0;i<n-1;i++){
                    for(int j=0;j<n-1-i;j++){
                        if(a[j]<a[j+1]){
                           t=a[j];
                           a[j]=a[j+1];
                           a[j+1]=t;
                        }
                    }
                }
                double  sum=0.0;
                for(int i=1;i<n-1;i++){
                    sum+=a[i];
                }
                printf("%.2lf\t",sum/(n-2));
            }
        }
    }

    return 0;
}
