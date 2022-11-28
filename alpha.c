#include "stdio.h"
#include "stdlib.h"
#include "graph.c"
#include "linkedlists.c"
#include "stack.c"
#include "queue.c"
#include "tree.c"

/*pizza store system where we store past orders in linked list,
                                    current orders in queue,
                                    menu card in trees,
                                    table status in graphs,
                                    total expenses in stacks.*/

/*typedef struct customer
{
    int id;
    int quantity;
    char name[20];
    char date[8];
    // char address[50];
} customer;*/



int main(){

    int option;
    node *head;
    customer data1;
    
    do{
        printf("------------------------------------\n");
        printf("Select operation:\n1)Place order    |   2)Dispatch order\n3)print orders   |   4)Previous orders\n5)View menu      |   6)Transact\n7)Table vacancy  |   8)Quit\n\n-> ");
        scanf("%d", &option);
        printf("------------------------------------\n");
        switch(option){
            case 1: placeOrder();
                    break;
            case 2: data1 = dispatchOrder();
                    head = create(data1.id, data1.quantity, data1.name, data1.date);
                    break;
            case 3: printOrders();
                    break;
            case 4: print(head);
                    break;
            case 5:
                    break;
            case 6:
                    break;
            case 7:
                    break;
            case 8: printf("Counter closed!");
                    break;
        }
    }while(option != 8);

    printf("\n\n");
    return 0;
}