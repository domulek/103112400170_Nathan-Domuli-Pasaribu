# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

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
penjelasan singkat guided 1

### 2. ...

#include <iostream>

using namespace std;

void tampilkanhasil (int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4,5}
    };
    int arcC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arcC[i][j] = arrA [i][j] + arrB[i][j];
        }
        
    }
    cout << "Hasil penjumlahan : " << endl;
    tampilkanhasil(arcC);

    cout << endl;

    //perkalian matriks 2x2
    for (int i = 0; i < 2; i++) {                       //perulangan baris
        for (int j = 0; j < 2 ; j++) {                  //perulangan kolom
            for (int k = 0; k < 2; k++) {               //perulangan perkalian
                arrD[i][j] += arrA [i][k] * arrB[k][j];
            }
        }
    }
    cout << "Hasil perkalian : " << endl;
    tampilkanhasil(arrD);

    return 0;
    
    }    
    
    

penjelasan singkat guided 2

### 3. ...

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
penjelasan singkat guided 3

### 4. ...

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
penjelasan singkat guided 4

### 5. ...

#include <iostream>

using namespace std;

void ubahNilai(int& ref){
    ref = 20; //Mengubah nilai melalui referensi
}

int main(){
    int x = 10;
    cout << "NIlai sebelum diubah : " << x << endl;

    ubahNilai(x); // Mengirimmkan referensi ke x
    cout << "Nilai setelah diubah : " << x << endl;

    return 0 ;
}

### 6. ...

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

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
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
