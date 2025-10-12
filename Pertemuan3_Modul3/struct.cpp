#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    float nilai1, nilai2 ;
};

//Realisasi dari Fungsi InputMhs
void InputMhs (mahasiswa &m){
    cout << "Input NIM : " ;
    cin >> m.nama ;
    cout << "Input Nilai 1 : " ;
    cin >> m.nilai1;
    cout << "Input Nilai 2 : ";
    cin >> m.nilai2;
}

//Realisasi dari Fungsi rata2

float rata2 (mahasiswa m){
    return (float)(m.nilai1 + m.nilai2)/2;
}