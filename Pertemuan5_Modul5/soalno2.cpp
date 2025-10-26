#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    Node* temp = head;
    int index = 1;

    while (temp) {
        cout << "Memeriksa node " << index << ": " << temp->data;
        if (temp->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << temp << endl;
            cout << "Data node: " << temp->data << endl;
            if (temp->next)
                cout << "Node berikutnya: " << temp->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return temp;
        } else {
            cout << " (tidak sama)" << endl;
        }
        temp = temp->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    displayList(head);

    int key;

    cout << "Mencari nilai: ";
    cin >> key;
    linearSearch(head, key);

    cout << "Mencari nilai: ";
    cin >> key;
    linearSearch(head, key);

    return 0;
}
