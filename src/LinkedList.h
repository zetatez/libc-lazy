/* LinkedList.h
 *
 *
 * */
typedef struct _node{
    void *data;
    struct _node *next;
} Node;

typedef struct _linkedlist{
    Node *head;
    Node *tail;
} LinkedList;

void makeEmptyLinkedList(LinkedList *linkedlist);
void destroyLinkedList(LinkedList *linkedlist);
void addHead(LinkedList *linkedlist, void *data);
void addTail(LinkedList *linkedlist, void *data);
void insert(LinkedList *linkedlist, Node *destnode, void *data);
void deleteNode(LinkedList *linkedlist, Node *node);
int isEmpty(LinkedList *linkedlist);
int isHead(LinkedList *linkedlist, Node *node);
int isTail(LinkedList *linkedlist, Node *node);
void *head(LinkedList *linkedlist);
void *tail(LinkedList *linkedlist);
void *find(LinkedList *linkedlist, int (*compare)(void *, void *), void *data);
void *findPrev(LinkedList *linkedlist, int (*compare)(void *, void *), void *data);
void *findNext(LinkedList *linkedlist, int (*compare)(void *, void *), void *data);
void displayLinkedList(LinkedList *linkedlist, void (*display)(void *));
