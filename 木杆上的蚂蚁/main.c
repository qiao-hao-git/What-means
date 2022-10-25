#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ants{
    int pos;
    char name[11];
}a[110];

struct event{
    char dir[2];
    int time;
}e[110];

int pos_cmp(const void* p,const void* q){
    struct ants *pp=(ants *)p;
    struct  ants    *qq=(ants   *)q;
    return ((pp->pos)>(qq->pos)?1:-1);
}

int time_cmp(const void* p,const void* q){
    struct event *pp=(event *)p;
    struct  event    *qq=(event   *)q;
    return ((pp->time)>(qq->time)?1:-1);
}

int main()
{
    int T,N,L,k=1;
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        memset(e,0,sizeof(e));
        scanf("%d%d",&N,&L);
        for(int i=0;i<N;i++){
            getchar();
            scanf("%s%d%s",a[i].name,&a[i].pos,e[i].dir);
        }
        for(int i=0;i<N;i++){
            if(e[i].dir[0]=='R'){
                e[i].time=L-a[i].pos;
            }
            else{
                e[i].time=a[i].pos;
            }
        }
        qsort(a,N,sizeof(a[0]),pos_cmp);
        qsort(e,N,sizeof(e[0]),time_cmp);
        printf("Case #%d:\n",k++);
        int l=0,r=N-1;
        for(int i=0;i<N;i++){
            if(e[i].dir[0]=='L'){
                printf("%d %s\n",e[i].time,a[l].name);
                l++;
            }
            else    if(e[i].dir[0]=='R'){
                printf("%d %s\n",e[i].time,a[r].name);
                r--;
            }
        }
    }
    return 0;
}
