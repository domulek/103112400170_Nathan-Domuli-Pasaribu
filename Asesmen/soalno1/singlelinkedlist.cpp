#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

void insertAkhir(string nama) {
    Node* baru = new Node{nama, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void deleteNama(string target) {
    if (head == nullptr) return;

    
    if (head->nama == target) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->nama != target) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
    }
}

void view() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}


int hitungGenap() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->nama.length() % 2 == 0) count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int menu;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                insertAkhir(nama);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                cin >> nama;
                deleteNama(nama);
                break;

            case 3:
                view();
                break;

            case 4:
                cout << "Jumlah nama dengan huruf genap: " 
                     << hitungGenap() << endl;
                break;
        }

    } while (menu != 0);

    return 0;
}
