#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000
struct List{
    int Data[MaxSize];
    int length;
};
int BinarySearch(List Tbl,int K){
    int left,right,mid,NotFound=-1;
    left=1;
    right=Tbl->length;
    while(left<=right){
        mid=(left+right)/2;
        if(K<Tbl->Data[mid]){
            right=mid-1;
        }
        else if(K>Tbl->Data[mid]){
            left=mid+1;
        }
        else{
            return mid;
        }
    }
    return NotFound;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
