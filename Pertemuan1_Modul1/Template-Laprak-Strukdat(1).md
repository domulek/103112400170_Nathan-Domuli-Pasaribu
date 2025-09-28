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

### 1. ...

```C++
source code guided 1
```
penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

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

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

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

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

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
