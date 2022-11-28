#include "stdio.h"
#include "stdlib.h"
//#include "linkedlists.c"


typedef struct customer
{
    int id;
    int quantity;
    char name[20];
    char date[8];
    // char address[50];
} customer;

customer data[100];
int rear = -1;
int front = -1;
int id = 1;

int isEmpty()
{
    if (rear == front)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == 2)
        return 1;
    else
        return 0;
}

void placeOrder()
{
    if (isFull() == 0)
    {
        rear++;
        data[rear].id = id++;
        printf("Enter date: ");
        scanf("%s", data[rear].date);
        printf("Enter name: ");
        scanf("%s", data[rear].name); // printf("Enter address:\n");
        // scanf("%s", data[rear].address);
        printf("Enter number of pizzas to deliver: ");
        scanf("%d", &data[rear].quantity);
    }
    else
        printf("Order is full!\n");
}

customer dispatchOrder()
{
    if (isEmpty() == 0)
    {
        front++;
        printf("\nDispatched order is:\n");
        printf("ID:\t%d\nName:\t%s\nQuantity:%d\n", data[front].id, data[front].name, data[front].quantity);
    }
    else
        printf("No more orders to be dispatched.\n");

    return data[front];
}

void printOrders()
{
    printf("The pending orders are:\n");
    for (int i = front + 1; i <= rear; i++)
    {
        printf("ID:\t%d\nName:\t%s\nQuantity:\t%d\n", data[i].id, data[i].name, data[i].quantity);
    }
}