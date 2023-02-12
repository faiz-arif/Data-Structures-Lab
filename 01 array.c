#include<stdio.h>
int choice,i,n,big,small;
int s=0;
int ar[10];
void maximum();
void minimum();
void sum();
void mean();
void count();
void main(){
	printf("How many numbers do you want to inserted:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the number\n");
		scanf("%d",&ar[i]);
		s+=ar[i];
	}
	do{
		printf("OPTIONS\n 1:maximum\n 2:minimum\n 3:sum\n 4:mean\n 5:count 0: Exit\n");
		scanf("%d",&choice);
		switch(choice){
    			case 1:maximum();
    			break;
    			case 2:minimum();
    			break;
    			case 3:sum();
    			break;
    			case 4:mean();
    			break;
    			case 5:count();
    			break;
    			case 0:printf("Exiting\n");
   			break;
    			default:printf("invalid Entry\n");
    			break;
		}
	}while(choice!=0);
}

void maximum(){
	big=ar[0];
	for(i=0;i<n;i++)
	{
		if(ar[i]>big)
		{
			big=ar[i];
		}
	}
	printf("maximum number is %d\n",big);
}

void minimum(){
	small=ar[0];
	for(i=0;i<n;i++)
	{
		if(ar[i]<small)
		{
			small=ar[i];
		}
	}
	printf("minimum number is %d\n",small);
}

void sum(){
	printf("sum=%d\n",s);
}

void mean(){
	printf("mean=%f \n",(float)s/n);
}

void count(){
	printf("totoal count %d\n",n);
}
