#include "queue.h"
#include <iostream>
using namespace std;

void initQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}

bool isEmpty(const Queue &Q) {
    return (Q.front == -1 && Q.rear == -1);
}

bool isFull(const Queue &Q) {
    return ((Q.rear + 1) % MAX_QUEUE == Q.front);
}

void enqueue(Queue &Q, ItemType value) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.front = 0;
        Q.rear = 0;
    } else {
        Q.rear = (Q.rear + 1) % MAX_QUEUE;
    }

    Q.data[Q.rear] = value;
}

ItemType dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    ItemType removed = Q.data[Q.front];

    if (Q.front == Q.rear) {
        Q.front = Q.rear = -1; // queue kembali kosong
    } else {
        Q.front = (Q.front + 1) % MAX_QUEUE;
    }

    return removed;
}

void printQueue(const Queue &Q) {
    cout << " " << Q.front << " - " << Q.rear << "\t | ";

    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
        return;
    }

    int i = Q.front;
    while (true) {
        cout << Q.data[i] << " ";
        if (i == Q.rear) break;
        i = (i + 1) % MAX_QUEUE;
    }

    cout << endl;
}