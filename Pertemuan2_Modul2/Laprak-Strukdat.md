# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Nathan Domuli Pasaribu - 103112400170</p>

## Dasar Teori
Struktur data merupakan cara penyimpanan, pengorganisasian, dan pengaturan data dalam memori komputer agar dapat diakses dan digunakan secara efisien. Dalam pemrograman, penggunaan struktur data seperti array dan pointer menjadi hal yang sangat penting untuk mengelola data dan memori secara optimal. Array digunakan untuk menyimpan kumpulan elemen dengan tipe data yang sama, sedangkan pointer digunakan untuk mengakses dan memanipulasi alamat memori dari variabel lain [1].

### A. Array
Array dalam bahasa C++ merupakan kumpulan data yang memiliki tipe yang sama dan disimpan di dalam satu variabel. Setiap elemen di dalam array dapat diakses menggunakan indeks yang dimulai dari angka 0. Data dalam array disusun secara berurutan di memori dan jumlah elemennya tidak bisa diubah setelah dideklarasikan.

### B. Pointer
Pointer adalah variabel khusus yang digunakan untuk menyimpan alamat memori dari variabel lain. Dengan pointer, kita dapat mengakses dan memodifikasi data secara tidak langsung melalui alamat memori tersebut. Konsep ini memungkinkan pengelolaan data menjadi lebih efisien dan fleksibel dalam pemrograman C++.

### C. Prosedur
Prosedur adalah bagian program terpisah yang berisi sekumpulan perintah untuk menjalankan fungsi tertentu, seperti menampilkan hasil atau melakukan proses perhitungan. Prosedur dapat menerima parameter sebagai masukan, namun tidak mengembalikan nilai seperti halnya fungsi.

## Guided 

### 1. Array

#include <iostream>
using namespace std;

int main () {
    int arr [5] ;

    for (int i = 0; i < 5; i++){
        cout << "Masukkan value indeks ke-" << i << " : ";
        cin >> arr [i];

    }

    int j = 0;
    while (j < 5){
        cout << "Isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
return 0 ;
}

Program ini menginput 5 angka, lalu menampilkan kembali sesuai urutan indeks array

### 2. CallbyPointer

#include <iostream>
using namespace std;

int main (){
    int arr[] = {10,20,30,40,50};
    int*ptr = arr; // Pointer yang menunjuk ke elemen pertama array

    //Mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; i++){
        cout << "Elemen array ke-" << i+1 << "Menggunakan pointer : "  << *(ptr + i) << endl;
    }

    //Mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++){ 
        cout << "Elemen array ke-" << i+1 << "Menggunakan indeks : " << arr[i] << endl;
    
    } 

    return 0;
} 
    
    
Program ini menampilkan isi array dengan dua cara, menggunakan pointer dan menggunakan indeks secara langsung

### 3. Fungsi Prosedur

#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }

return MAX;
}

void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr [i] ;
    }
    cout << "Total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran ; i++) {
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl ;
}

int main () {
    const int ukuran = 5 ;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "NIlai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr,ukuran) ;
    return 0;
}
Program ini mencari nilai terbesar dalam array serta menghitung total penjumlahan dan perkalian dari seluruh elemen array yang dimasukkan



## Unguided 

### 1. Diketahui 2 buah matriks 3x3 seperti dibawah ini :
matriksA = 
[7 12 22
31 6 41
15 19 36]
MatriksB = 
[11 34 7
3 25 41
5 18 33]
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian
matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan;
jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan
kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case
seperti berikut ini :
--- Menu Program Matriks ---
1. Penjumlahan matriks
2. Pengurangan matriks
3. Perkalian matriks
4. Keluar


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


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan2_Modul2/Output-Unguided1-1.png)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan2_Modul2/Output-Unguided1-2.png)

Program ini menampilkan menu untuk melakukan penjumlahan, pengurangan, dan perkalian dua matriks berukuran 3×3

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan
dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan
luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar
yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas.
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui
pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa
nilainya telah berubah.

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

Program ini menghitung luas dan keliling persegi panjang dengan menggunakan konsep pointer untuk mengakses dan mengubah nilai variabel panjang serta lebar secara tidak langsung, lalu hasil perhitungan ditampilkan sebelum dan sesudah nilai diubah menggunakan pointer.

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/main/Pertemuan2_Modul2/Output-Unguided2-1.png)


penjelasan unguided 2

Program ini menghitung luas dan keliling persegi panjang dengan menggunakan konsep pointer untuk mengakses dan mengubah nilai variabel panjang serta lebar secara tidak langsung, lalu hasil perhitungan ditampilkan sebelum dan sesudah nilai diubah menggunakan pointer.

## Kesimpulan
Dalam praktikum modul 2 ini dibahas mengenai array, pointer, dan prosedur dalam bahasa pemrograman C++. Konsep array digunakan untuk menyimpan dan mengelola data dalam jumlah besar secara efisien tanpa perlu mendeklarasikan banyak variabel. Sementara itu, pointer memberikan fleksibilitas tinggi dalam pengelolaan memori serta meningkatkan efisiensi program, khususnya saat bekerja dengan array dinamis dan struktur data kompleks seperti linked list maupun tree. Selain itu, penerapan fungsi atau prosedur berperan penting dalam membagi program menjadi bagian-bagian kecil yang terorganisir dan mudah dikelola. Dengan mengombinasikan konsep array, pointer, dan prosedur dalam C++, programmer dapat menciptakan kode yang efisien, modular, serta mudah dipahami.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.

