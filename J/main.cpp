#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> good;
vector<long long> money;
int n,k;
long long sum1,sum2;
int main()
{
    int i;
    scanf("%d%d",&k);
    for(i=1;i<=n;i++){
        scanf("%lld",money[i]);
        sum1+=money[i];
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&good[i]);
        sum2+=goof[i];
    }
    if(sum2>sum1){
        printf("NIE\n");
    }
    else{

    }
    return 0;
}
