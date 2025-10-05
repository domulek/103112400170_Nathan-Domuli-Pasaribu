#include <iostream>
using namespace std;

int main() {
    int panjang = 10, lebar = 5;
    int *pPanjang, *pLebar;
    int luas, keliling;

    pPanjang = &panjang;
    pLebar = &lebar;

    cout << "Data Persegi Panjang" << endl;
    cout << "Nilai awal panjang : " << *pPanjang << endl;
    cout << "Nilai awal lebar   : " << *pLebar << endl << endl;

    luas = (*pPanjang) * (*pLebar);
    keliling = 2 * ((*pPanjang) + (*pLebar));

    cout << "Hasil Perhitungan Awal" << endl;
    cout << "Luas      = " << luas << endl;
    cout << "Keliling  = " << keliling << endl << endl;

    *pPanjang = 12;
    *pLebar = 6;

    luas = (*pPanjang) * (*pLebar);
    keliling = 2 * ((*pPanjang) + (*pLebar));

    cout << "Setelah Nilai Diubah" << endl;
    cout << "Panjang baru : " << panjang << endl;
    cout << "Lebar baru   : " << lebar << endl;
    cout << "Luas baru    : " << luas << endl;
    cout << "Keliling baru: " << keliling << endl;

    return 0;
}
