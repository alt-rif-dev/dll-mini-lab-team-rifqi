#include <vector>
#include <iostream>
#include <string>

#define main original_main
#include "task8_predict.cpp"
#undef main

int passed = 0;
int failed = 0;

void check(const string& name, bool ok){
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << endl;
    if (ok) passed++; else failed++;
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

void deleteNodeBuggy(Node*& head, Node*& tail, Node* target){
    if (target == nullptr) return;
    if (target->prev != nullptr) target->prev->next = target->next;
    else head = target->next;
    if (target->next == nullptr) tail = target->prev;
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

Node* findNode(Node* head, const string& value){
    for (Node* c = head; c != nullptr; c = c->next) {
        if (c->data == value) return c;
    }
    return nullptr;
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

    cout << "--- INSERT TAIL ---" << endl;
    appendNode(head, tail, "A");
    check("append ke list kosong: head == tail == A", verify(head, tail, {"A"}) && head == tail);
    appendNode(head, tail, "B");
    appendNode(head, tail, "C");
    check("append beberapa kali: A <-> B <-> C", verify(head, tail, {"A", "B", "C"}));
    freeAll(head);

    cout << "\n--- DELETE ---" << endl;
    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, findNode(head, "A"));
    check("hapus head: B <-> C <-> D", verify(head, tail, {"B", "C", "D"}));
    freeAll(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, findNode(head, "D"));
    check("hapus tail: A <-> B <-> C", verify(head, tail, {"A", "B", "C"}));
    freeAll(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, findNode(head, "C"));
    check("hapus tengah: A <-> B <-> D", verify(head, tail, {"A", "B", "D"}));
    freeAll(head);

    buildManual(head, tail, {"A"});
    deleteNode(head, tail, findNode(head, "A"));
    check("hapus satu-satunya node: list kosong, head & tail nullptr", verify(head, tail, {}));

    buildManual(head, tail, {"A", "B"});
    deleteNode(head, tail, findNode(head, "B"));
    check("hapus node terakhir dari 2 node: A saja", verify(head, tail, {"A"}) && head == tail);
    freeAll(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, findNode(head, "A"));
    deleteNode(head, tail, findNode(head, "D"));
    check("hapus head lalu tail: B <-> C", verify(head, tail, {"B", "C"}));
    freeAll(head);

    buildManual(head, tail, {"A", "B", "C"});
    deleteNode(head, tail, nullptr);
    check("hapus nullptr (node tidak ketemu): list tidak berubah", verify(head, tail, {"A", "B", "C"}));
    freeAll(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, findNode(head, "Z"));
    check("hapus node yang tidak ada: list tidak berubah", verify(head, tail, {"A", "B", "C", "D"}));
    freeAll(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    while (head != nullptr) deleteNode(head, tail, head);
    check("hapus semua dari head satu per satu: list kosong", verify(head, tail, {}));

    buildManual(head, tail, {"A", "B", "C", "D"});
    while (tail != nullptr) deleteNode(head, tail, tail);
    check("hapus semua dari tail satu per satu: list kosong", verify(head, tail, {}));

    cout << "\n--- GABUNGAN ---" << endl;
    buildManual(head, tail, {"A", "B", "C"});
    deleteNode(head, tail, findNode(head, "C"));
    appendNode(head, tail, "X");
    check("hapus tail lalu append: A <-> B <-> X", verify(head, tail, {"A", "B", "X"}));
    freeAll(head);

    buildManual(head, tail, {"A"});
    deleteNode(head, tail, findNode(head, "A"));
    appendNode(head, tail, "Z");
    check("kosongkan list lalu append lagi: Z", verify(head, tail, {"Z"}) && head == tail);
    freeAll(head);

    cout << "\n--- SANITY CHECK PENGUJI ---" << endl;
    buildManual(head, tail, {"A", "B", "C", "D"});
    Node* c = findNode(head, "C");
    deleteNodeBuggy(head, tail, c);
    check("verify() mendeteksi bug prev yang terlupa (harus mendeteksi)", !verify(head, tail, {"A", "B", "D"}));
    freeAll(head);
    delete c;

    cout << "\nHasil: " << passed << " PASS, " << failed << " FAIL" << endl;
    return failed == 0 ? 0 : 1;
}