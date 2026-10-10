#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

Node* createNode(const string& value) {
    Node* n = new Node();
    n->data = value;
    n->prev = nullptr;
    n->next = nullptr;
    return n;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

void traverseForward(Node* head) {
    cout << "Forward: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

void traverseBackward(Node* tail) {
    cout << "Backward: ";
    Node* current = tail;
    while (current != nullptr) {
        cout << current->data;
        if (current->prev != nullptr) cout << " -> ";
        current = current->prev;
    }
    cout << endl;
}

void insertAfter(Node* head, const string& target, const string& newData) {
    Node* current = head;

    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    if (current != nullptr) {
        Node* newNode = createNode(newData);

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }
}

void deleteNode(Node*& head, Node*& tail, const string& target) {
    Node* current = head;

    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    if (current == nullptr) return;

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    delete current;
}

int main() {
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

    Node* head = a;
    Node* tail = e;

    cout << "--- Initial List ---" << endl;
    displayList(head);
    cout << endl;

    cout << "--- Task 5: Insert 'Song X' after 'Song B' ---" << endl;
    insertAfter(head, "Song B", "Song X");
    traverseForward(head);
    traverseBackward(tail);
    cout << endl;

    cout << "--- Task 6: Delete 'Song C' ---" << endl;
    deleteNode(head, tail, "Song C");
    traverseForward(head);
    traverseBackward(tail);

    return 0;
}