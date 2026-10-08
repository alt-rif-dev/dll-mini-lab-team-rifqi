#include <iostream>
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

void displayList(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
            current = current->next;
        }
        cout << endl;
    }
}

int main(){
    Node* a = createNode("Song A");
    Node* b = createNode("Song B");
    Node* c = createNode("Song C");
    Node* d = createNode("Song D");
    Node* e = createNode("Song E");

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;
    d->next = e;
    e->prev = d;

    cout << "List: " << endl;
    displayList(a);
    return 0;
}