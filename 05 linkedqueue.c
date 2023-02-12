#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*rear=NULL,*front=NULL;
void enqueue(){
     int item;
     struct node *newnode=(struct node*)malloc(sizeof(struct node));
     printf("Enter the data :\n");
     scanf("%d",&newnode->data);
     newnode->next=NULL;
     if(front==NULL)
     {
        front=rear=newnode;
     }
     else
     {
         rear->next=newnode;
         rear=newnode;
     }
}
void dequeue(){
    if(front==NULL)
    {
        printf("UNDERFLOW...!\n");
    }
    else if(rear==front)
    {
        printf("Deleted element is: %d \n",front->data);
        free(front);
        front=rear=NULL;
    }
    else
    {
        printf("Deleted element is: %d \n",front->data);
        struct node *temp;
        temp=front;
        front=front->next;
        free(temp);
    }
}
void top(){
    if(front==NULL)
    {
        printf("Queue is empty...!\n");
    }
    else
    {
        printf("Front :%d \n",front->data);
    }
}
void display(){
    if(front==NULL)
    {
        printf("Queue is empty...!\n");
    }
    else
    {
        struct node *temp;
        temp=front;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
void main()
{
    int a;
    do
    {
        printf("OPTIONS\n 1:enqueue(insertion)\n 2:Dequeue(Deletion)\n 3:Front of the queue\n 4:display the quque\n 0: Exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:top();
            break;
            case 4:display();
            break;
            case 0:printf("Exiting\n");
            break;
            default:printf("invalid Entry\n");
            break;
        }  
    }while(a!=0);
}

