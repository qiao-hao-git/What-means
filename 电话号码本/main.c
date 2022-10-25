#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info{
    char Name[20];
    char Tel[15];
    char Addr[50];
}Info;
Info people[20];

void Input(char *name,char *tel,char *addr,int count){
    int length1=strlen(name);
    int i;
    for(i=0;i<length1;i++){
        people[count].Name[i]=name[i];
    }
    int length2=strlen(tel);
    for(i=0;i<length2;i++){
        people[count].Tel[i]=tel[i];
    }
    int length3=strlen(addr);
    for(i=0;i<length3;i++){
        people[count].Addr[i]=addr[i];
    }
}

void serach(char *name){
    int length=sizeof(people)/sizeof(people[0]);
    int i;
    for(i=0;i<length;i++){
        if(strcmp(people[i].Name,name)==0){
            printf("%s %s %s",people[i].Name,people[i].Tel,people[i].Addr);
        }
    }
}

void sort(){
    int length=sizeof(people)/sizeof(people[0]);
    int i,j;
    char *temp1,*temp2;
    for(i=1;i<length;i++){
        for(j=0;j<length-i;j++){
            if(strcmp(people[j].Name,people[j+1].Name)>0){
                strcpy(temp1,people[j].Name);
                strcpy(temp2,people[j+1].Name);
                memset(people[j].Name,0,sizeof(people[j].Name));
                memset(people[j+1].Name,0,sizeof(people[j+1].Name));
                strcpy(people[j].Name,temp2);
                strcpy(people[j+1].Name,temp1);
                memset(temp1,0,sizeof(temp1));
                memset(temp2,0,sizeof(temp2));
            }
        }
    }
}
int main()
{

    return 0;
}
