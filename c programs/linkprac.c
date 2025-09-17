#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
};
void printlist(struct node* head){
    if(head==NULL){return;}
    printf("%d\t",head->data);
    printlist(head->next);
}
void reverse(struct node** ptr){
    struct node* pre=NULL;
    struct node* nex= (*ptr)->next;
    while(nex!=NULL){
        (*ptr)->next = pre;
        pre=(*ptr);
        (*ptr)=nex;
        nex=nex->next;
    }
    (*ptr)->next = pre;
}
void addtofront(struct node** ptr,int n){
    if(n==0){return;}
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&(temp->data));
    temp->next=*ptr ;
    *ptr = temp;
    addtofront(ptr , n-1);
}
int main(){
        int n;
        struct node* head=NULL;
        scanf("%d",&n);
        addtofront(&head , n);
        reverse(&head);
        printlist(head);
}