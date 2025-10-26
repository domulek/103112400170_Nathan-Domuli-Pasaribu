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

int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getNodeAt(Node* head, int index) {
    int count = 0;
    while (head && count < index) {
        head = head->next;
        count++;
    }
    return head;
}

Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getLength(head) - 1;
    int iter = 1;

    cout << "\nProses Pencarian:\n";

    while (left <= right) {
        int mid = left + (right - left) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iter++ << ": Mid = " << midNode->data << " (indeks tengah) ";

        if (midNode->data == key) {
            cout << "- DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            if (midNode->next)
                cout << "Node berikutnya: " << midNode->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return midNode;
        } else if (midNode->data < key) {
            cout << "-> Cari di bagian kanan" << endl;
            left = mid + 1;
        } else {
            cout << "-> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST\n";

    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    displayList(head);

    int key;

    cout << "Mencari nilai: ";
    cin >> key;
    binarySearch(head, key);

    cout << "Mencari nilai: ";
    cin >> key;
    binarySearch(head, key);

    return 0;
}


