#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double  pi=acos(-1.0);
int a[22];
int b[22];
int main()
{
    int T,n,i;
    double r;
    while(T--){
        int sum=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        scanf("%lf",&r);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
             a[0]=a[n];
             for(i=0;i<n;i++){
                if(a[i]>a[i+1]){
                    b[i]=a[i]-a[i+1];
                }
            }
            for(i=0;i<n;i++){
                sum+=b[i];
            }
            if(sum==0){
                printf("Inf\n");
            }
            else{

            printf("%.3lf\n",2*pi*r/sum);
            }
    }
    return 0;
}
