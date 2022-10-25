#include <iostream>
#include <vector>
#define maxn 200005
using namespace std;
int n,m;
int a[maxn],b[maxn];
struct ppp{
    int cnt=1;
    int k;
}p[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]%3==0){
            while(a[i]%3==0){
                p[i].k=a[i]/3;
                a[i]/=3;
                p[i].cnt*=3;
            }
        }
        else{
            p[i].k=a[i];
        }
    }
    int cnt;
    for(i=1;i<=m;i++){
        scanf("%d",&b[i]);
        cnt=0;
        for(j=1;j<=n;j++){
            cnt+=p[j].cnt;
            if(b[i]>cnt){
                continue;
            }
            if(b[i]<=cnt){
                printf("%d ",p[j].k);
                break;
            }
        }
    }
    return 0;
}
