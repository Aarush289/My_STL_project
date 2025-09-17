#include<stdio.h>

#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void printlist(struct node* ptr){
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}

struct node* addtoFront(struct node* ptr,int key){
	struct node* tempPtr;
	tempPtr=(struct node*)malloc(sizeof(struct node));
	tempPtr->data=key;
	tempPtr->next=ptr;
	return tempPtr;}

int main(){
    int n;
	scanf("%d",&n);
	struct node* head=NULL;
    for(int i=0;i<n;i++){
		int input;
		scanf("%d",&input);
		head=addtoFront(head,input);
	}
    struct node* head2= head;
    while(head->data == head->next->data){
    while(head2->data == head2->next->data){
        head2=head2->next;
    }
    head= head2;
    }
    struct node* headp= head;
     head2=head2->next;
    while(head!=NULL){
        while(head2->next !=NULL && (head2->data != head2->next->data)){
            head2=head2->next;
        }
        if(head2==NULL){break;}
        while(head->next !=head2){
            head=head->next;
        }
        while(head2->next!= NULL &&  head2->data == head2->next->data){
            head2=head2->next;
        }
        if(head2->next !=NULL){head2=head2->next;head->next = head2;}
    }
    printlist(headp);
}