#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define false 0
#define true 1

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *top = NULL;

bool isEmpty(){
    return top == NULL;
}

void push (int newValue) {
    if (isEmpty == true) {
        top = (node_t*) malloc(sizeof(node_t));
        top->data = newValue;
        top->next = NULL;
    } else {
        node_t *temp = (node_t*) malloc(sizeof(node_t));
        temp->data = newValue;
        temp->next = top;
        top = temp;
    }
}

int pop() {
    if (isEmpty() == false) {
        int popValue = top->data;
        top = top->next;
        return popValue;
    }
}

void printStack(){
    node_t *temp = top;
    if (!isEmpty()) {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main() {
    printf("Stack empty? %s\n\nPushing Values into stack:\n", isEmpty() == true ? "Yes" : "No"); //should be true
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printStack();
    printf("Stack empty? %s\n\nPopping Values off stack:\n", isEmpty() == true ? "Yes" : "No"); //should be false
    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());
    push(6);
    printStack();

    return 0;
}
