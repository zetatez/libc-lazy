
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/HashTable.c"

int main(int argc, char *argv[]) {
    HashTable *map = makeEmptyHashTable();

    set(map, "lorenzo", "28");
    set(map, "susan", "24");
    set(map, "sally", "24");

    char *val1 = (char *)get(map, "lorenzo");
    char *val2 = (char *)get(map, "sally");

    printf("%s\n", val1);
    printf("%s\n", val2);
    

    destroyHashTable(map);

    return 0;
}
