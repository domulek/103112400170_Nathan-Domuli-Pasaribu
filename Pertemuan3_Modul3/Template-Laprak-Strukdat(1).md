# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE</h1>
<p align="center"> Nathan Domuli Pasaribu - 103112400170 </p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. ...

#include <iostream>
#include"mahasiswa.h"

using namespace std;

//Realisasi dari Fungsi InputMhs
void InputMhs (mahasiswa &m){
    cout << "Input NIM : " ;
    cin >> m.nim ;
    cout << "Input Nilai 1 : " ;
    cin >> m.nilai1;
    cout << "Input Nilai 2 : ";
    cin >> m.nilai2;
}

//Realisasi dari Fungsi rata2

float rata2 (mahasiswa m){
    return (float)(m.nilai1 + m.nilai2)/2;
}

#ifndef MAHASISWA_H
#define MAHASISWA_H

//definisi tipe (Struct)
struct mahasiswa {
    char nim [10]; 
    int nilai1, nilai2;
};

// Deklarasi Primitif (Fungsi)
void InputMhs (mahasiswa&m);
float rata2(mahasiswa m );

#endif

#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    InputMhs(mhs) ;

    cout << "Rata -rata nilai adalah : " << rata2 
    (mhs) << endl ;
    system ("pause");

    return 0;
}

### 2. Struct

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

Kode ini berfungsi untuk memasukkan data seorang mahasiswa dan menghitung rata-rata dua nilainya menggunakan fungsi terpisahdd

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts+ 0.4 * uas + 0.3 * tugas

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin >> mhs[i].nama;
        cout << "NIM    : ";
        cin >> mhs[i].nim;
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "Data Mahasiswa";
    for (int i = 0; i < n; i++) {
        cout << "\nNama        : " << mhs[i].nama;
        cout << "\nNIM         : " << mhs[i].nim;
        cout << "\nNilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. Buatlah ADT pelajaran dengan file "pelajaran.h" lalu buat implementasi ADT pelajran dalam file "pelajaran.cpp" lalu coba hasil implementasi ADT dalam file "main.cpp"

pelajaran.cpp

#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran create_pelajaran(string nama, string kode) {
    Pelajaran p;
    p.namaMapel = nama;
    p.kodeMapel = kode;
    return p;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

pelajaran.h

#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;


struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran create_pelajaran(string nama, string kode);
void tampil_pelajaran(Pelajaran pel);

#endif 

main.cpp 

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodeMapel = "STD";

    Pelajaran pel = create_pelajaran(namaMapel, kodeMapel);

    tampil_pelajaran(pel);

    return 0;
}


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. Buatlah program dengan ketentuan: 
### 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer 
### fungsi/prosedur yang menampilkan isi sebuah array integer 2D 
### fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarNilai(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int B[3][3] = { {9,8,7}, {6,5,4}, {3,2,1} };
    int baris, kolom;

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    cout << "\nMasukkan posisi yang ingin ditukar (baris kolom, dimulai dari 0): ";
    cin >> baris >> kolom;

    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        cout << "Posisi tidak valid! Harus antara 0 dan 2.\n";
        return 0;
    }

    tukarNilai(A, B, baris, kolom);

    cout << "\nSetelah tukar posisi (" << baris << "," << kolom << "):\n";
    cout << "Array A:\n"; tampilArray(A);
    cout << "Array B:\n"; tampilArray(B);

    int x = 10, y = 99;
    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(p1, p2);
    cout << "Sesudah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}


### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
