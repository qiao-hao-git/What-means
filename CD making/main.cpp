#include <iostream>

using namespace std;

int main()
{
    int T,n,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        if(k<13){
            printf("%d\n",n/k+(n%k?1:0));
        }
        else    if(k==13){
            k=12;
            printf("%d\n",n/k+(n%k?1:0));
        }
        else    if(k==14){
            if(n%k==0){
                printf("%d\n",n/k);
            }
            else    if(n%k==13){
                printf("%d\n",n/k+2);
            }
            else{
                printf("%d\n",n/k+1);
            }
        }
        else{
            if(n==13){
                printf("2\n");
            }
            else    if(n%k==0){
                printf("%d\n",n/k);
            }
            else{
                printf("%d\n",n/k+1);
            }
        }
    }
    return 0;
}
