#include <vector>
#include <iostream>
#include <string>

#define main original_main
#include "task5_6_implementation.cpp"
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

bool verify(Node* head, Node* tail, const vector<string>& expected){
    if (expected.empty()) return head == nullptr && tail == nullptr;
    if (head == nullptr || tail == nullptr) return false;
    if (head->prev != nullptr || tail->next != nullptr) return false;

    vector<string> fwd;
    vector<string> bwd;
    for (Node* c = head; c != nullptr && fwd.size() < 100; c = c->next) fwd.push_back(c->data);
    for (Node* c = tail; c != nullptr && bwd.size() < 100; c = c->prev) bwd.push_back(c->data);

    vector<string> rev(expected.rbegin(), expected.rend());
    return fwd == expected && bwd == rev;
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "--- PENGUJIAN TASK 5: INSERT AFTER ---" << endl;
    
    buildManual(head, tail, {"Song A", "Song B", "Song C", "Song D", "Song E"});
    insertAfter(head, "Song B", "Song X");
    check("Sisip Song X setelah Song B: A <-> B <-> X <-> C <-> D <-> E", 
          verify(head, tail, {"Song A", "Song B", "Song X", "Song C", "Song D", "Song E"}));
    freeAll(head);

    buildManual(head, tail, {"Song A", "Song B", "Song C"});
    insertAfter(head, "Song C", "Song D");
    check("Sisip Song D setelah Song C (tail lama): tail terupdate dengan benar", 
          verify(head, tail, {"Song A", "Song B", "Song C", "Song D"}) && tail->data == "Song D");
    freeAll(head);

    buildManual(head, tail, {"Song A", "Song B"});
    insertAfter(head, "Song Z", "Song X");
    check("Sisip setelah target tidak ada: list tidak berubah", 
          verify(head, tail, {"Song A", "Song B"}));
    freeAll(head);


    cout << "\n--- PENGUJIAN TASK 6: DELETE NODE ---" << endl;

    buildManual(head, tail, {"Song A", "Song B", "Song X", "Song C", "Song D", "Song E"});
    deleteNode(head, tail, "Song C");
    check("Hapus Song C di tengah: A <-> B <-> X <-> D <-> E", 
          verify(head, tail, {"Song A", "Song B", "Song X", "Song D", "Song E"}));
    freeAll(head);

    buildManual(head, tail, {"Song A", "Song B", "Song C"});
    deleteNode(head, tail, "Song A");
    check("Hapus head (Song A): head berpindah ke Song B", 
          verify(head, tail, {"Song B", "Song C"}) && head->data == "Song B");
    freeAll(head);

    buildManual(head, tail, {"Song A", "Song B", "Song C"});
    deleteNode(head, tail, "Song C");
    check("Hapus tail (Song C): tail mundur ke Song B", 
          verify(head, tail, {"Song A", "Song B"}) && tail->data == "Song B");
    freeAll(head);

    buildManual(head, tail, {"Song A"});
    deleteNode(head, tail, "Song A");
    check("Hapus satu-satunya node: list kosong, head & tail jadi nullptr", 
          verify(head, tail, {}));

    cout << "\n--- HASIL AKHIR PENGUJIAN ---" << endl;
    cout << "Total Berhasil (PASS): " << passed << endl;
    cout << "Total Gagal (FAIL): " << failed << endl;

    return failed == 0 ? 0 : 1;
}