#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    initQueue(Q);

    cout << "----------------------" << endl;
    cout << " F - R \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printQueue(Q);
    enqueue(Q, 5); printQueue(Q);
    enqueue(Q, 2); printQueue(Q);
    enqueue(Q, 7); printQueue(Q);
    dequeue(Q);    printQueue(Q);
    enqueue(Q, 4); printQueue(Q);
    dequeue(Q);    printQueue(Q);
    dequeue(Q);    printQueue(Q);

    return 0;
}