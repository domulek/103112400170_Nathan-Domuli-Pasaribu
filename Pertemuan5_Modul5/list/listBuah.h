#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL
#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address; // mendefniskan alias address sbgi pointer ke struct

struct node{ //  node unutk
    dataBuah isiData;
    address next;
};
struct linkedList{ //linked list
   address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst (linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);
void delFirst(linkedList &List);
void delLst(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address Prev);

#endif