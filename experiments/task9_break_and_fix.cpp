#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

Node* createNode(const string& value){
    Node* n = new Node();
    n->data = value;
    n->prev = nullptr;
    n->next = nullptr;
    return n;
}

void displayForward(Node* head){
    cout << "Forward : ";
    for (Node* c = head; c != nullptr; c = c->next) {
        cout << c->data;
        if (c->next != nullptr) cout << " <-> ";
    }
    cout << endl;
}

void displayBackward(Node* tail){
    cout << "Backward: ";
    for (Node* c = tail; c != nullptr; c = c->prev) {
        cout << c->data;
        if (c->prev != nullptr) cout << " <-> ";
    }
    cout << endl;
}

void deleteNode(Node*& head, Node*& tail, Node* target){
    if (target == nullptr) return;

    if (target->prev != nullptr) target->prev->next = target->next;
    else head = target->next;

    if (target->next != nullptr) target->next->prev = target->prev;
    else tail = target->prev;

    delete target;
}

int main(){
    Node* a = createNode("A");
    Node* b = createNode("B");
    Node* c = createNode("C");
    Node* d = createNode("D");

    a->next = b;  b->prev = a;
    b->next = c;  c->prev = b;
    c->next = d;  d->prev = c;

    Node* head = a;
    Node* tail = d;

    cout << "Sebelum hapus C:" << endl;
    displayForward(head);
    displayBackward(tail);

    deleteNode(head, tail, c);

    cout << "\nSesudah hapus C:" << endl;
    displayForward(head);
    displayBackward(tail);

    delete a; delete b; delete d;
    return 0;
}