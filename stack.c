#include "stdio.h"
#include "stdlib.h"


#define max 20

typedef struct stack{
    int data[max];
    int top;
}stack;

void init(stack *s){
    s->top = - 1;
}

int full(stack *s){
    return (s->top == max -1);
}

int empty(stack *s){
    return (s->top == -1);
}

int push(stack *s, int c){

    if(full(s)){
        printf("\nStack full!\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = c;
    return 1;
}


int pop(stack *s){
    if(empty(s)){
        printf("\nStack empty!\n");
        return -1;
    }
    s->top = s->top - 1;
    return s->data[s->top+1];

}
