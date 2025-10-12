# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE</h1>
<p align="center"> Nathan Domuli Pasaribu - 103112400170 </p>

## Dasar Teori
Struktur data menggambarkan sekumpulan data yang dibedakan berdasarkan cara pengorganisasiannya serta operasi yang diterapkan padanya. Pemilihan struktur data yang sesuai dalam proses pemrograman akan membantu menghasilkan algoritma yang lebih efisien dan mudah dipahami, sehingga membuat keseluruhan program menjadi lebih sederhana.[1]

### A. Pointer
Single Linked List dalam bahasa C merupakan struktur data berantai satu arah, di mana setiap elemen atau node terdiri atas dua bagian utama, yaitu data yang berisi nilai yang disimpan seperti angka atau karakter, serta pointer yang berfungsi sebagai penunjuk alamat menuju node berikutnya dalam urutan.

### B. Single Linked List
Double Linked List atau Doubly Linked List adalah struktur data berantai dua arah yang memungkinkan setiap elemen atau node terhubung ke node sebelumnya maupun node berikutnya. Setiap node memiliki dua pointer, yaitu pointer pertama yang menunjuk ke node sebelumnya dan pointer kedua yang menunjuk ke node berikutnya, serta menyimpan data di antara kedua pointer tersebut.

## Guided 

### 1. Soal Guided 1

```C++

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
```

Program ini membentuk struktur data Linked List dengan tipe data float. Program tersebut diawali dengan membuat daftar awal yang berisi beberapa elemen, kemudian menampilkan isinya. Setelah itu, pengguna diminta untuk memasukkan sebuah angka baru yang akan disisipkan ke dalam daftar secara berurutan (dari kecil ke besar). Terakhir, program menampilkan hasil akhir dari daftar setelah proses penyisipan dilakukan.

### 2. Soal Guided 2

```C++
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
```

Kode ini berfungsi untuk memasukkan data seorang mahasiswa dan menghitung rata-rata dua nilainya menggunakan fungsi terpisah

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts+ 0.4 * uas + 0.3 * tugas

```C++
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
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan3_Modul3/Output%20Unguided-Modul3-Soalno1.png)


Program ini dibuat untuk menghitung dan menampilkan nilai akhir dari beberapa mahasiswa. Setiap mahasiswa memiliki data berupa nama, NIM, nilai UTS, UAS, dan tugas yang disimpan dalam struktur bernama Mahasiswa. Perhitungan nilai akhir dilakukan dengan rumus yang memberi bobot 30% pada nilai UTS, 40% pada nilai UAS, dan 30% pada nilai tugas. Setelah pengguna memasukkan jumlah mahasiswa dan data masing-masing, program akan menghitung nilai akhir mereka secara otomatis, lalu menampilkan hasil berupa nama, NIM, serta nilai akhir setiap mahasiswa di layar.


### 2. Buatlah ADT pelajaran dengan file "pelajaran.h" lalu buat implementasi ADT pelajran dalam file "pelajaran.cpp" lalu coba hasil implementasi ADT dalam file "main.cpp"

pelajaran.cpp

```C++

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
```

pelajaran.h
```C++
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
```
main.cpp 
```C++
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
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan3_Modul3/Output%20Unguided-Modul3-Soalno2.png)



Program ini menggunakan struct untuk menyimpan data mata pelajaran berupa nama dan kode. Fungsi create_pelajaran digunakan untuk membuat objek mata pelajaran berdasarkan data yang diberikan, sedangkan tampil_pelajaran menampilkan hasilnya ke layar. Pada fungsi main, program membuat mata pelajaran struktur data dengan kode STD dan menampilkannya.

### 3. Buatlah program dengan ketentuan: 
### 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer 
### fungsi/prosedur yang menampilkan isi sebuah array integer 2D 
### fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
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
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan3_Modul3/Output%20Unguided-Modul3-Soalno3.png)


Program ini menampilkan dua array 3x3, A dan B, lalu meminta pengguna memilih posisi baris dan kolom untuk menukar elemen pada posisi tersebut antara kedua array. Setelah pertukaran, program menampilkan hasil array yang sudah diperbarui. Selain itu, terdapat contoh penggunaan pointer untuk menukar nilai dua variabel (x dan y) menggunakan fungsi tukarpointer

## Kesimpulan
ADT berfungsi untuk memisahkan antara logika pengolahan data dengan cara implementasinya, sehingga program menjadi lebih mudah dipahami dan dikelola. STRUCT digunakan untuk membuat tipe data baru seperti data mahasiswa atau pelajaran. Sementara itu, Linked List merupakan contoh penerapan ADT yang memanfaatkan pointer untuk menghubungkan antar elemen data.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
