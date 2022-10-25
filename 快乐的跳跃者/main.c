#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int *p=(int*)malloc(sizeof(int)*(n+1));
        int *q=(int*)malloc(sizeof(int)*(n+1));
        p=(int*)memset(p,0,sizeof(int)*(n+1));
        q=(int*)memset(q,0,sizeof(int)*(n+1));
        if(p==NULL||q==NULL){
            return  0;
        }
        else{
            for(int i=0;i<n;i++){
                scanf("%d",&p[i]);
            }
            for(int i=1;i<n;i++){
                q[abs(p[i]-p[i-1])]++;
            }
            int t=0;
            for(int i=1;i<n;i++){
                if(q[i]!=1){
                    t=1;
                    break;
                }
            }
            if(t==0){
                printf("Jolly\n");
            }
            else{
                printf("Not jolly\n");
            }
            free(p);
            free(q);
        }
    }
    return 0;
}
