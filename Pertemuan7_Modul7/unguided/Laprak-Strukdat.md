# <h1 align="center">Laporan Praktikum Modul 7 - Stack (Bagian Pertama)</h1>
<p align="center">Nathan Domuli Pasaribu - 103112400170</p>

## Dasar Teori
Struktur data adalah teknik untuk mengatur dan menyimpan informasi sehingga proses pengolahan dalam program dapat berjalan secara optimal. Salah satu struktur data dasar yang banyak dimanfaatkan adalah stack, yaitu struktur linear yang bekerja dengan prinsip LIFO (Last In, First Out), di mana elemen terakhir yang masuk akan menjadi elemen pertama yang diambil [1]. Stack menyediakan sejumlah operasi utama seperti push, pop, peek/top, isEmpty, dan isFull, yang memungkinkan pengelolaan data dari bagian atas secara terstruktur [2]. Struktur ini memiliki peranan penting dalam berbagai aplikasi, termasuk pengelolaan call stack, fitur undo/redo, evaluasi ekspresi aritmatika, proses backtracking, serta navigasi riwayat pada browser, sehingga pemahaman mengenai stack menjadi aspek penting dalam perancangan algoritma dan pengembangan perangkat lunak [3].

### A. Stack
Stack adalah salah satu struktur data linear yang memiliki aturan khusus dalam pengolahan datanya. Elemen-elemen di dalam stack tersusun seperti tumpukan, sehingga hanya data yang paling baru ditambahkan yang bisa diakses atau diproses terlebih dahulu. Seluruh operasi dilakukan pada satu sisi yang disebut top (bagian atas stack). Stack bekerja dengan prinsip LIFO (Last In, First Out), yaitu elemen yang masuk terakhir akan menjadi elemen pertama yang dikeluarkan.

### 1. guided 1 

main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node* address;

struct node{
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka); 
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update (stack &listStack, int posisi);
void view (stack listStack);
void searchData(stack listStack, int data);

#endif
```

Program ini membuat struktur stack menggunakan linked list dan menyediakan beberapa operasi, seperti push untuk menambahkan data di bagian atas, pop untuk menghapus elemen teratas, update untuk mengubah data pada posisi tertentu, view untuk menampilkan seluruh isi stack, serta searchData untuk mencari nilai tertentu. Pada file stack.h terdapat definisi struktur dan deklarasi fungsi, sedangkan stack.cpp memuat implementasinya. File main.cpp digunakan untuk menunjukkan cara kerja stack, mulai dari menambah beberapa elemen, menghapus dua elemen, memperbarui data pada posisi tertentu, hingga melakukan pencarian data di dalam stack.

### 2. guided 2

main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```

stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //Array untuk menyimpan eleman stack
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // Menambahkan elemen ke dalam stack
infotype pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S);
void balikStack(Stack &S); // Membalik urutan elemen dalam stack

#endif
```

penjelasan singkat guided 2

Program ini membangun stack menggunakan array dengan batas kapasitas tertentu. Pada stack.h didefinisikan struktur stack dan deklarasi fungsi, sedangkan stack.cpp memuat implementasi berbagai operasi, seperti membuat stack, memeriksa kondisi kosong atau penuh, push untuk menambah elemen, pop untuk mengambil elemen, printInfo untuk menampilkan isi stack, serta balikStack untuk membalik urutan elemen dengan bantuan dua stack tambahan. Dalam main.cpp, program menjalankan beberapa operasi push dan pop, menampilkan isi stack, lalu membalik isi stack dan menampilkannya kembali.

## Unguided 

### 1. Unguided1
stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
#define MaxEl 20
#define Nil -1

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);

#endif
```

stack.cpp
```C++
#include "stack.h"
using namespace std;

void CreateStack(Stack &S){
    S.top = Nil;
}
void push(Stack &S, infotype x){
    if(!isFull(S)){
        S.top++;
        S.info[S.top] = x;
    }else{
        cout << "Stack penuh" << endl;
    }

}
infotype pop(Stack &S) {
    infotype x = -999;  
    if (!isEmpty(S)) {  
        x = S.info[S.top];  
        S.top--;  
    } else {
        cout << "Stack Kosong!" << endl;  
    }
    return x; 
}
void printInfo(Stack S) {
    if (isEmpty(S)) {  
        cout << "Stack Kosong" << endl;  
    } else {
        cout << "[TOP] ";  
        for (int i = S.top; i >= 0; i--) {  
            cout << S.info[i] << " ";  
        }
        cout << endl; 
    }
}
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  
        Stack temp1, temp2;  
        CreateStack(temp1); CreateStack(temp2);  

        while (!isEmpty(S)) { push(temp1, pop(S)); }  

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  
    }
}
bool isEmpty(Stack S){
    return S.top == Nil;
}
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  
}
void pushAscending(Stack &S, int x){
    Stack Temp1, Temp2;
    CreateStack(Temp1);
    CreateStack(Temp2);
    int t;
    while(!isEmpty(S)){
        t = pop(S);
        if (t < x){
            push(Temp1, t);
            //break;
        }else{
            push(Temp2, t);
        }
    }
    while(!isEmpty(Temp1)){
        push(S, pop(Temp1));
    }
    push(S, x);
    while(!isEmpty(Temp2)){
       
        push(S, pop(Temp2));
    }
}
void getInputStream(Stack &S) {
    char c;

    cout << "Masukkan input: ";

    cin.get(c);           

    while (c != '\n') {   
        push(S, c - '0'); 
        cin.get(c);       
    }
}
```

main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;
int main(){
    cout << "Hello World!" << endl;
    Stack S;
    CreateStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S,2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    cout << "Hello World!" << endl;
    CreateStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    cout << "Hello World!" << endl;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan7_Modul7/unguided/Output-Unguided1-Modul7.png)

Program ini membangun struktur stack yang dilengkapi operasi dasar seperti push, pop, serta penampilan isi stack. Selain itu, terdapat fungsi tambahan seperti balikStack yang digunakan untuk membalik urutan elemen, pushAscending untuk menambahkan data sambil mempertahankan urutan menaik, dan getInputStream yang membaca input angka per digit. Pada file main.cpp, seluruh fungsi tersebut dicoba satu per satu untuk memperlihatkan cara kerja stack beserta fitur tambahannya.


## Kesimpulan
Praktikum ini memperlihatkan penerapan konsep stack yang bekerja dengan prinsip LIFO, baik melalui array maupun linked list. Mahasiswa belajar mengimplementasikan operasi dasar stack dan fitur tambahan seperti membalik urutan elemen, memasukkan data secara terurut, serta membaca input secara bertahap. Kegiatan ini membantu memahami penggunaan stack secara efisien dalam pemrograman.

## Referensi
[1] Munir, R. (2015). Algoritma dan Struktur Data. Bandung: Informatika. [2] Kurniawan, A. (2019). Struktur Data dan Algoritma. Bandung: Informatika. [3] Rismayanti, R., & Santoso, H. B. (2017). “Implementasi Struktur Data Stack untuk Aplikasi Pengolahan Ungkapan Aritmatika.” Jurnal Teknologi Informasi dan Pendidikan, 10(2), 45–52.
