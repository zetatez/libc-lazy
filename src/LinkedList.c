/* LinkedList.c
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"

void mkEmpty(LinkedList *linkedlist){
    linkedlist->head = NULL;
    linkedlist->tail = NULL;
}

void destroy(LinkedList *linkedlist){
    Node *tmp;
    Node *node = linkedlist->head;
    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
}

void addHead(LinkedList *linkedlist, void *data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if (linkedlist->head == NULL) {
        linkedlist->tail = node;
        node->next = NULL;
    } else {
        node->next = linkedlist->head;
    }
    linkedlist->head = node;
}

void addTail(LinkedList *linkedlist, void *data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (linkedlist->head == NULL) {
        linkedlist->head = node;
    } else {
        linkedlist->tail->next = node;
    }
    linkedlist->tail = node;
}

void insert(LinkedList *linkedlist, Node *destnode, void *data){
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;
    if (destnode == linkedlist->head) {
        tmp->next = linkedlist->head->next;
        linkedlist->head = tmp;
    } else {
        Node *node = linkedlist->head;
        while (node != NULL && node->next != destnode) {
            node = node->next;
        }

        if (node != NULL) {
            tmp->next = node->next;
            node->next = tmp;
        }
    }
}

void deleteNode(LinkedList *linkedlist, Node *nodetodelete){
    if (nodetodelete == linkedlist->head) {
        if (linkedlist->head->next == NULL) {
            linkedlist->head = linkedlist->tail = NULL;
        } else {
            linkedlist->head = linkedlist->tail;
        }
    } else {
        Node *node = linkedlist->head;
        while (node != NULL && node->next != nodetodelete) {
            node = node->next;
        }
        if (node != NULL) {
            node->next = nodetodelete->next;
        }
    }
    free(nodetodelete);
    nodetodelete = NULL;
}

int isEmpty(LinkedList *linkedlist){
    int res = (linkedlist->head == NULL) ? 1 : 0;
    return res;
}

int isHead(LinkedList *linkedlist, Node *node){
    int res = (linkedlist->head == node) ? 1 : 0;
    return res;
}

int isTail(LinkedList *linkedlist, Node *node){
    int res = (linkedlist->tail == node) ? 1 : 0;
    return res;
}

void *head(LinkedList *linkedlist){
    return linkedlist->head;
}

void *tail(LinkedList *linkedlist){
    return linkedlist->tail;
}

void *find(LinkedList *linkedlist, int (*compare)(void *, void *), void *data){
    Node *node = linkedlist->head;
    while (node != NULL && compare(node->data, data) != 0) {
        node = node->next;
    }
    return node;
}

void *findPrev(LinkedList *linkedlist, int (*compare)(void *, void *), void *data){
    Node *node = linkedlist->head;
    if (compare(linkedlist->head->data, data) == 0) {
        return NULL;
    }
    while (node->next != NULL && compare(node->next->data, data) != 0) {
        node = node->next;
    }
    return node;
}

void *findNext(LinkedList *linkedlist, int (*compare)(void *, void *), void *data){
    Node *node = linkedlist->head;
    while (node->next != NULL && compare(node->data, data) != 0) {
        node = node->next;
    }
    return node->next;
}

void displayLinkedList(LinkedList *linkedlist, void (*display)(void *)){
    printf("\nLinkedList\n");
    Node *current = linkedlist->head;
    while (current != NULL) {
        display(current->data);
        current = current->next;
    }
}

