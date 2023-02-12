#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int data,rear=-1,front=-1;

int isEmpty() {
	if (front == -1) 
		return 1;
	return 0;
}

int isFull() {
  	if ((front == rear + 1) || (front == 0 && rear == MAX - 1)) 
  		return 1;
	return 0;
}

void enQueue(int element){
	if (isFull())
    		printf("\n Queue is full!! \n");
  	else {
    		if (front == -1)
    			front = 0;
    		rear = (rear + 1) % MAX;
    		queue[rear] = element;
		printf("\n Inserted -> %d", element);
	}
}

void Top(){
	if(isEmpty()){
		printf("Queue is empty...! \n");
	}
	else{
		printf("Front ->%d \n ",queue[front]);	
	}
}

void display() {
	int i;
	if (isEmpty())
		printf(" \n Empty Queue\n");
	else {
		printf("\n Front -> %d ", front);
    		printf("\n Items -> ");
    		for (i = front; i != rear; i = (i + 1) % MAX) {
      			printf("%d ",queue[i]);
    		}
    		printf("%d ", queue[i]);
    		printf("\n Rear -> %d \n", rear);
  	}
}

void deQueue(){
	if (front == -1 && rear==-1) {
		printf("\n Queue is empty !! \n");
  	} 
  	else{
  		data = queue[front]; 
  		if(front==rear){
  			front=rear=-1;
  		}
  		else{
  			front = (front+1)%MAX;
  		}
  	}
    	printf("\n Deleted element -> %d \n", data);
}

void main(){
	int choice,element;
	printf("\n OPTIONS: \n1.Enqueue \n2.Display Queue\n3.Display Front\n4.Dequeue\n0.Exit\n");
	do{
		printf("\nEnter the choice :");
		scanf("%d",&choice);
		switch(choice){
			case 1 : {	printf("Enter the element:");
					scanf("%d",&element);
					enQueue(element);
					break;
				 }
			case 2 : {
					display();
					break;
				 }
			case 3 : {
					Top();
					break;
				 }
			case 4 : {
					deQueue();
					break;
				 }
			case 0 : {
					printf("\nExiting....!\n");
					break;
				 }
			default : {
					printf("\nWrong input\n");
					break;
				  }
		}
	}while(choice != 0 );
}
