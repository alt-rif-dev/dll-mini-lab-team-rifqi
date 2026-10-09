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

void appendNode(Node*& head, Node*& tail, const string& value){
    Node* n = createNode(value);
    if (head == nullptr) {
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void displayForward(Node* head){
    cout << "Forward : ";
    Node* current = head;
    while(current != nullptr){
        cout << current->data;
        if (current->next != nullptr) cout << " <-> ";
        current = current->next;
    }
    cout << endl;
}

void displayBackward(Node* tail){
    cout << "Backward: ";
    Node* current = tail;
    while(current != nullptr){
        cout << current->data;
        if (current->prev != nullptr) cout << " <-> ";
        current = current->prev;
    }
    cout << endl;
}

void freeList(Node* head){
    while(head != nullptr){
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    appendNode(head, tail, "google.com");
    appendNode(head, tail, "youtube.com");
    appendNode(head, tail, "github.com");
    appendNode(head, tail, "stackoverflow.com");
    appendNode(head, tail, "kampus.ac.id");

    cout << "Browser History:" << endl;
    displayForward(head);
    displayBackward(tail);

    Node* currentPage = tail;
    cout << "\nHalaman sekarang : " << currentPage->data << endl;

    currentPage = currentPage->prev;
    cout << "Klik Back        : " << currentPage->data << endl;

    currentPage = currentPage->prev;
    cout << "Klik Back        : " << currentPage->data << endl;

    currentPage = currentPage->next;
    cout << "Klik Forward     : " << currentPage->data << endl;

    freeList(head);
    return 0;
}