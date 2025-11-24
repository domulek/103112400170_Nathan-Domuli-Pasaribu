# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Nathan Domuli Pasaribu - 103112400170</p>

## Dasar Teori
Struktur data merupakan cara untuk menyimpan serta mengatur data sehingga proses akses dan pengolahannya dapat dilakukan secara efisien [1]. Dalam bidang pemrograman, struktur data berfungsi untuk menata data agar lebih terstruktur, sehingga berbagai operasi seperti pencarian, penyimpanan, dan penghapusan dapat dilakukan dengan lebih optimal [2]. Salah satu struktur data yang sering digunakan adalah Queue, yaitu struktur data yang bekerja mengikuti prinsip First In First Out (FIFO), di mana elemen yang pertama masuk akan menjadi elemen pertama yang diproses [3].

### A. Queue

Queue merupakan struktur data linear yang mengikuti prinsip FIFO, di mana elemen yang masuk terlebih dahulu akan menjadi elemen pertama yang diproses. Operasi utamanya meliputi enqueue untuk menambah elemen dan dequeue untuk menghapus elemen. Struktur queue dapat dibangun menggunakan array maupun linked list. Pada implementasi berbasis array, konsep circular queue sering dimanfaatkan agar penggunaan memori lebih optimal. Struktur data ini banyak digunakan dalam berbagai aplikasi komputer, seperti antrian proses pada CPU, buffer penyimpanan data, serta algoritma pencarian seperti BFS.


## Guided 

### 1. Guided 1

queue.h 

```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    int dataAngka;
    address next;
} ;

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchQueue(queue Q, int data);

#endif
```
queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchQueue(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah updateQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchQueue(Q, 4);
    searchQueue(Q, 9);

    return 0;
}
```
Program ini mengimplementasikan struktur data queue menggunakan linked list pada bahasa C++. Di dalamnya tersedia fungsi-fungsi seperti menambah elemen (enqueue), menghapus elemen (dequeue), memperbarui data, mencari data, serta menampilkan seluruh isi queue. Semua operasi dijalankan berdasarkan konsep FIFO (First In First Out) dan memanfaatkan alokasi memori dinamis sehingga elemen dapat ditambahkan atau dihapus sesuai kebutuhan.

### 2. Guided 2

queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}


void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; 
        int n = 0; 
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);

    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" <<  endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Program ini menerapkan struktur queue statis berbasis array dengan mekanisme circular queue. Fitur yang tersedia mencakup penambahan elemen (enqueue), penghapusan elemen (dequeue), pemeriksaan apakah queue dalam kondisi penuh atau kosong, serta penampilan seluruh data di dalamnya. Seluruh proses mengikuti konsep FIFO (First In First Out).


## Unguided 

### 1. Unguided 1

queue.h
```C++
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
```

queue.cpp
```C++
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
```

main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;
    createQueue(Q);

    cout << "-------------------------" << endl;
    cout << " F - R | Queue Content" << endl;
    cout << "-------------------------" << endl;

    printQueue(Q);
    enqueue(Q, 5); printQueue(Q);
    enqueue(Q, 2); printQueue(Q);
    enqueue(Q, 7); printQueue(Q);
    dequeue(Q);   printQueue(Q);
    enqueue(Q, 4); printQueue(Q);
    dequeue(Q);   printQueue(Q);
    dequeue(Q);   printQueue(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan8_Modul8/unguided1/Output-Unguided1-Modul8.png)

Program ini merepresentasikan penggunaan queue yang dibangun menggunakan array dan mengikuti konsep FIFO. Fungsinya mencakup penambahan data (enqueue), penghapusan data (dequeue), pemeriksaan kondisi penuh atau kosong, serta penampilan seluruh elemen. Proses dequeue dilakukan dengan cara menggeser elemen-elemen di dalam array.


### 2. Unguided 2

queue.h
```C++
s#ifndef QUEUE_H
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
```

queue.cpp
```C++
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
```
main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World\n";
    
    Queue Q;
    initQueue(Q);

    cout << "----------------------\n";
    cout << " F - R | Queue info\n";
    cout << "----------------------\n";

    printQueue(Q);
    enqueue(Q, 5); printQueue(Q);
    enqueue(Q, 2); printQueue(Q);
    enqueue(Q, 7); printQueue(Q);
    dequeue(Q);   printQueue(Q);
    enqueue(Q, 4); printQueue(Q);
    dequeue(Q);   printQueue(Q);
    dequeue(Q);   printQueue(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan8_Modul8/unguided2/Output-Unguided2-Modul8.png)

Program ini mengimplementasikan struktur data queue menggunakan array dengan menerapkan prinsip FIFO. Di dalamnya tersedia fungsi untuk menambah elemen (enqueue), menghapus elemen (dequeue), memeriksa apakah queue penuh atau kosong, serta menampilkan seluruh isi queue. Saat queue menjadi kosong, indeks akan diatur ulang secara otomatis sehingga pengelolaan posisinya menjadi lebih efisien.

### 3. Unguided 3

queue.h
```C++
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
```

queue.cpp
```C++
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
```

main.cpp
```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan8_Modul8/unguided3/Output-Unguided3-Modul8.png)

Program ini menerapkan circular queue berbasis array untuk mengatur data menggunakan prinsip FIFO. Pergerakan indeks dilakukan secara melingkar dengan operasi modulo sehingga pemanfaatan ruang menjadi lebih optimal. Program juga menyediakan operasi enqueue, dequeue, pengecekan kondisi penuh atau kosong, serta fitur untuk menampilkan isi queue.

## Kesimpulan
Queue adalah struktur data yang beroperasi dengan prinsip FIFO. Melalui praktikum ini, mahasiswa dapat mempelajari mekanisme kerja enqueue, dequeue, pemeriksaan kondisi queue, serta penerapan queue menggunakan array maupun linked list. Pemahaman tersebut penting karena struktur data queue banyak dimanfaatkan dalam berbagai proses komputasi dan sistem pemrograman.

## Referensi
[1] Arifin, Z. (2020). Struktur Data dan Algoritma. Jakarta: Informatika.
[2] Hakim, R. (2021). Pemrograman Dasar C++ dan Struktur Data. Bandung: Garuda Media.
[3] Junaidi. (2019). Struktur Data: Konsep dan Implementasi Menggunakan C++. Yogyakarta: Andi Publisher.
