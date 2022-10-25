#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node,*Ptr;

void Create_list(Ptr head){
    int i;
    for(i=0;i<=5;i++){
        Ptr p=(Ptr)malloc(sizeof(struct Node));
        if(p!=NULL){
            p->data=i;
            //printf("%d",p->data);
            p->next=head->next;
            head->next=p;
        }
        else{
            break;
        }
    }
}

void Inverse(Ptr L){
    Ptr q,p=L->next;
    L->next=NULL;
    while(p){
        q=p;
        p=p->next;
        q->next=L->next;
        L->next=q;
    }
}

void Input(Ptr head){
    int i;
    Ptr p=(Ptr)malloc(sizeof(struct Node));
    p=head->next;
    for(i=0;i<=5;i++){
       printf("%d",p->data);
       p=p->next;
    }
}
int main()
{
    Ptr head;
    head=(Ptr)malloc(sizeof(struct Node));
    head->next=NULL;
    Create_list(head);
    Input(head);
    Inverse(head);
    Input(head);
    return 0;
}
