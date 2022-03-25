#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/BinarySearchTree.c"

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
    TreeNode *root = NULL;
    
    Employee *sally = (Employee *)malloc(sizeof(Employee));
    strcpy(sally->name, "sally");
    sally->age = 25;

    Employee *susan = (Employee *)malloc(sizeof(Employee));
    strcpy(susan->name, "susan");
    susan->age = 26;
    
    Employee *lorenzo = (Employee *)malloc(sizeof(Employee));
    strcpy(lorenzo->name, "lorenzo");
    lorenzo->age = 24;

    Employee *x0001 = (Employee *)malloc(sizeof(Employee));
    strcpy(x0001->name, "x0001");
    x0001->age = 24;

    Employee *x0002 = (Employee *)malloc(sizeof(Employee));
    strcpy(x0002->name, "x0002");
    x0002->age = 24;

    insert(&root, (int (*)(void *, void *))compareEmployee, sally);
    insert(&root, (int (*)(void *, void *))compareEmployee, susan);
    insert(&root, (int (*)(void *, void *))compareEmployee, lorenzo);
    insert(&root, (int (*)(void *, void *))compareEmployee, x0001);
    insert(&root, (int (*)(void *, void *))compareEmployee, x0002);

    printf("prevOrder\n");
    prevOrder(root, (void (*)(void *))(displayEmployee));

    printf("inOrder\n");
    inOrder(root, (void (*)(void *))(displayEmployee));

    printf("postOrder\n");
    postOrder(root, (void (*)(void *))(displayEmployee));

    printf("inOrder before delete\n");
    inOrder(root, (void (*)(void *))(displayEmployee));

    delete(&root, (int (*)(void *, void *))compareEmployee, sally);
    printf("inOrder after delete: sally\n");
    inOrder(root, (void (*)(void *))(displayEmployee));

    printf("find: lorenzo\n");
    TreeNode *x1 = find(root, (int (*)(void *, void *))compareEmployee, lorenzo);
    displayEmployee((Employee *)(x1->data));

    printf("find: min\n");
    TreeNode *xmin = findMin(root);
    displayEmployee((Employee *)(xmin->data));

    printf("find: max\n");
    TreeNode *xmax = findMax(root);
    displayEmployee((Employee *)(xmax->data));


    return 0;
}

