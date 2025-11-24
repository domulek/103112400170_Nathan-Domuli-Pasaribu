#include "queue.h"
#include <iostream>
using namespace std;

void initQueue(Queue &Q) {
    Q.front = 0;
    Q.rear = -1;
}

bool isEmpty(const Queue &Q) {
    return Q.rear < Q.front;
}

bool isFull(const Queue &Q) {
    return Q.rear == MAX_QUEUE - 1;
}

void enqueue(Queue &Q, ItemType value) {
    if (!isFull(Q)) {
        Q.rear++;
        Q.data[Q.rear] = value;
    } else {
        cout << "Queue penuh!\n";
    }
}

ItemType dequeue(Queue &Q) {
    if (!isEmpty(Q)) {
        ItemType value = Q.data[Q.front];
        Q.front++;

        // Reset jika kosong
        if (Q.front > Q.rear) {
            Q.front = 0;
            Q.rear = -1;
        }
        
        return value;
    }
    cout << "Queue kosong!\n";
    return -1;
}

void printQueue(const Queue &Q) {
    cout << Q.front << " - " << Q.rear << " | ";

    if (isEmpty(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.front; i <= Q.rear; i++) {
        cout << Q.data[i] << " ";
    }
    cout << "\n";
}