#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} my_node;

my_node *front, *rear;

void insert();
void delet();
void display();

int main(void)
{
    int choice;
    printf("Welcome to Kelvino's queue implementation using list\n");

    do{
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delet();
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
    } while(choice != 4);

    return (0);
}

void insert()
{
    my_node *temp;

    temp = malloc(sizeof(my_node));
    if (temp == NULL)
        printf("Queue Overflow!");
    else
    {
        printf("Enter the element to be inserted in the queue: ");
        scanf("%d", &temp->data);
        temp->link = NULL;
        if (rear == NULL)
            front = rear = temp;
        else
        {
            rear->link = temp;
            rear = temp;
        }
    }
}

void delet()
{
    my_node *temp;

    temp = front;
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        front = rear = NULL;
    }
    else
    {
        printf("The deleted element from the queue is %d\n", front->data);
        front = front->link;
        free(temp);
    }
}

void display()
{
    my_node *temp;

    temp = front;
    if (front == NULL)
        printf("Queue Underflow\n");
    else
    {
        printf("The elements of the stack are: \n");
        while (temp)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}
