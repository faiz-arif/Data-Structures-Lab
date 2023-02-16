#include<stdio.h>
//#include<conio.h>
#define N 5
int c,a,top=-1;
int stack[N];
void push();
void pop();
void topof();
void display();
void main()
{
//clrscr();
do
{
printf("OPTIONS\n 1:PUSH(insertion)\n 2:POP(Deletion)\n 3:top of the stack\n 4:display the stack\n 0: Exit\n");
scanf("%d",&a);
switch(a)
{
    case 1:push();
    break;
    case 2:pop();
    break;
    case 3:topof();
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
void push()
{
	if(top==N-1)
	{
		printf("Overflow\n");
	}
	else
	{
		int x;
		printf("Enter the element\n");
		top++;
		scanf("%d",&stack[top]);
	}
}
void pop()
{
	int item;
	if(top==-1)
	{
		printf("Underflow\n");
	}
	else
	{
		item=stack[top];
		top--;
		printf("Removed item %d\n",item);
	}
}
void topof()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("%d\n",stack[top]);
	}
}
void display()
{	
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		int i;
		for(i=top;i>-1;i--)
		printf("displaying element in stack %d \n",stack[i]);
	}
}

