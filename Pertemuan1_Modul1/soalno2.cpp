#include <iostream>
using namespace std;

int main (){
    int angka;
    cout << "Masukkan angka 1-100 : ";
    cin >> angka;

   string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan"};

    if (angka == 0) cout << "nol";
        
    else if (angka == 100) cout << "seratus";

    else if (angka < 10) cout << satuan[angka];

    else if (angka == 10) cout << "sepuluh";

    else if (angka == 11) cout << "sebelas";

    else if (angka < 20) 
        cout << satuan[angka % 10] << " belas";
    
    else if (angka < 100) {
        cout << satuan[angka / 10] << " puluh";
        if (angka % 10 != 0) cout << " " << satuan[angka % 10];
    }
}