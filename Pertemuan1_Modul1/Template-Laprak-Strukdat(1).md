# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Nathan Domuli Pasaribu - 103112400170</p>

## Dasar Teori
C++ adalah bahasa pemrograman yang kuat, fleksibel, dan menjadi dasar dari banyak aplikasi modern. Buku Pengenalan Pemrograman Dasar: Dunia Koding dengan C++ membimbing pembaca dari hal-hal sederhana seperti struktur program dan tipe data, lalu bertahap menuju konsep lanjutan seperti OOP, manajemen memori, dan file. Dengan pendekatan ini, pemula dapat memahami logika pemrograman sekaligus belajar praktik terbaik menulis kode yang efisien dan mudah dipahami [1].

### A. Dasar Pemrograman C++
Dasar pemrograman C++ mencakup konsep-konsep fundamental yang harus dipahami sebelum membuat program, seperti:

- Input dan Output: Menggunakan cin untuk input dari pengguna dan cout untuk menampilkan output ke layar.

- Variabel dan Tipe Data: Menyimpan data dengan tipe seperti int, float, double, dan string.

- Struktur Program: Program C++ biasanya memiliki fungsi main() sebagai titik awal eksekusi.

- Operator: Digunakan untuk melakukan operasi matematika, logika, atau perbandingan.

- Kontrol Alur: Perintah if, else, for, while, dan do…while digunakan untuk pengkondisian dan perulangan.

### B. Operator Aritmatika

Di C++, operator aritmatika digunakan untuk melakukan perhitungan dasar pada angka. Beberapa operator penting antara lain:

(+) untuk penjumlahan

(-) untuk pengurangan

(*) untuk perkalian

(/) untuk pembagian

(%) untuk sisa pembagian (hanya untuk bilangan bulat)

Operator ini bisa digunakan dengan tipe data seperti int, float, atau double untuk membuat program melakukan operasi matematika dasar

### C. Struct
Di C++, struct digunakan untuk mengelompokkan beberapa variabel yang berbeda tipe menjadi satu kesatuan. Dengan struct, kita bisa menyimpan data yang saling terkait, misalnya nama dan nilai siswa, sehingga lebih terstruktur dan mudah diakses dalam program.

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
Modul 1 mempelajari dasar penggunaan C++ dengan aritmatika, penggunaan struct, perulangan dan sebagainya. Pada bagian unguided, kita mengimplementasikan operasi aritmatika sederhana, mengubah angka menjadi bentuk kata dalam bahasa Indonesia, serta membuat pola menggunakan kombinasi angka dan simbol.

## Referensi
[1] Trianiza, I., Khirdany, E. N., Wahyudi, E., Vandika, A. Y., & Sofyan, S. (2025). Pengenalan Pemrograman Dasar Dunia Koding dengan C++.
