/*�˶�Ա��ˮʱ����n����ί��֣�����Ϊ10���ƣ�������λС�����÷ֹ���Ϊ��ȥ����߷ֺ���ͷ֣���ʣ�·�����ƽ��ֵ�������˶�Ա�����յ÷֡�

Standard Input
�ж���������ݡ���һ��������T (T <= 100)����ʾ�������ݵ������������T��������ݡ�ÿһ���������ռһ�У��ֱ�Ϊ����n��n����ί�Ĵ�֣�������֮����һ���ո����У�2<n��100��

Standard Output
��Ӧÿ�����룬������˶�Ա�ĵ÷֣�����2λС����*/

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
