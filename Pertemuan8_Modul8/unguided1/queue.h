#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

typedef int ElementType;

struct Queue {
    ElementType data[MAX_QUEUE];
    int front;
    int rear;
};

void createQueue(Queue &Q);
bool isEmpty(const Queue &Q);
bool isFull(const Queue &Q);
void enqueue(Queue &Q, ElementType x);
ElementType dequeue(Queue &Q);
void printQueue(const Queue &Q);

#endif