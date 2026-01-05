#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void enqueue()
{
    int value;
    if (rear == SIZE - 1)
    {
        printf("\nQueue Overflow! Cannot enqueue.\n");
    }
    else
    {
        printf("Enter value to enqueue: ");
        scanf("%d", &value);

        if (front == -1)   // first element
            front = 0;

        rear++;
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow! Cannot dequeue.\n");
        front = rear = -1;   // reset queue
    }
    else
    {
        printf("Dequeued element = %d\n", queue[front]);
        front++;
        
        if (front > rear)   // queue becomes empty
            front = rear = -1;
    }
}

void peek()
{
    if (front == -1)
        printf("\nQueue is empty.\n");
    else
        printf("\nFront element = %d\n", queue[front]);
}


void display()
{
    int i;
    if (front == -1)
        printf("\nQueue is empty.\n");
    else
    {
        printf("\nQueue elements:\n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}


int main()
{
    int choice;

    while (1)
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek();    break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
