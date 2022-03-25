/* Queue.h
 *
 *
 * */
typedef struct _node{
    void *data;
    struct _node *next;
} Node;

typedef struct _queue{
    Node *head;
    Node *tail;
} Queue;

void makeEmptyQueue(Queue *queue);
void destroyQueue(Queue *queue);
void enqueue(Queue *queue, void *data);
void *dequeue(Queue *queue);
void displayQueueList(Queue *queue, void (*display)(void *));



