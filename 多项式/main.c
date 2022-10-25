#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int index;
    struct Node *next;
}Node,*Ptr;


void Attach(int c,int e,Ptr *p){
    Ptr pn;
    pn=(Ptr)malloc(sizeof(struct Node));
    pn->data=c;
    pn->index=e;
    pn->next=NULL;
    (*p)->next=pn;
    *p=pn;
}

Ptr Read(){
    Ptr P,Rear,t;
    P=(Ptr)malloc(sizeof(struct Node));
    P->next=NULL;
    Rear=P;
    int N;
    scanf("%d",&N);
    int c,e;
    while(N--){
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    t=P;
    P=P->next;
    free(t);
    return P;
}
void Print(Ptr p){
    while(p){
        printf("%d %d",p->data,p->index);
        p=p->next;
    }
}

Ptr Add(Ptr P1,Ptr P2){
    Ptr front,rear,temp;
    int sum;
    rear=(Ptr)malloc(sizeof(struct Node));
    front=rear;
    while(P1&&P2){
        if(P1->index>P2->index){
            Attach(P1->data,P1->index,&rear);
            P1=P1->next;
        }
        if(P1->index<P2->index){
            Attach(P2->data,P2->index,&rear);
            P2=P2->next;
        }
        if(P1->index==P2->index){
            sum=P1->data+P2->data;
            if(sum){
                Attach(sum,P1->index,&rear);
            }
            P1=P1->next;
            P2=P2->next;
        }
    }
    for(;P1;P1=P1->next){
        Attach(P1->data,P1->index,&rear);
    }
    for(;P2;P2=P2->next){
        Attach(P2->data,P2->index,&rear);
    }
    rear->next=NULL;
    temp=front;
    front=front->next;
    free(temp);
    return front;
}
int main()
{
    Ptr p1,p2;
    p1=Read();
    p2=Read();
    Ptr p3=Add(p1,p2);
    Print(p3);
    return 0;
}
