/* Queue.c
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

void makeEmptyQueue(Queue *queue){
    queue->head = NULL;
    queue->tail = NULL;
}

void destroyQueue(Queue *queue){
    Node *tmp;
    Node *node = queue->head;
    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
}

void enqueue(Queue *queue, void *data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if (queue->head == NULL) {
        queue->tail = node;
        node->next = NULL;
    } else {
        node->next = queue->head;
    }
    queue->head = node;
}

void *dequeue(Queue *queue){
    Node *node = queue->head;
    void * data;
    if (queue->head == NULL) {
        data = NULL;
    } else if (queue->head == queue->tail) {
        queue->head = queue->tail = NULL;
        data = node->data;
        free(node);
    } else {
        while (node->next != queue->tail) {
            node = node->next;
        }
        queue->tail = node;
        node = node->next;
        queue->tail->next = NULL;
        data = node->data;
        free(node);
        node = NULL;
    }
    return data;
}

void displayQueueList(Queue *queue, void (*display)(void *)){
    printf("\nQueue\n");
    Node *current = queue->head;
    while (current != NULL) {
        display(current->data);
        current = current->next;
    }
}



