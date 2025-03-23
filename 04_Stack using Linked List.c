#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
int stackLimit; // Limit for the stack
int currentSize = 0; // Current number of elements in the stack

void push()
{
    if (currentSize == stackLimit)
    {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    if (scanf("%d", &newnode->data) != 1)
    {
        printf("Invalid input! Please enter a valid integer.\n");
        free(newnode);
        while (getchar() != '\n')
            ;
        return;
    }
    newnode->next = top;
    top = newnode;
    currentSize++;
    printf("%d pushed to stack\n", newnode->data);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        struct node *temp;
        temp = top;
        printf("Popped element: %d\n", temp->data);
        top = top->next;
        free(temp);
        currentSize--;
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        struct node *temp;
        temp = top;
        printf("Stack elements (top to bottom):\n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;
    printf("Enter the maximum limit for the stack: ");
    if (scanf("%d", &stackLimit) != 1 || stackLimit <= 0)
    {
        printf("Invalid input! Limit must be a positive integer.\n");
        return 1;
    }

    while (1)
    {
        printf("\n\nStack Operations Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number between 1 to 5.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program...Goodbye!\n");
            return 0;
        default:
            printf("Invalid input! Please enter a number between 1 to 5.\n");
        }
    }
}
