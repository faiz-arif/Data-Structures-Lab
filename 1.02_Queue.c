#include<stdio.h>
//#include<conio.h>
#define N 5
int a,rear=-1,front=-1;
int queue[N];
void enqueue();
void dequeue();
void top();
void display();
void main()
{
//clrscr();
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
//getch();
}
void enqueue()
{
	if(rear==N-1)
	{
		printf("Overflow\n");
	}
	
	else if(rear==-1 && front==-1)
	{
		rear=front=0;
		printf("Enter the element\n");
		scanf("%d",&queue[rear]);

	}
	else
	{
		rear++;
		printf("Enter the element\n");
		scanf("%d",&queue[rear]);
	}
}
void dequeue()
{
	if(rear==-1 && front ==-1)
	{
		printf("Underflow\n");
	}
	else if(front==rear)
	{
		printf("Removed item %d\n",queue[front]);
		front=rear=-1;
	}
	else
	{
		printf("Removed item %d\n",queue[front]);
		front++;
	}
}
void top()
{
	if(front==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("Front = %d\n",queue[front]);
	}
}
void display()
{
	int i;

	if(front==-1)
	{
		printf("queue is empty\n");
	}
	else
	{	
		printf("Queue -> ");
		for(i=front;i<=rear;i++)
		{
			printf(" %d ->",queue[i]);
		}
		printf(" NULL \n");
	}
	
}

