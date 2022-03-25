#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/LinkedList.c"

typedef struct _employee{
    char name[32];
    unsigned int age;
} Employee;

int compareEmployee(Employee *e1, Employee *e2) {
    return strcmp(e1->name, e2->name);
}

void  displayEmployee(Employee *employee) {
    printf("\t%s\t%d\n", employee->name, employee->age);
}

int main(int argc, char *argv[]) {
    LinkedList linkedlist;


    Employee *loren = (Employee *)malloc(sizeof(Employee));
    strcpy(loren->name, "loren");
    loren->age = 24;

    Employee *sally = (Employee *)malloc(sizeof(Employee));
    strcpy(sally->name, "sally");
    sally->age = 25;

    Employee *susan = (Employee *)malloc(sizeof(Employee));
    strcpy(susan->name, "susan");
    susan->age = 26;
    

    mkEmpty(&linkedlist);


    addHead(&linkedlist, loren);
    addHead(&linkedlist, sally);


    addTail(&linkedlist, susan);


    displayLinkedList(&linkedlist, (void (*)(void *))displayEmployee);


    Node *node = find(&linkedlist, (int (*)(void *, void *))compareEmployee, loren);
    printf("\nthe node is \n");
    displayEmployee((Employee *)(node->data));


    Employee *alan = (Employee *)malloc(sizeof(Employee));
    strcpy(alan->name, "alan");
    alan->age = 26;
    insert(&linkedlist, node, alan);
    displayLinkedList(&linkedlist, (void (*)(void *))displayEmployee);


    deleteNode(&linkedlist, node);
    displayLinkedList(&linkedlist, (void (*)(void *))displayEmployee);


    Node *nodesally = find(&linkedlist, (int (*)(void *, void *))compareEmployee, sally);
    Node *nodesusan = find(&linkedlist, (int (*)(void *, void *))compareEmployee, susan);
    printf("\nisHead\t%d\n", isHead(&linkedlist, nodesally));
    printf("\nisHead\t%d\n", isHead(&linkedlist, nodesusan));
    printf("\nisTail\t%d\n", isTail(&linkedlist, nodesally));
    printf("\nisTail\t%d\n", isTail(&linkedlist, nodesusan));


    Node *nodeprevalan = findPrev(&linkedlist, (int (*)(void *, void *))compareEmployee, alan);
    printf("\nthe node before alan \n");
    if (nodeprevalan != NULL) {
        displayEmployee((Employee *)(nodeprevalan->data));
    }

    
    Node *nodenextalan = findNext(&linkedlist, (int (*)(void *, void *))compareEmployee, alan);
    printf("\nthe node next alan \n");
    if (nodenextalan != NULL) {
        displayEmployee((Employee *)(nodenextalan->data));
    }


    displayLinkedList(&linkedlist, (void (*)(void *))displayEmployee);
    destroy(&linkedlist);

    return 0;
}




















