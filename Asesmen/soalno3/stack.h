#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#define Nil -1

#include <iostream>
using namespace std;

const int MAX = 6;

typedef struct {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
} Mahasiswa;


typedef struct {
    Mahasiswa data[MAX];
    int Top;
} StackMahasiswa;


bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);

void push(StackMahasiswa &S, Mahasiswa M);
void pop(StackMahasiswa &S);

void update(StackMahasiswa &S, int posisi, Mahasiswa M);
void view(StackMahasiswa S);

float hitungNilaiAkhir(Mahasiswa M);

void searchNilaiAkhir(StackMahasiswa S, float minVal, float maxVal);

void maxNilaiAkhir(StackMahasiswa S);


#endif
