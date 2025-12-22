# <h1 align="center">Laporan Praktikum Modul 14 - Graph </h1>
<p align="center">Nathan Domuli Pasaribu - 103112400170 </p>

## Dasar Teori
Linked List adalah struktur data linier di mana setiap elemen tidak disimpan secara berurutan, melainkan dihubungkan menggunakan pointer. Linked List terdiri dari serangkaian node yang saling terhubung, dengan setiap node menyimpan data dan alamat dari node selanjutnya[1]
### A. Graph
Graph adalah jenis struktur data yang menyimpan data secara tidak berdekatan satu sama lain, yang berarti data disusun dalam pola non-linier. Graph terdiri dari kumpulan simpul yang menyimpan data, di mana antar simpul terdapat hubungan yang saling terhubung. Berdasarkan arah hubungan antar simpul, graph dibagi menjadi dua jenis, yaitu graph berarah dan graph tak berarah.


## Guided 

### 1. Guided

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
  adrNode first;
};
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);
#endif
```
graph_edge.cpp
```C++
#include "graph.h"
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while(P != NULL){
        if(P->info == X){
            P = P -> next;
        }
        return NULL;
    }
}
void connectNode(Graph &G, infoGraph start, infoGraph end){
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if(pStart != NULL && pEnd != NULL){
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;//insert first di list edge
        pStart->firstEdge = newEdge;
    }
    
}
```

graph_init.cpp
```C++
#include "graph.h"
void createGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;

    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
```

graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node" << P->info << "Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```
main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    Graph G;
    createGraph(G);

    insertNode(G, 'A');//nambah node A,B,C,D
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    //hub8ngkan node gd edge
    connectNode(G,'A','B'); // A ke B
    connectNode(G,'A','C'); // A ke C
    connectNode(G, 'B','D'); // B ke D
    connectNode(G, 'C','D'); // C ke D

    cout << "Isi graph :" << endl;
    printGraph(G);

}
```
Program ini mengimplementasikan struktur data graph berarah (directed graph) menggunakan linked list, di mana setiap node menyimpan data berupa karakter serta daftar edge yang menunjukkan hubungan dengan node lain. Graph dimulai dalam kondisi kosong, kemudian ditambahkan node A, B, C, dan D. Setelah itu, dibentuk hubungan satu arah antara A ke B, A ke C, B ke D, dan C ke D. Setiap node menyimpan daftar node tujuan dalam bentuk adjacency list. Struktur graph kemudian ditampilkan dengan mencetak setiap node beserta node-node yang terhubung, sehingga hubungan antar node dapat terlihat dengan jelas.



## Unguided 

### 1. Buatlah ADT Graph tidak berarah file “graph.h”.Buatlah implementasi ADT Graph pada file“graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp” dan Buatlah prosedur untuk menampilkanhasil penelusuran DFS serta penelusuran BFS.

```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)



penjelasan unguided 1 



## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
