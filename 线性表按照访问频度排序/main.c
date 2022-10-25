#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    int freq;
    struct Node *pre,*next;
}Node,*Ptr;

void Create_list(Ptr head){
    int i;
    Ptr p;
    for(i=0;i<=5;i++){
        p=(Ptr)malloc(sizeof(struct Node));
        if(p){
            p->data=i;
            p->freq=0;
            p->next=head->next;
            head->next=p;
            p->next->pre=p;
            p->pre=head;
        }
        else{
            break;
        }
    }
}

void Locate(Ptr head,int x){
    Ptr p=head->next;
    Ptr q;
    while(p&&p->data!=x){
        p=p->next;
    }
    if(p){
        p->freq++;
        q=p;
        if(p->pre){
            p->pre->next=p->next;
        }
        if(p->next){
            p->next->pre=p->pre;
        }
        p=q->pre;
        while(p!=head&&q->freq>p->freq){
            p=p->pre;
        }
        q->next=p->next;
        q->pre=p;
        if(p->next){
            p->next->pre=q;
        }
        p->next=q;
    }
    else{
        returnl;
    }
}

int main()
{

    return 0;
}
