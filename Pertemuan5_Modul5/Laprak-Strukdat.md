# <h1 align="center">Laporan Praktikum Modul 1 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. Binary 
...


### B. Linear
...

## Guided 

### 1. Guided 1

listbuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.jumlah = jumlah; 
    nodeBaru->isiData.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isiData.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isiData.nama << ", Jumlah : " << nodeBantu->isiData.jumlah << ", Harga : " << nodeBantu->isiData.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

//----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isiData.nama;
        cout << "Jumlah : ";
        cin >> List.first->isiData.jumlah;
        cout << "Harga : ";
        cin >> List.first->isiData.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isiData.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isiData.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isiData.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isiData.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isiData.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isiData.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isiData.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

listbuah.h
```C++
    #ifndef LISTBUAH_H
    #define LISTBUAH_H

    #define Nil NULL
    #include <iostream>
    using namespace std;

    struct buah {
        string nama;
        int jumlah;
        float harga;
    };

    typedef buah dataBuah;
    typedef struct node *address;

    struct node {
        dataBuah isidata;
        address next;
    };

    struct linkedlist {
        address first;
    };

    // ==== DEKLARASI / PROTOTYPE ====
    bool isEmpty(linkedlist List);
    void createList(linkedlist &List);

    address alokasi(string nama, int jumlah, float harga);
    void dealokasi(address &node);

    void insertFirst(linkedlist &List, address nodeBaru);
    void insertAfter(linkedlist &List, address nodeBaru, address Prev);
    void insertLast(linkedlist &List, address nodeBaru);

    void delFirst(linkedlist &List);
    void delLast(linkedlist &List);
    void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

    void printList(linkedlist List);
    int nbList(linkedlist List);
    void deleteList(linkedlist &List);

    // === Fungsi update data ===
    void updateFirst(linkedlist List);
    void updateLast(linkedlist List);
    void updateAfter(linkedlist List, address nodePrev);

    #endif
```

main.cpp
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini berfungsi untuk membuat dan mengelola Linked List yang menyimpan data buah, di mana setiap node berisi nama buah, jumlah, dan harga. Program ini memungkinkan pengguna untuk menambah, menghapus, menampilkan, serta mengedit data buah dalam daftar.


### 2. Guided 2

binary.cpp
```C++
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* binarySearch(Node* head, int key) {
    Node* low = head;
    Node* high = nullptr;

    while (low != high) {
        Node* mid = low;
        Node* fast = low;

        while (fast != high && fast->next != high) {
            fast = fast->next->next;
            mid = mid->next;
        }

        if (mid->data == key) {
            return mid; // Key found
        } else if (mid->data < key) {
            low = mid->next;
        } else {
            high = mid;
        }
    }
    return nullptr; // Key not found
}
void append(Node*& head, int value) {

    if(!head)head= new Node{value,nullptr};

    else{
        Node* current=head;
        while(current->next)current=current->next;
        current->next=new Node{value,nullptr};
    }

}

int main(){
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);

    int key = 30;
    Node* result = binarySearch(head, key);
    if (result) {
        cout << "Key " << key << " found in the list." << endl;
    } else {
        cout << "Key " << key << " not found in the list." << endl;
    }

    return 0;
}
```

linear.cpp
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Program ini digunakan untuk mencari data spesifik dalam struktur data linked list. Pada program pertama, pencarian dilakukan menggunakan metode binary search, sedangkan pada program kedua menggunakan metode linear search. Kedua metode tersebut memiliki tujuan yang sama, yaitu menentukan apakah suatu nilai (key) terdapat dalam linked list dan menampilkan hasil “Found” atau “Not Found”.



## Unguided 

### 1. Soal Unguided 1

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getNodeAt(Node* head, int index) {
    int count = 0;
    while (head && count < index) {
        head = head->next;
        count++;
    }
    return head;
}

Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getLength(head) - 1;
    int iter = 1;

    cout << "\nProses Pencarian:\n";

    while (left <= right) {
        int mid = left + (right - left) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iter++ << ": Mid = " << midNode->data << " (indeks tengah) ";

        if (midNode->data == key) {
            cout << "- DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            if (midNode->next)
                cout << "Node berikutnya: " << midNode->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return midNode;
        } else if (midNode->data < key) {
            cout << "-> Cari di bagian kanan" << endl;
            left = mid + 1;
        } else {
            cout << "-> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST\n";

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    displayList(head);

    int key;

    cout << "Mencari nilai: ";
    cin >> key;
    binarySearch(head, key);

    cout << "Mencari nilai: ";
    cin >> key;
    binarySearch(head, key);

    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)


Program tersebut digunakan untuk mencari data tertentu pada struktur data linked list dengan menerapkan metode binary search menggunakan bahasa C++. Program ini terlebih dahulu membuat linked list berisi data integer yang tersusun secara terurut, kemudian melakukan pencarian nilai dengan membagi posisi tengah (mid node) secara bertahap sampai data yang dicari berhasil ditemukan atau dinyatakan tidak ada.

### 2. Soal Unguided 2

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    Node* temp = head;
    int index = 1;

    while (temp) {
        cout << "Memeriksa node " << index << ": " << temp->data;
        if (temp->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << temp << endl;
            cout << "Data node: " << temp->data << endl;
            if (temp->next)
                cout << "Node berikutnya: " << temp->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return temp;
        } else {
            cout << " (tidak sama)" << endl;
        }
        temp = temp->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    displayList(head);

    int key;

    cout << "Mencari nilai: ";
    cin >> key;
    linearSearch(head, key);

    cout << "Mencari nilai: ";
    cin >> key;
    linearSearch(head, key);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)


Program ini digunakan untuk mencari data tertentu pada struktur data linked list dengan menerapkan metode linear search menggunakan bahasa C++. Program ini terlebih dahulu membentuk linked list berisi beberapa data integer, menampilkan seluruh isinya, lalu melakukan pencarian berdasarkan nilai yang dimasukkan pengguna. Proses pencarian dilakukan dengan menelusuri setiap node secara berurutan dari awal hingga akhir daftar sampai data yang dicari ditemukan atau seluruh node telah diperiksa.



## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
