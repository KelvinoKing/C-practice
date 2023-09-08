#include <stdio.h>
#include <stdlib.h>
#define LIMIT 5

int stack[LIMIT];
int top;
int i;
int choice;
void display();
void push();
void pop();

int main(void)
{
    top = -1;

    printf("Welcome to Kelvino's Stack\n");

    do{
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Sorry , invalid choice");
                break;
        }

    }while(choice != 4);

    return (0);
}

void display()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else if (top >= 0)
    {
        printf("The elements of the stack are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void push()
{
    int element;

    if (top == LIMIT - 1)
    {
         printf("Stack overflow\n");
    }
   else
    {
         printf("Enter the element to be inserted: ");
         scanf("%d", &element);
         top++;
         stack[top] = element;
    }
}

void pop()
{
    int __attribute__((unused)) element;

    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        element = stack[top];
        printf("The deleted item is: %d\n", stack[top]);
        top--;
    }
}
