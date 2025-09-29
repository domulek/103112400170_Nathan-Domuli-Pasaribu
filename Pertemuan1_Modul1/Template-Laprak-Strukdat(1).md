# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Nathan Domuli Pasaribu - 103112400170</p>

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

### 1. Operator Aritmatika

#include <iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << " pembagian : " << angka1 / angka2 << endl;
    return 0;
    
}

Program ini digunakan untuk meminta dua angka dari pengguna, kemudian menghitung dan menampilkan hasil operasi aritmatika dasar dari kedua angka tersebut, yaitu penjumlahan, pengurangan, perkalian, dan pembagian.

### 2. Struct

#include<iostream>
using namespace std;

int main(){
    const int MAX = 3;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for (int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout<< "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }
    
    int j = 0;
    while(j < MAX){
        cout << "Nama siswa : " << siswa[j].nama << ", Nilai : " << siswa[j].nilai << endl;
        j++;
    }

    return 0;
}

Program ini digunakan untuk menyimpan dan menampilkan data rapot siswa, berupa nama dan nilai.

### 3. Perulangan

#include <iostream>
using namespace std;

int main (){
    int angka1;
    cout << "Masukkan angka 1 : ";
    cin >> angka1 ;

    for(int i = 0; i < angka1; i++){ //increment
        cout << i << " - " ;
    }
    cout << endl ;

    int j = 10;
    while (j > angka1){
        cout << j << " - " ;
        j --; //decrement
    }

    cout << endl ;

    int k = 10 ;
    do {
        cout << k << " - ";
    } while (k < angka1) ;

    return 0;
}
Program ini digunakan untuk memperlihatkan cara kerja tiga jenis perulangan (for, while, dan do…while) dengan menggunakan input angka dari pengguna.

## Unguided 

### 1. Soal Unguided 1

Buatlah program yang menerima input-an dua buah...

#include <iostream>
using namespace std;

int main (){
    int bil1, bil2;
    cout << "Masukkan Bilangan 1 : ";
    cin >> bil1;
    cout << "Masukkan Bilangan 2 : ";
    cin >> bil2;

    cout << "Penjumlahan : " << bil1 + bil2 << endl;
    cout << "Pengurangan : " << bil1 - bil2 << endl;
    cout << "Pembagian : " << bil1 / bil2 << endl;
    cout << "Perkalian : " << bil1 * bil2 << endl;

    return 0;
}


### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/3a023cb8d09a68f5ee9d9598e2d10a94f9cc2a59/Pertemuan1_Modul1/Output-Unguided1-Modul1.png)


Program di atas adalah sebuah program sederhana dalam C++ yang berfungsi untuk melakukan operasi aritmatika dasar. Pertama, program meminta pengguna untuk memasukkan dua bilangan, yaitu bilangan 1 dan bilangan 2. Setelah kedua bilangan dimasukkan, program langsung menghitung hasil dari penjumlahan, pengurangan, pembagian, dan perkalian dengan menggunakan nilai yang telah diinputkan tersebut. Hasil dari setiap operasi kemudian ditampilkan ke layar. Dengan demikian, program ini berguna sebagai contoh sederhana bagaimana melakukan input, melakukan perhitungan aritmatika, dan menampilkan output dalam bahasa C++.


### 2. Soal Unguided 2

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output...

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
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/3a023cb8d09a68f5ee9d9598e2d10a94f9cc2a59/Pertemuan1_Modul1/Output-Unguide2-Modul1.png)


Program ini mengubah input angka 0–100 menjadi tulisan dalam bahasa Indonesia. Angka dicek dengan kondisi if: 0 jadi nol, 100 jadi seratus, 1–9 memakai array satuan, angka khusus seperti 10 dan 11 ditangani terpisah, 12–19 menggunakan format belas, sedangkan 20–99 menggunakan format puluh ditambah satuan jika tidak nol.

### 3. Soal unguided 3

Buatlah program yang dapat memberikan input...

#include <iostream>
using namespace std;

int main () {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output:\n";

    for (int i = n; i >= 1; i--) {
        
        for (int s = n; s > i; s--) cout << "  ";

            
        for (int j = i; j >= 1; j--) cout << j << " ";

        cout << "* ";

        for (int j = 1; j <= i; j++) cout << j << " ";

        cout << endl;
    }

    for (int s = 0; s < n; s++) cout << "  ";
    cout << "*" << endl;
    return 0;
}
### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/domulek/103112400170_Nathan-Domuli-Pasaribu/blob/3a023cb8d09a68f5ee9d9598e2d10a94f9cc2a59/Pertemuan1_Modul1/Output-Unguide3-Modul1.png)


Program ini menggunakan for sebagai perulangan, i-- digunakan untuk membuat cetak atas ke bawah. S-- menambahkan spasi, j-- mencetak angka menurun serta j++ mencetak angka menaik. Operator ++ dan (--) untuk mengatur arah iterasi perulangan


## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
