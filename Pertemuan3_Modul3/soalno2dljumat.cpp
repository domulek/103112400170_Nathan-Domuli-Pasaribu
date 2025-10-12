#include <iostream>
using namespace std;

struct node {
    float data;
    node* next;
};

struct list {
    node* first;
};

// Membuat list kosong
void buatList(list &L) {
    L.first = NULL;
}

// Membuat elemen baru
node* buatElemen(float X) {
    node* elm = new node;
    elm->data = X;
    elm->next = NULL;
    return elm;
}

// Menambahkan elemen di akhir list
void tambahAkhir(list &L, node* elm) {
    if (L.first == NULL) {
        L.first = elm;
    } else {
        node* p = L.first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = elm;
    }
}

// Mencari nilai X dalam list
node* cariX(list L, float X) {
    node* p = L.first;
    while (p != NULL) {
        if (p->data == X) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Menghapus elemen sesuai kondisi di soal
void hapusKondisi(list &L, float X) {
    if (L.first == NULL) {
        cout << "List kosong" << endl;
        return;
    }

    node* p = L.first;
    node* prev = NULL;

    // Jika elemen pertama bernilai X
    if (p->data == X) {
        L.first = p->next;
        delete p;
        return;
    }

    // Cari elemen X di tengah list
    while (p != NULL && p->data != X) {
        prev = p;
        p = p->next;
    }

    // Jika X tidak ditemukan
    if (p == NULL) {
        cout << "Tidak ada elemen bernilai " << X << " dalam list" << endl;
        return;
    }

    // Jika X berada di akhir list
    if (p->next == NULL) {
        prev->next = NULL;
        delete p;
        return;
    }

    // Jika X di tengah, hapus elemen setelah X
    node* temp = p->next;
    p->next = temp->next;
    delete temp;
}

// Menampilkan isi list
void tampilList(list L) {
    node* p = L.first;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    list L;
    buatList(L);

    tambahAkhir(L, buatElemen(15));
    tambahAkhir(L, buatElemen(30));
    tambahAkhir(L, buatElemen(40));
    tambahAkhir(L, buatElemen(50));

    cout << "List awal:" << endl;
    tampilList(L);

    float X;
    cout << "Masukkan nilai X: ";
    cin >> X;

    hapusKondisi(L, X);

    cout << "List setelah penghapusan:" << endl;
    tampilList(L);

    return 0;
}
