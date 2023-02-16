#include<stdio.h>
int q[100];

int front=-1,rear=-1;

void enq(int var)
{
    q[rear] = var;
    rear++;
}

void dq()
{
    q[front] = 0;
    front++;
}
int visited[6] = {0};

int main()
{

    int graph[6][6] = {{0,1,1,0,0,0},
                     {1,0,1,0,0,0},
                     {1,1,0,1,1,0},
                     {0,0,1,0,0,0},
                     {0,0,1,0,0,1},
                     {0,0,0,0,1,0}};



    enq(1);
    visited[0] = 1;
    while(front != rear)
    {
        int current = q[front];

        printf("%d ", current);
        dq();

        for(int i=0;i<6;i++)
        {

            if((graph[current-1][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1;
                enq(i+1);
            }
        }
    }
    printf("\n");
    return 0;
}



