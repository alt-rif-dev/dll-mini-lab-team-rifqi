#include <vector>
#include <iostream>
#include <string>

#define main original_main
#include "task3_4_traversal.cpp"
#undef main

int passed = 0;
int failed = 0;

void check(const string& name, bool ok){
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << endl;
    if (ok) passed++; else failed++;
}

void buildManual(Node*& head, Node*& tail, const vector<string>& values){
    head = nullptr;
    tail = nullptr;
    for (size_t i = 0; i < values.size(); i++) {
        Node* n = createNode(values[i]);
        if (head == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
}

void freeAll(Node* head){
    while (head != nullptr) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "--- SETUP LIST UNTUK TASK 3 & 4 ---" << endl;
    buildManual(head, tail, {"Song A", "Song B", "Song C", "Song D", "Song E"});
    check("Inisialisasi list 5 lagu berhasil", head != nullptr && tail != nullptr);

    cout << "\n--- TASK 3: FORWARD TRAVERSAL ---" << endl;
    cout << "Expected output:" << endl;
    cout << "Forward Traversal:\nSong A\nSong B\nSong C\nSong D\nSong E\n" << endl;
    cout << "Actual output running:" << endl;
    traverseForward(head);

    cout << "\n--- TASK 4: BACKWARD TRAVERSAL ---" << endl;
    cout << "Expected output:" << endl;
    cout << "Backward Traversal:\nSong E\nSong D\nSong C\nSong B\nSong A\n" << endl;
    cout << "Actual output running:" << endl;
    traverseBackward(tail);

    freeAll(head);

    cout << "\n=== HASIL PENGUJIAN TRAVERSAL ===" << endl;
    cout << "Passed: " << passed << endl;
    cout << "Failed: " << failed << endl;

    return 0;
}