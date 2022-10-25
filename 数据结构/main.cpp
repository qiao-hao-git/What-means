#include <iostream>
#include <math.h>
void PrintN(int N){
    int i;
    for(i=1;i<=N;i++){
        printf("%d\n",i);
    }
    return;
}

void printN(int N){
    if(N){
        printN(N-1);
        printf("%d\n",N);
    }
    return;
}

double f(int n;double a[];double x){
    int i;
    double p=a[0];
    for(i=1;i<=n;i++){
        p+=(a[i]*pow(x,i))
    }
    return p;
}

double ff(int n;double a[];double x){
    int i;
    double p=a[n];
    for(i=n;i>=1;i--){
        p=x*p+a[i-1];
    }
    return p;
}
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    //printN(N);

    return 0;
}
