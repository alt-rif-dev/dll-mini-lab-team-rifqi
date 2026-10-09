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
    cout << "  Forward : ";
    for (Node* c = head; c != nullptr; c = c->next) {
        cout << c->data;
        if (c->next != nullptr) cout << " <-> ";
    }
    cout << endl;
}

void displayBackward(Node* tail){
    cout << "  Backward: ";
    for (Node* c = tail; c != nullptr; c = c->prev) {
        cout << c->data;
        if (c->prev != nullptr) cout << " <-> ";
    }
    cout << endl;
}

void deleteNodeBuggy(Node*& head, Node*& tail, Node* target){
    if (target == nullptr) return;
    if (target->prev != nullptr) target->prev->next = target->next;
    else head = target->next;
    if (target->next == nullptr) tail = target->prev;
}

void deleteNodeFixed(Node*& head, Node*& tail, Node* target){
    if (target == nullptr) return;
    if (target->prev != nullptr) target->prev->next = target->next;
    else head = target->next;
    if (target->next != nullptr) target->next->prev = target->prev;
    else tail = target->prev;
    delete target;
}

void buildList(Node*& head, Node*& tail, Node*& c){
    Node* a = createNode("A");
    Node* b = createNode("B");
    c = createNode("C");
    Node* d = createNode("D");
    a->next = b;  b->prev = a;
    b->next = c;  c->prev = b;
    c->next = d;  d->prev = c;
    head = a;
    tail = d;
}

int main(){
    Node *head, *tail, *c;

    cout << "=== BUGGY: hapus C tanpa update D->prev ===" << endl;
    buildList(head, tail, c);
    deleteNodeBuggy(head, tail, c);
    displayForward(head);
    displayBackward(tail);

    cout << "\n=== FIXED: update next DAN prev ===" << endl;
    buildList(head, tail, c);
    deleteNodeFixed(head, tail, c);
    displayForward(head);
    displayBackward(tail);
    return 0;
}