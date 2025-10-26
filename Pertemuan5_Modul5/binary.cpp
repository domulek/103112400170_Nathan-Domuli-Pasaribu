#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* binarySearch(Node* head, int key) {
    Node* low = head;
    Node* high = nullptr;

    while (low != high) {
        Node* mid = low;
        Node* fast = low;

        while (fast != high && fast->next != high) {
            fast = fast->next->next;
            mid = mid->next;
        }

        if (mid->data == key) {
            return mid; // Key found
        } else if (mid->data < key) {
            low = mid->next;
        } else {
            high = mid;
        }
    }
    return nullptr; // Key not found
}
void append(Node*& head, int value) {

    if(!head)head= new Node{value,nullptr};

    else{
        Node* current=head;
        while(current->next)current=current->next;
        current->next=new Node{value,nullptr};
    }

}

int main(){
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);

    int key = 30;
    Node* result = binarySearch(head, key);
    if (result) {
        cout << "Key " << key << " found in the list." << endl;
    } else {
        cout << "Key " << key << " not found in the list." << endl;
    }

    return 0;
}