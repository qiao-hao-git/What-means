#include <iostream>

using namespace std;
int cal_a(int a,int b,int n);
int cal_b(int a,int b,int n);
int main()
{
    printf("%d",cal_a(1,1,3));
    return 0;
}
int cal_a(int a,int b,int n){
    while(n!=1){
        if(n%2==1){
            a=a*cal_a(a,b,n-1)+2*b*cal_b(a,b,n-1);
            b=a*cal_b(a,b,n-1)+b*cal_a(a,b,n-1);
        }
        else{
            a=a*a+2*b*b;
            b=2*a*b;
        }
    }
    return  a;
}
int cal_b(int a,int b,int n){
    while(n!=1){
        if(n%2==1){
            a=a*cal_a(a,b,n-1)+2*b*cal_b(a,b,n-1);
            b=a*cal_b(a,b,n-1)+b*cal_a(a,b,n-1);
        }
        else{
            a=a*a+2*b*b;
            b=2*a*b;
        }
    }
    return  b;
}
