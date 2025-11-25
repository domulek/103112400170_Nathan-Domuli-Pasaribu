#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;
    do {
        cout << "\n--- Komaniya Ekspress ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "5. Keluar\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        if (pilihan == 1) {
            Paket P;
            cout << "Kode Resi     : "; cin >> P.KodeResi;
            cout << "Nama Pengirim : "; cin >> P.NamaPengirim;
            cout << "Berat Barang  : "; cin >> P.BeratBarang;
            cout << "Tujuan        : "; cin >> P.Tujuan;
            enQueue(Q, P);
        } else if (pilihan == 2) {
            deQueue(Q);
        } else if (pilihan == 3) {
            viewQueue(Q);
        } else if (pilihan == 4) {
            int total = TotalBiayaPengiriman(Q);
            cout << "\nTotal biaya pengiriman semua paket: Rp " << total << endl;
        }

    } while (pilihan != 5);

    cout << "Program selesai.";
    return 0;
}
