# <h1 align="center">Laporan Praktikum Modul 14 -  Graph</h1>
<p align="center">Nathan Domuli Pasaribu - 103112400170</p>

## Dasar Teori
Linked List adalah struktur data linier di mana setiap elemen tidak disimpan secara berurutan, melainkan dihubungkan menggunakan pointer. Linked List terdiri dari serangkaian node yang saling terhubung, dengan setiap node menyimpan data dan alamat dari node selanjutnya [1]

### A. Graph
Graph adalah jenis struktur data yang menyimpan data secara tidak berdekatan satu sama lain, yang berarti data disusun dalam pola non-linier. Graph terdiri dari kumpulan simpul yang menyimpan data, di mana antar simpul terdapat hubungan yang saling terhubung. Berdasarkan arah hubungan antar simpul, graph dibagi menjadi dua jenis, yaitu graph berarah dan graph tak berarah.


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

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
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
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
adrNode allocateNode(infoGraph X);
//prosedur untuk menampilkanhasil penelusuran DFS
void printDFS(Graph G, adrNode N);    
//prosedur untuk menampilkanhasil penelusuran BFS
void printBFS(Graph G, adrNode N);                     
void Visited(Graph &G);
#endif           
```

graph.cpp
```C++
#include "graph.h"
#include<queue>

void CreateGraph(Graph &G){
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
void InsertNode(Graph &G, infoGraph X){
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
void ConnectNode(adrNode N1, adrNode N2){
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node " << P->info << " Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void Visited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = 0;
        P = P->next;
    }
}

//prosedur untuk menampilkanhasil penelusuran DFS
void printDFS(Graph G, adrNode N){
    if(N != NULL && N->visited == 0){
        cout << N->info << " ";
        N->visited = 1;

        adrEdge E = N->firstEdge;
        while(E != NULL){
            if(E->node->visited == 0){
                printDFS(G, E->node);
            }
            E = E->next;
        }
    }
}

//prosedur untuk menampilkanhasil penelusuran BFS
void printBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    queue<adrNode> Q;

    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}
```

main.cpp
```C++
#include "graph.h"
#include<iostream>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode a = findNode(G, 'A');
    adrNode b = findNode(G, 'B');
    adrNode c = findNode(G, 'C');
    adrNode d = findNode(G, 'D');
    adrNode e = findNode(G, 'E');
    adrNode f = findNode(G, 'F');
    adrNode g = findNode(G, 'G'); 
    adrNode h = findNode(G, 'H');

    ConnectNode(a, b);
    ConnectNode(a, c);
    ConnectNode(b, d);
    ConnectNode(b, e);
    ConnectNode(c, f);
    ConnectNode(c, g);
    ConnectNode(d, h);
    ConnectNode(e, h);
    ConnectNode(f, h);
    ConnectNode(g, h);
    PrintInfoGraph(G);
    cout << endl ;


    Visited(G);
    cout << "Hasil penulusuran DFS : " ;
    printDFS(G, a);
    cout << endl ;


    Visited(G);
    cout << "Hasil penulusuran BFS : " ;
    printBFS(G, a);
    cout << endl ;
    
    return 0;

}
```

### Output Unguided 1 :

##### Output 1

a. Menampilkan setiap node beserta node-node lain yang terhubung (PrintInfoGraph)

![Screenshot Output Unguided 1_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan12_Modul14/unguided/Output1-Unguided-Modul14.png)

b. Hasil penelusuran DFS

![Screenshot Output Unguided 1_2](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan12_Modul14/unguided/Output2-Unguided-Modul14.png)

c.Hasil penelusuran BFS.

![Screenshot Output Unguided 1_3](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan12_Modul14/unguided/Output3-Unguided-Modul14.png)


Program ini mengimplementasikan struktur data graph tak berarah (undirected graph) menggunakan linked list dalam bahasa C++. Graph dibangun dengan menambahkan node dari A hingga H, yang masing-masing menyimpan data berupa karakter serta daftar edge dalam bentuk adjacency list. Setiap hubungan antar node dibentuk dua arah melalui fungsi ConnectNode, yang memungkinkan penelusuran bolak-balik. Program ini mendukung algoritma penelusuran graph menggunakan Depth First Search (DFS) dan Breadth First Search (BFS), dengan setiap node diberi penanda "visited" untuk mencegah kunjungan berulang. Sebelum penelusuran dimulai, seluruh node diinisialisasi sebagai belum dikunjungi menggunakan fungsi Visited. Penelusuran DFS dilakukan secara mendalam mulai dari node A, sementara BFS dijalankan secara melebar dengan bantuan struktur data queue. Hasil penelusuran dan keterhubungan antar node ditampilkan melalui fungsi pencetakan, yang menunjukkan secara rinci proses pembuatan, penghubungan, dan penelusuran graph tak berarah.



## Kesimpulan
Graph adalah struktur data non-linier yang efisien untuk menggambarkan hubungan antar data melalui simpul (vertex) dan sisi (edge). Struktur ini memungkinkan pemodelan masalah yang kompleks. Berdasarkan arah hubungan antar simpul, graph dibagi menjadi graph berarah dan graph tidak berarah, masing-masing dengan karakteristik dan penggunaan yang berbeda. Dengan kemampuannya untuk menggambarkan hubungan antar data secara fleksibel, graph menjadi struktur data yang sangat penting dalam pengembangan algoritma dan sistem komputasi saat ini.

## Referensi
[1]Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01)
[2]Trivusi. (2022, September 16). Struktur data graph: Pengertian, jenis, dan kegunaannya. Trivusi
