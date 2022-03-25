/* Stack.h
 *
 *
 * */
typedef struct _node{
    void *data;
    struct _node *next;
} Node;

typedef struct _stack{
    Node *head;
    Node *tail;
} Stack;

void makeEmptyStack(Stack *queue);
void destroyStack(Stack *queue);
void push(Stack *queue, void *data);
void *pop(Stack *queue);
void displayStackList(Stack *queue, void (*display)(void *));

