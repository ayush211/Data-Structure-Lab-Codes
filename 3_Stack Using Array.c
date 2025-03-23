#include <stdio.h>
#include <stdlib.h>

int *stack = NULL; // Dynamic array for stack
int top = -1, max_size = 0;

void push()
{
    if (top == (max_size - 1))
    {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }

    printf("Enter data: ");
    if (scanf("%d", &stack[++top]) != 1)
    {
        printf("Invalid input! Please enter a valid integer.\n");
        top--;
        while (getchar() != '\n')
            return;
    }
    printf("Pushed %d onto the stack.\n", stack[top]);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! \n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements (Top to Bottom):\n");
        for (int i = top; i >= 0; i--)
        {
            printf("  %d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;
    printf("Enter the maximum size of the stack: ");
    if (scanf("%d", &max_size) != 1 || max_size <= 0)
    {
        printf("Invalid input! Maximum size must be a positive integer.\n");
        return 1;
    }

    stack = (int *)malloc(max_size * sizeof(int)); // Allocate memory for stack
    if (stack == NULL)
    {
        printf("Memory allocation failed!\n");
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
            printf("Exiting program. Goodbye!\n");
            free(stack); // Free allocated memory
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
