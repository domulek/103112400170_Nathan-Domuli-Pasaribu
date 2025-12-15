# <h1 align="center">Laporan Praktikum Modul 13 - Multilinkedlist</h1>
<p align="center">Nathan Domuli Pasaribu - 103112400170</p>

## Dasar Teori
Multi Linked List adalah pengembangan dari struktur data linked list yang digunakan untuk merepresentasikan hubungan data secara hierarkis, di mana satu node parent dapat memiliki satu atau lebih node child. Struktur ini sangat cocok untuk mengelola data dengan relasi satu-ke-banyak, seperti pengelompokan data hewan berdasarkan golongan. Dengan alokasi memori dinamis, multi linked list memungkinkan penambahan dan penghapusan data secara fleksibel tanpa harus menggeser elemen lain, menjadikannya lebih efisien dibandingkan dengan struktur data statis seperti array dalam menangani perubahan data yang sering terjadi [1].

Namun, Linked List memiliki keterbatasan, terutama dalam hal akses data. Pencarian elemen pada Linked List harus dilakukan secara berurutan dari node pertama, sehingga waktu akses menjadi lebih lambat dibandingkan struktur data yang mendukung akses langsung. Oleh karena itu, pemilihan Linked List sebagai struktur data perlu mempertimbangkan kebutuhan aplikasi, khususnya ketika data bersifat dinamis dan tidak memerlukan akses acak yang cepat [2].

### A. MultiLinkedList
Multi Linked List (MLL) adalah struktur data yang menghubungkan node secara hierarkis, di mana setiap node parent dapat memiliki satu atau lebih node child. Struktur ini cocok untuk data dengan relasi satu-ke-banyak, seperti pengelompokan data atau sistem menu. MLL menggunakan alokasi memori dinamis, memungkinkan penambahan dan penghapusan data secara fleksibel tanpa memindahkan elemen lain. Namun, akses data lebih lambat karena pencarian elemen dilakukan secara berurutan.

## Guided 

### 1. Guided

multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;   //alias pointer ke struct nodeChild

struct nodeChild { //node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak { //list child
    NodeChild first;
    NodeChild last;
};

struct nodeParent { //node parent
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk { //list parent
    NodeParent first;
    NodeParent last;
};

//create list
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

//alokasi & dealokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent prev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteFirstChild(listAnak &LAnak, NodeChild &nodePrev);
void findChildByID(listInduk LInduk, string idCari);

//operasi print
void printStrukturMLL(listInduk LInduk);

#endif
```

multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```

main.cpp
```C++
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    //1. Inisialisasi List
    listInduk LInduk ;
    createListInduk(LInduk);
    //2. Membuat Data Parent (Kategori Makanan)
    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl;

    //3. Memasukkan Data Child (menu Makanan) ke kategori tertentu
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);
    // --> Isi Kategori Minuman (K02)
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);
    // --> Isi Kategori Dessert (K03)
    NodeChild S01 = alokasiNodeChild("S01", "Puding Coklat");
    insertLastChild(K03->L_Anak, S01);
    cout << endl;

    //4. Print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5. Searching node child
    findChildByID(LInduk, "D01");
    cout << endl;
    
    //6. Delete node child
    deleteFirstChild(K02->L_Anak, M01); //menghapus node child ayam bakar madu
    cout << endl;

    //7. delete ndoe parent
    deleteAfterParent(LInduk, K02); //menghapus node parent dessert
    cout << endl;

    //8. Print mll setelah delete-delete
    printStrukturMLL(LInduk);
    cout << endl;

    return 0;
}
```
Program ini mengimplementasikan Multilevel Linked List (MLL) menggunakan C++ untuk mengelola kategori makanan sebagai node parent dan menu makanan sebagai node child. List induk berupa double linked list, dengan setiap node parent memiliki list anak sesuai kategori. Fitur yang disediakan meliputi inisialisasi list, penambahan data parent dan child, penampilan struktur list, pencarian child berdasarkan ID, serta penghapusan node child dan parent beserta anaknya. Program ini membantu memahami konsep hubungan parent-child dalam struktur data multilevel linked list.



## Unguided 

### 1. Unguided 1

multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn,
string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void deleteListChild(listChild &LChild);

void printMLLStructure(listParent &LParent);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif
```

multilist.cpp
```C++
#include "multilist.h"

bool isEmptyParent(listParent LParent){
    return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild){
    return LChild.first == NULL;
}

void createListParent(listParent &LParent){
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild){
    LChild.first = LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn,
                         string habitat, bool tail, float weight){
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent){
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild){
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent){
    if(!isEmptyParent(LParent)){
        NodeParent del = LParent.first;
        LParent.first = del->next;
        if(LParent.first != NULL)
            LParent.first->prev = NULL;
        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev){
    if(NPrev != NULL && NPrev->next != NULL){
        NodeParent del = NPrev->next;
        NPrev->next = del->next;
        if(del->next != NULL)
            del->next->prev = NPrev;
        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild){
    if(!isEmptyChild(LChild)){
        NodeChild del = LChild.first;
        LChild.first = del->next;
        if(LChild.first != NULL)
            LChild.first->prev = NULL;
        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev){
    if(NPrev != NULL && NPrev->next != NULL){
        NodeChild del = NPrev->next;
        NPrev->next = del->next;
        if(del->next != NULL)
            del->next->prev = NPrev;
        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &LChild){
    while(!isEmptyChild(LChild)){
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent &LParent){
    NodeParent P = LParent.first;
    int noParent = 1;

    while(P != NULL){
        cout << "=== Parent " << noParent << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if(isEmptyChild(P->L_Child)){
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild C = P->L_Child.first;
            int noChild = 1;
            while(C != NULL){
                cout << "- Child " << noChild << " :" << endl;
                cout << "  ID Hewan : " << C->isidata.idHewan << endl;
                cout << "  Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "  Habitat : " << C->isidata.habitat << endl;
                cout << "  Ekor : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "  Bobot : " << C->isidata.bobot << endl;
                C = C->next;
                noChild++;
            }
        }
        cout << "------------------------" << endl;
        P = P->next;
        noParent++;
    }
}

void searchHewanByEkor(listParent &LParent, bool tail){
    if(isEmptyParent(LParent)){
        cout << "List parent kosong!" << endl;
        return;
    }

    NodeParent P = LParent.first;
    int indexParent = 1;
    bool ketemu = false;

    while(P != NULL){
        NodeChild C = P->L_Child.first;
        int indexChild = 1;

        while(C != NULL){
            if(C->isidata.ekor == tail){
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << indexChild << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Hewan : " << C->isidata.idHewan << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? "TRUE" : "FALSE") << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Golongan : " << P->isidata.idGolongan << endl;
                cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
                cout << "Posisi dalam list parent : posisi ke-"
                     << indexParent << endl;
                cout << "---------------------------" << endl;

                ketemu = true;
            }
            C = C->next;
            indexChild++;
        }

        P = P->next;
        indexParent++;
    }

    if(!ketemu){
        cout << "Data hewan dengan ekor = "
             << (tail ? "TRUE" : "FALSE")
             << " tidak ditemukan!" << endl;
    }
}
```

main.cpp
```C++
#include "multilist.h"

int main(){
    listParent LParent;
    createListParent(LParent);

    NodeParent G001 = allocNodeParent("G001","Aves");
    NodeParent G002 = allocNodeParent("G002","Mamalia");
    NodeParent G003 = allocNodeParent("G003","Pisces");
    NodeParent G004 = allocNodeParent("G004","Amfibi");
    NodeParent G005 = allocNodeParent("G005","Reptil");

    insertLastParent(LParent,G001);
    insertLastParent(LParent,G002);
    insertLastParent(LParent,G003);
    insertLastParent(LParent,G004);
    insertLastParent(LParent,G005);

    insertLastChild(G001->L_Child, allocNodeChild("AV001","Cendrawasih","Hutan",true,0.3));
    insertLastChild(G001->L_Child, allocNodeChild("AV002","Bebek","Air",true,2));

    insertLastChild(G002->L_Child, allocNodeChild("M001","Harimau","Hutan",true,200));
    insertLastChild(G002->L_Child, allocNodeChild("M003","Gorila","Hutan",false,160));
    insertLastChild(G002->L_Child, allocNodeChild("M002","Kucing","Darat",true,4));

    insertLastChild(G004->L_Child, allocNodeChild("AM001","Kodok","Sawah",false,0.2));

    printMLLStructure(LParent);

    searchHewanByEkor(LParent,false);

    deleteAfterParent(LParent,G003);

    printMLLStructure(LParent);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan11_Modul13/unguided/Output-Unguided1-Modul13.png)

![Screenshot Output Unguided 1_2](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan11_Modul13/unguided/Output2-Unguided-Modul13.png)

![Screenshot Output Unguided 1_3](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan11_Modul13/unguided/Output3-Unguided-Modul13.png)


Program ini mengimplementasikan Multi Linked List menggunakan bahasa C++ untuk memodelkan hubungan golongan hewan sebagai node parent dan data hewan sebagai node child. Setiap node parent menyimpan golongan hewan dan memiliki daftar child yang berisi data hewan berdasarkan golongan tersebut. Program ini menyediakan operasi untuk membuat list, alokasi dan dealokasi node, penambahan dan penghapusan data parent atau child, mencetak seluruh struktur multilevel linked list, serta mencari data hewan berdasarkan atribut ekor. Dengan struktur ini, program dapat menampilkan, menelusuri, dan mengelola data hewan secara bertingkat sesuai golongannya.


## Kesimpulan
Multi Linked List adalah struktur data lanjutan yang memungkinkan setiap node memiliki lebih dari satu pointer, ideal untuk merepresentasikan hubungan data yang kompleks dan hierarkis. Dalam praktikum ini, MLL digunakan untuk mengelola data hewan berdasarkan golongan, dengan dua level: parent list untuk golongan hewan dan child list untuk data hewan individual. Implementasi menggunakan doubly linked list memungkinkan traversal dua arah dan efisiensi dalam operasi insert dan delete. Setiap parent node menyimpan golongan hewan dan memiliki child list untuk menyimpan data hewan, termasuk ID, nama, habitat, status ekor, dan bobot. MLL efektif untuk aplikasi dengan hubungan data one-to-many dan struktur hierarkis, meskipun lebih kompleks dibandingkan struktur data sederhana.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Wijoyo, Agung., Prasetiyo, Alif Ramdhani., Salsabila, Afra Anggita., Nife, Kristina., Murni., Nadapdap, Pandri Budiman. (2024). “Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian”. Jurnal Riset Informatika dan Inovasi (JRIIN), 1(12), 1244–1246. Diakses pada 13 Desember 2025 melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/1060/678
