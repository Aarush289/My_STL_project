#include<stdio.h>
#include<stdlib.h>
struct data{
    int x;
    char y;
    struct data* next;
};
void printlist(struct data* head){
    if(head == NULL){return;}
    printf("%d\n",head->x);
    printlist(head->next);
}
char findthekey(structdata)
void addtofront(struct data** ptrhead,int n){
        if(n == 0){
            return;
        }
		struct data* temp;
		struct data* temp1=((*ptrhead));
		temp=(struct data*)malloc(sizeof(struct data));
		scanf("%d %c",&(temp->x),&(temp->y));
		temp->next=NULL;
		if((*ptrhead)==NULL){(*ptrhead)=temp;}
        else{
		while(temp1->next!=NULL){temp1=temp1->next;}
		temp1->next=temp;
        }
        addtoback(ptrhead, n-1);
}
int main(){
    int n;
    scanf("%d",&n);
    struct data *head = NULL;
    addtoback(&head ,n);
    int key;
    scanf("%d",&key);
    findthekey(head,key);
}