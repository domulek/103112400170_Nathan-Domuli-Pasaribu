#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int matriksA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int matriksB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int hasil[3][3] = {0};
    int pilihan;

    do {
        cout << "\n=== MENU PROGRAM MATRIKS ===\n";
        cout << "1. Penjumlahan Matriks\n";
        cout << "2. Pengurangan Matriks\n";
        cout << "3. Perkalian Matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        hasil[i][j] = matriksA[i][j] + matriksB[i][j];
                    }
                }
                cout << "Hasil Penjumlahan Matriks:" << endl;
                tampilkanHasil(hasil);
                cout << endl;
                break;

            case 2:
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        hasil[i][j] = matriksA[i][j] - matriksB[i][j];
                    }
                }
                cout << "Hasil Pengurangan Matriks:" << endl;
                tampilkanHasil(hasil);
                cout << endl;
                break;

            case 3:
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        hasil[i][j] = 0;
                        for (int k = 0; k < 3; k++) {
                            hasil[i][j] += matriksA[i][k] * matriksB[k][j];
                        }
                    }
                }
                cout << "Hasil Perkalian Matriks:" << endl;
                tampilkanHasil(hasil);
                cout << endl;
                break;

            case 4:

                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
