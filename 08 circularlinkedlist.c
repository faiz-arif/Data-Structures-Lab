#include<stdio.h>
#include<stdlib.h>

int i,n;

struct node{
	int data;
	struct node *next;
};

struct node *last=NULL,*current,*temp,*newnode;

void insertion(){
	printf("how many data do you want to insert\n");
	scanf("%d",&n);
	printf("Enter the data\n");
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		if(last==NULL)
		{
			last=newnode;
			newnode->next=last;
		}
		else
		{
			newnode->next=last->next;
			last->next=newnode;
			last=newnode;
		}
	}
}

void traverse(){
	int count=0;
	if(last==NULL){
		printf("List is empty.....!\n");
	}
	else{
		current=last->next;
		do 
		{
			printf("%d->",current->data);
			current=current->next;
			count++;
		}while(current!=last->next);
		printf("NULL\n");
		printf("Total elements in the data :%d\n",count);
	}
}

void search(){
	int item,pos=0,flag=0;
	if(last==NULL)
	{
		printf("Linked list is empty..!\n");
	}
	else
	{
		printf("Enter the data to search :\n");
		scanf("%d",&item);
		current=last->next;
		do
		{
			pos++;
			if(current->data==item)
			{
				printf("Item found on %d th position\n",pos);
				flag=1;
				break;
			}
			current=current->next;
		}while(current!=last->next);
		if(flag==0)
		{
			printf("item not found \n");
		}
	}
}

void addend(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&newnode->data);
	if(last==NULL)
	{
		last=newnode;
		newnode->next=last;
	}
	else
	{
		newnode->next=last->next;
		last->next=newnode;
		last=newnode;
	}
}

void addspec(){
	struct node *ptr;
	int item;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&newnode->data);
	printf("insert data after:");
	scanf("%d",&item);
	if(last==NULL)
	{
		last=newnode;
		newnode->next=last;
	}
	else
	{
		ptr=last->next;
		while(ptr->data!=item && ptr->next!=last)
		{
			ptr=ptr->next;
		}
		newnode->next=ptr->next;
		ptr->next=newnode;
	}
}

void addbeg(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&newnode->data);
	if(last==NULL)
	{
		last=newnode;
		newnode->next=last;
	}
	else
	{
		newnode->next=last->next;
		last->next=newnode;
	}
}

void deleteend(){
	if(last==NULL)
	{
		printf("Linked list UNDERFLOW...!");
	}
	else if(last==last->next)
	{
		printf("Deleted element :%d \n",last->data);
		free(last);
		last=NULL;
	}
	else
	{	current=last->next;
		while(current->next!=last)
		{
			current=current->next;
		}
		printf("Deleted element :%d \n",last->data);
		current->next=last->next;
		free(last);
		last=current;
	}
}

void deletespec(){
	struct node *preptr,*ptr;
	int item;
	if(last==NULL)
	{
		printf("Linked list undeflow");
	}
	else
	{
		ptr=last->next;
		preptr=ptr;
		printf("Enter the  previous element\n");
		scanf("%d",&item);
		while(preptr->data!=item && ptr!=last)
		{
			preptr=ptr;
			ptr=ptr->next;
			if(ptr==last)
			return;
		}
		temp=ptr;
		printf("Deleted element :%d \n",temp->data);
		preptr->next=ptr->next;
		free(temp);
	}
}

void deletebeg(){
	if(last==NULL)
	{
		printf("Linked list UNDERFLOW...!");
	}
	else if(last==last->next)
	{
		printf("Deleted element :%d \n",last->data);
		free(last);
		last=NULL;
	}
	else
	{
		current=last->next;
		printf("Deleted element :%d \n",current->data);
		last->next=current->next;
		free(current);
	}
}

void main()
{
	int choice;
	do{
		printf("\nOPTIONS\n 1:insertion\n 2:traversing\n 3:searching\n 4:addition at end \n 5:additon after a specific element\n 6:addtion at the beginning\n 7:deltion at the end\n 8:deletion after specific element\n 9:deletion at the beginning  0: Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
    			case 1:insertion();
    				break;
    				
    			case 2:traverse();
    				break;
    			
    			case 3:search();
    				break;
    			case 4:addend();
    				break;
    			case 5:addspec();
    				break;
    			case 6:addbeg();
    				break;
    			case 7:deleteend();
    				break;
    			case 8:deletespec();
    				break;
    			case 9:deletebeg();
    				break;
    			case 0:printf("Exiting\n");
    				break;
    			default: printf("invalid Entry\n");
    				break;
		}
	}while(choice!=0);
}
