/* Stack.c
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

void makeEmptyStack(Stack *stack){
    stack->head = NULL;
    stack->tail = NULL;
}

void destroyStack(Stack *stack){
    Node *tmp;
    Node *node = stack->head;
    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
}

void push(Stack *stack, void *data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if (stack->head == NULL) {
        stack->tail = node;
        node->next = NULL;
    } else {
        node->next = stack->head;
    }
    stack->head = node;
}

void *pop(Stack *stack){
    Node *node = stack->head;
    void * data;
    if (stack->head == NULL) {
        data = NULL;
    } else if (stack->head == stack->tail) {
        stack->head = stack->tail = NULL;
        data = node->data;
        free(node);
        node = NULL;
    } else {
        stack->head = stack->head->next;
        data = node->data;
        free(node);
        node = NULL;
    }
    return data;
}

void displayStackList(Stack *stack, void (*display)(void *)){
    printf("\nStack\n");
    Node *current = stack->head;
    while (current != NULL) {
        display(current->data);
        current = current->next;
    }
}



