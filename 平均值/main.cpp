#include<cstdio>
#include<algorithm>
#define ll long long
#define mod (ll)1000000007

using namespace std;

ll fast_power(ll a,ll b)
{
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

int main()
{
    printf("%lld\n",fast_power(2,mod-2));
    return 0;
}
