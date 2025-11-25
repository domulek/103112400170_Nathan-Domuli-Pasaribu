#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;


void insertEnd(int value) {
    Node* baru = new Node(value);

    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void deleteLast() {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* hapus = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete hapus;
}

void viewForward() {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    Node* current = head;
    Node* temp = nullptr;


    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  
    }


    if (temp != nullptr) {
        head = temp->prev;
    }
}

int main() {
    int menu;
    int value;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> menu;

        switch(menu) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                insertEnd(value);
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                viewForward();
                break;

            case 4:
                reverseList();
                cout << "List setelah di-reverse: ";
                viewForward();
                break;
        }
    } while (menu != 0);

    return 0;
}
