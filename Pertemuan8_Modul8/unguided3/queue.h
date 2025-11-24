#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

typedef int ItemType;

struct Queue {
    ItemType data[MAX_QUEUE];
    int front;
    int rear;
};

void initQueue(Queue &Q);
bool isEmpty(const Queue &Q);
bool isFull(const Queue &Q);
void enqueue(Queue &Q, ItemType value);
ItemType dequeue(Queue &Q);
void printQueue(const Queue &Q);

#endif