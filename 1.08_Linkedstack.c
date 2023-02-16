#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *Top=NULL;

void push()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter the data \n");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=Top;
    Top=newnode;
}
void pop()
{
    struct node* temp=Top;
    if(temp==NULL)
    {
        printf("stack underflow \n");
    }
    else
    {
        Top=Top->next;
        printf("Deleted Element :%d \n",temp->data);
        free(temp);
    }
}

void top()
{
    if(Top==NULL)
    {
        printf("stack Empty\n");
    }
    else
    {
        printf("Top  element :%d \n",Top->data);
    }
}

void display()
{
    if(Top==NULL)
    {
        printf("stack Empty \n");
    }
    else
    {
        printf("Stack using Linked List :\n");
        struct node *temp=Top;
        while(temp!=NULL)
        {
             printf(" %d ->",temp->data);  
             temp=temp->next;
        }
        printf("NULL \n");
    }
}
void main(){

	int choice;
	do{

	printf("Enter a choice : \n1.Push\n2.Pop\n3.Top\n4.Display\n0.Exit\n\n");
	scanf("%d",&choice);

	switch(choice){
		case 1 : {
				 push();
				 break;
			 }
		case 2: {
				pop();
				break;
			}
				case 3 : {
				 top();
				 break;
			 }
	
		case 4 : {
				 display();
				 break;
			 }
		case 0 :{
				printf("Exiting....!\n");
				break;
			}
		default : {
				  printf("Wrong input\n");
				  break;
			  }
	}
}while(choice != 0 );
}
