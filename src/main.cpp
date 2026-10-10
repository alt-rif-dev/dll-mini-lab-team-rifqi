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
 
void appendNode(Node*& head, Node*& tail, const string& value) {
    Node* n = createNode(value);
    if (head == nullptr) {
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}
 
void freeList(Node* head) {
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}
 
void deleteNodeBuggy(Node*& head, Node*& tail, Node* target) {
    if (target == nullptr) return;
 
    if (target->prev != nullptr) {
        target->prev->next = target->next;
    } else {
        head = target->next;
    }
 
    if (target->next == nullptr) {
        tail = target->prev;
    }
}
 
void task7BrowserHistory() {
    Node* head = nullptr;
    Node* tail = nullptr;
 
    appendNode(head, tail, "google.com");
    appendNode(head, tail, "youtube.com");
    appendNode(head, tail, "github.com");
    appendNode(head, tail, "stackoverflow.com");
    appendNode(head, tail, "kampus.ac.id");
 
    cout << "Browser History:" << endl;
    displayList(head);
    traverseForward(head);
    traverseBackward(tail);
    cout << endl;
 
    Node* currentPage = tail;
    cout << "Halaman sekarang : " << currentPage->data << endl;
 
    currentPage = currentPage->prev;
    cout << "Klik Back        : " << currentPage->data << endl;
 
    currentPage = currentPage->prev;
    cout << "Klik Back        : " << currentPage->data << endl;
 
    currentPage = currentPage->next;
    cout << "Klik Forward     : " << currentPage->data << endl;
    cout << endl;
 
    cout << "Hapus 'youtube.com' dari history" << endl;
    deleteNode(head, tail, "youtube.com");
    traverseForward(head);
    traverseBackward(tail);
 
    freeList(head);
}
 
void task8PredictBeforeRunning() {
    Node* head = nullptr;
    Node* tail = nullptr;
 
    appendNode(head, tail, "A");
    appendNode(head, tail, "B");
    appendNode(head, tail, "C");
    appendNode(head, tail, "D");
 
    cout << "Sebelum hapus C:" << endl;
    traverseForward(head);
    traverseBackward(tail);
    cout << endl;
 
    deleteNode(head, tail, "C");
 
    cout << "Sesudah hapus C:" << endl;
    traverseForward(head);
    traverseBackward(tail);
 
    freeList(head);
}
 
void task9BreakAndFix() {
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* c = nullptr;
 
    cout << "BUGGY (lupa update D->prev):" << endl;
    appendNode(head, tail, "A");
    appendNode(head, tail, "B");
    appendNode(head, tail, "C");
    appendNode(head, tail, "D");
    c = head->next->next;
    deleteNodeBuggy(head, tail, c);
    traverseForward(head);
    traverseBackward(tail);
    freeList(head);
    delete c;
    cout << endl;
 
    head = nullptr;
    tail = nullptr;
 
    cout << "FIXED (next dan prev sama-sama diupdate):" << endl;
    appendNode(head, tail, "A");
    appendNode(head, tail, "B");
    appendNode(head, tail, "C");
    appendNode(head, tail, "D");
    deleteNode(head, tail, "C");
    traverseForward(head);
    traverseBackward(tail);
    freeList(head);
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
    cout << endl;
 
    cout << "--- Task 7: Real-World Experiment (Browser History) ---" << endl;
    task7BrowserHistory();
    cout << endl;
 
    cout << "--- Task 8: Predict Before Running (delete C dari A, B, C, D) ---" << endl;
    task8PredictBeforeRunning();
    cout << endl;
 
    cout << "--- Task 9: Break and Fix ---" << endl;
    task9BreakAndFix();
 
    freeList(head);
    return 0;
}