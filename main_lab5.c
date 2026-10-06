// LAB 5: DEMONSTRATION OF QUEUES
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct queue
{
    int front, rear;
    int data[SIZE];
};

typedef struct queue QUEUE;

void enqueue(QUEUE *q, int item)
{
    if(q->rear == SIZE - 1)
        printf("\n QUEUE FULL\n");
    else
    {
        q->rear = q->rear + 1;
        q->data[q->rear] = item;
        if(q->front == -1)
            q->front = 0;
    }
}

void dequeue(QUEUE *q)
{
    if(q->front == -1)
        printf("\n QUEUE EMPTY\n");
    else
    {
        printf("\n ELEMENT IS %d\n", q->data[q->front]);
        if(q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front = q->front + 1;
        }
    }
}

void display(QUEUE q)
{
    int i;
    if(q.front == -1)
    {
        printf("\n QUEUE EMPTY\n");
    }
    else
    {
        printf("\n CONTENT OF THE QUEUE:\n");
        for(i = q.front; i <= q.rear; i++)
        {
            printf("%d\t", q.data[i]);
        }
        printf("\n");
    }
}

int main()
{
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    int item, ch;

    for(;;)
    {
        printf("\n 1. INSERT \n 2. DELETE \n 3. DISPLAY \n 4. EXIT \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            printf("\n READ ELEMENT TO BE INSERTED: ");
            scanf("%d", &item);
            enqueue(&q, item);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
        default:
            printf("\n WRONG CHOICE TRY AGAIN\n");
        }
    }
    return 0;
}
