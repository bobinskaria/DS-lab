#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    int value;
    struct node *newnode;

    newnode = (struct node*) malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nMemory not available! Cannot push.\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("Pushed %d\n", value);
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("\nStack Underflow! Cannot pop.\n");
        return;
    }

    temp = top;
    printf("Popped element = %d\n", temp->data);

    top = top->next;
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nTop element = %d\n", top->data);
    }
}


void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nStack elements:\n");
    temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}


int main()
{
    int choice;

    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
