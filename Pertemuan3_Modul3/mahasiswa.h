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