#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

typedef struct node
{
    int data;
    struct node *next;
}my_node;

my_node *temp;

int main(void)
{
    int choice;
    printf("Welcome to Kelvino's Stack\n");
    printf("Stack implementation using linked lists in C\n");

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
                printf("Invalid choice\n");
                break;
        }
    }while(choice != 4);

    return (0);
}

void push()
{
    int data;

    my_node *ptr = malloc(sizeof(my_node));
    if (ptr == NULL)
        printf("Stack overflow\n");
    else
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);

        if (temp == NULL)
        {
            ptr->data = data;
            ptr->next = NULL;
            temp = ptr;
        }
        else
        {
            ptr->data = data;
            ptr->next = temp;
            temp = ptr;
        }
    }
}

void pop()
{
    int item;
    my_node *ptr;

    if (temp == NULL)
        printf("Stack underflow\n");
    else
    {
        item = temp->data;
        ptr = temp;
        temp = temp->next;
        free(ptr);
        printf("The deleted item is: %d\n", item);
    }
}

void display()
{
    my_node *ptr;

    ptr = temp;
    if (ptr == NULL)
        printf("Stack Underflow\n");
    else
    {
        printf("The elements of the struct are:\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
