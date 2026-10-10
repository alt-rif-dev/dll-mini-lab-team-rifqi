#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#define main original_main
#include "main.cpp"
#undef main

int passed = 0;
int failed = 0;

void check(const string& name, bool ok){
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << endl;
    if (ok) passed++; else failed++;
}

string capture(void (*fn)()){
    ostringstream buf;
    streambuf* old = cout.rdbuf(buf.rdbuf());
    fn();
    cout.rdbuf(old);
    return buf.str();
}

bool has(const string& text, const string& part){
    return text.find(part) != string::npos;
}

void buildManual(Node*& head, Node*& tail, const vector<string>& values){
    head = nullptr;
    tail = nullptr;
    for (size_t i = 0; i < values.size(); i++) appendNode(head, tail, values[i]);
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
    freeList(head);

    cout << "\n--- DELETE ---" << endl;
    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, "A");
    check("hapus head: B <-> C <-> D", verify(head, tail, {"B", "C", "D"}));
    freeList(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, "D");
    check("hapus tail: A <-> B <-> C", verify(head, tail, {"A", "B", "C"}));
    freeList(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, "C");
    check("hapus tengah (C): A <-> B <-> D", verify(head, tail, {"A", "B", "D"}));
    freeList(head);

    buildManual(head, tail, {"A"});
    deleteNode(head, tail, "A");
    check("hapus satu-satunya node: list kosong, head & tail nullptr", verify(head, tail, {}));

    buildManual(head, tail, {"A", "B"});
    deleteNode(head, tail, "B");
    check("hapus node terakhir dari 2 node: A saja", verify(head, tail, {"A"}) && head == tail);
    freeList(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, "A");
    deleteNode(head, tail, "D");
    check("hapus head lalu tail: B <-> C", verify(head, tail, {"B", "C"}));
    freeList(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, "Z");
    check("hapus data yang tidak ada: list tidak berubah", verify(head, tail, {"A", "B", "C", "D"}));
    freeList(head);

    head = nullptr; tail = nullptr;
    deleteNode(head, tail, "A");
    check("hapus dari list kosong: tidak crash, tetap kosong", verify(head, tail, {}));

    buildManual(head, tail, {"A", "B", "A", "C"});
    deleteNode(head, tail, "A");
    check("data duplikat: hanya kemunculan pertama yang dihapus (B <-> A <-> C)",
          verify(head, tail, {"B", "A", "C"}));
    freeList(head);

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, "A"); deleteNode(head, tail, "B");
    deleteNode(head, tail, "C"); deleteNode(head, tail, "D");
    check("hapus semua dari depan satu per satu: list kosong", verify(head, tail, {}));

    buildManual(head, tail, {"A", "B", "C", "D"});
    deleteNode(head, tail, "D"); deleteNode(head, tail, "C");
    deleteNode(head, tail, "B"); deleteNode(head, tail, "A");
    check("hapus semua dari belakang satu per satu: list kosong", verify(head, tail, {}));

    cout << "\n--- GABUNGAN ---" << endl;
    buildManual(head, tail, {"A", "B", "C"});
    deleteNode(head, tail, "C");
    appendNode(head, tail, "X");
    check("hapus tail lalu append: A <-> B <-> X", verify(head, tail, {"A", "B", "X"}));
    freeList(head);

    buildManual(head, tail, {"A"});
    deleteNode(head, tail, "A");
    appendNode(head, tail, "Z");
    check("kosongkan list lalu append lagi: Z", verify(head, tail, {"Z"}) && head == tail);
    freeList(head);

    cout << "\n--- OUTPUT task8PredictBeforeRunning() ---" << endl;
    string out8 = capture(task8PredictBeforeRunning);
    check("sebelum hapus C: Forward A -> B -> C -> D", has(out8, "Forward: A -> B -> C -> D"));
    check("sebelum hapus C: Backward D -> C -> B -> A", has(out8, "Backward: D -> C -> B -> A"));
    check("sesudah hapus C: Forward A -> B -> D", has(out8, "Sesudah hapus C:\nForward: A -> B -> D"));
    check("sesudah hapus C: Backward D -> B -> A", has(out8, "Backward: D -> B -> A"));

    cout << "\n--- OUTPUT task9BreakAndFix() ---" << endl;
    string out9 = capture(task9BreakAndFix);
    check("BUGGY: forward kelihatan benar (A -> B -> D)", has(out9, "BUGGY (lupa update D->prev):\nForward: A -> B -> D"));
    check("BUGGY: backward masih lewat C (D -> C -> B -> A)", has(out9, "Backward: D -> C -> B -> A"));
    check("FIXED: forward A -> B -> D", has(out9, "FIXED (next dan prev sama-sama diupdate):\nForward: A -> B -> D"));
    check("FIXED: backward D -> B -> A", has(out9, "FIXED (next dan prev sama-sama diupdate):\nForward: A -> B -> D\nBackward: D -> B -> A"));

    cout << "\n--- SANITY CHECK PENGUJI ---" << endl;
    buildManual(head, tail, {"A", "B", "C", "D"});
    Node* c = head->next->next;
    deleteNodeBuggy(head, tail, c);
    check("verify() mendeteksi bug prev yang terlupa (harus mendeteksi)", !verify(head, tail, {"A", "B", "D"}));
    freeList(head);
    delete c;

    cout << "\nHasil: " << passed << " PASS, " << failed << " FAIL" << endl;
    return failed == 0 ? 0 : 1;
}