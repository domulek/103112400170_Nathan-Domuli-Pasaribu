#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){
    Q.front = 0;
    Q.rear = 0;
}

bool isEmpty(const Queue &Q){
    return (Q.front == 0);
}

bool isFull(const Queue &Q){
    return (Q.rear == MAX_QUEUE);
}

void enqueue(Queue &Q, ElementType x){
    if(isFull(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }

    if(isEmpty(Q)){
        Q.front = Q.rear = 1;
        Q.data[0] = x;
    } else {
        Q.rear++;
        Q.data[Q.rear - 1] = x;
    }
}

ElementType dequeue(Queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }

    ElementType removed = Q.data[0];

    for(int i = 0; i < Q.rear - 1; i++){
        Q.data[i] = Q.data[i + 1];
    }

    Q.rear--;

    if(Q.rear == 0){
        Q.front = 0;
    }

    return removed;
}

void printQueue(const Queue &Q){
    int F, R;

    if(isEmpty(Q)){
        F = R = -1;
    } else {
        F = Q.front - 1;
        R = Q.rear - 1;
    }

    cout << F << " - " << R << " | ";

    if(isEmpty(Q)){
        cout << "empty queue";
    } else {
        for(int i = 0; i < Q.rear; i++){
            cout << Q.data[i] << " ";
        }
    }
    cout << endl;
}