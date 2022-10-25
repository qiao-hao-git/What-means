#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,M,x;
	cin>>N>>M;
    x=(int)pow(N-1,M)+(int)pow(-1,M)*(N-1);
    printf("%d",x/N);
    return 0;
}
