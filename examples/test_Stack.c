#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/Stack.c"

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
    Stack stack;


    Employee *loren = (Employee *)malloc(sizeof(Employee));
    strcpy(loren->name, "loren");
    loren->age = 24;

    Employee *sally = (Employee *)malloc(sizeof(Employee));
    strcpy(sally->name, "sally");
    sally->age = 25;

    Employee *susan = (Employee *)malloc(sizeof(Employee));
    strcpy(susan->name, "susan");
    susan->age = 26;
    

    makeEmptyStack(&stack);

    push(&stack, loren);
    displayStackList(&stack, (void (*)(void *))displayEmployee);
    push(&stack, sally);
    displayStackList(&stack, (void (*)(void *))displayEmployee);
    push(&stack, susan);
    displayStackList(&stack, (void (*)(void *))displayEmployee);

    Employee *data;
    data = (Employee *)pop(&stack);
    /* printf("\nthe data is \n"); */
    /* displayEmployee(data); */
    displayStackList(&stack, (void (*)(void *))displayEmployee);

    data = (Employee *)pop(&stack);
    /* printf("\nthe data is \n"); */
    /* displayEmployee(data); */
    displayStackList(&stack, (void (*)(void *))displayEmployee);
 
    data = (Employee *)pop(&stack);
    /* printf("\nthe data is \n"); */
    /* displayEmployee(data); */
    displayStackList(&stack, (void (*)(void *))displayEmployee);
    
    return 0;
}

