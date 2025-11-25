#include "queue.h"

bool isEmpty(QueueEkspedisi Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "Queue penuh! Tidak bisa menambah paket.\n";
        return;
    }
    if (isEmpty(Q)) {
        Q.Head = Q.Tail = 0;
    } else {
        Q.Tail++;
    }
    Q.dataPaket[Q.Tail] = data;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong! Tidak bisa menghapus paket.\n";
        return;
    }
    for (int i = Q.Head; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }
    Q.Tail--;
    if (Q.Tail < 0) {
        Q.Head = Q.Tail = -1;
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
        return;
    }

    cout << "\n--- Daftar Paket Dalam Queue ---\n";
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "Paket ke-" << i + 1 << endl;
        cout << "Kode Resi   : " << Q.dataPaket[i].KodeResi << endl;
        cout << "Pengirim    : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "Berat (kg)  : " << Q.dataPaket[i].BeratBarang << endl;
        cout << "Tujuan      : " << Q.dataPaket[i].Tujuan << endl;
        cout << "-----------------------------\n";
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    int total = 0;
    const int tarif = 8250;

    if (isEmpty(Q)) return 0;

    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += Q.dataPaket[i].BeratBarang * tarif;
    }
    return total;
}
