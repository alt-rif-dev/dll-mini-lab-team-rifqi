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

// Tangkap output cout dari sebuah fungsi supaya bisa dicek isinya
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
    for (Node* c = head; c != nullptr && fwd.size() < 2000; c = c->next) fwd.push_back(c->data);
    for (Node* c = tail; c != nullptr && bwd.size() < 2000; c = c->prev) bwd.push_back(c->data);

    vector<string> rev(expected.rbegin(), expected.rend());
    return fwd == expected && bwd == rev;
}

// Simulasi tombol Back / Forward browser: berhenti di ujung list
void goForward(Node*& cur){ if (cur != nullptr && cur->next != nullptr) cur = cur->next; }
void goBack(Node*& cur){ if (cur != nullptr && cur->prev != nullptr) cur = cur->prev; }

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "--- NODE ---" << endl;
    Node* n = createNode("google.com");
    check("createNode: data benar, prev & next nullptr",
          n != nullptr && n->data == "google.com" && n->prev == nullptr && n->next == nullptr);
    delete n;

    cout << "\n--- LIST BROWSER HISTORY ---" << endl;
    vector<string> pages = {"google.com", "youtube.com", "github.com", "stackoverflow.com", "kampus.ac.id"};
    buildManual(head, tail, pages);
    check("5 halaman: traversal maju dan mundur benar", verify(head, tail, pages));

    cout << "\n--- NAVIGASI BACK / FORWARD ---" << endl;
    Node* cur = tail;
    goBack(cur); goBack(cur);
    check("Back 2 kali dari halaman terakhir: github.com", cur->data == "github.com");
    goForward(cur);
    check("Forward 1 kali: stackoverflow.com", cur->data == "stackoverflow.com");
    goBack(cur);
    check("Back lalu Forward kembali ke halaman yang sama", cur->data == "github.com" && cur->next->data == "stackoverflow.com");

    cur = tail;
    goForward(cur);
    check("Forward di halaman terakhir: tetap di tail, tidak crash", cur == tail);
    cur = head;
    goBack(cur);
    check("Back di halaman pertama: tetap di head, tidak crash", cur == head);

    cur = tail;
    for (int i = 0; i < 10; i++) goBack(cur);
    check("Back 10 kali (lebih dari panjang list): berhenti di head", cur == head);
    for (int i = 0; i < 10; i++) goForward(cur);
    check("Forward 10 kali: berhenti di tail", cur == tail);
    freeList(head);

    cout << "\n--- OUTPUT task7BrowserHistory() ---" << endl;
    string out = capture(task7BrowserHistory);
    check("output: Halaman sekarang = kampus.ac.id", has(out, "Halaman sekarang : kampus.ac.id"));
    check("output: Back pertama = stackoverflow.com", has(out, "Klik Back        : stackoverflow.com"));
    check("output: Back kedua = github.com", has(out, "Klik Back        : github.com"));
    check("output: Forward = stackoverflow.com", has(out, "Klik Forward     : stackoverflow.com"));
    check("output: forward setelah hapus youtube.com benar",
          has(out, "Forward: google.com -> github.com -> stackoverflow.com -> kampus.ac.id"));
    check("output: backward setelah hapus youtube.com benar",
          has(out, "Backward: kampus.ac.id -> stackoverflow.com -> github.com -> google.com"));

    cout << "\n--- EDGE CASE DATA ---" << endl;
    buildManual(head, tail, {"A"});
    check("list 1 node: head == tail, prev & next nullptr",
          verify(head, tail, {"A"}) && head == tail && head->prev == nullptr && head->next == nullptr);
    freeList(head);

    buildManual(head, tail, {"", "B", ""});
    check("data string kosong: urutan tetap benar", verify(head, tail, {"", "B", ""}));
    freeList(head);

    buildManual(head, tail, {"X", "X", "X"});
    check("data duplikat: urutan tetap benar", verify(head, tail, {"X", "X", "X"}));
    freeList(head);

    string panjang(1000, 'a');
    buildManual(head, tail, {panjang, "B"});
    check("data string panjang (1000 karakter)", verify(head, tail, {panjang, "B"}));
    freeList(head);

    buildManual(head, tail, {"Halaman #1 (utama)", "a/b\\c", "100% \"ok\""});
    check("karakter spesial", verify(head, tail, {"Halaman #1 (utama)", "a/b\\c", "100% \"ok\""}));
    freeList(head);

    cout << "\n--- SANITY CHECK PENGUJI ---" << endl;
    buildManual(head, tail, {"A", "B", "C"});
    head->next->prev = nullptr;
    check("verify() mendeteksi prev yang rusak (harus mendeteksi)", !verify(head, tail, {"A", "B", "C"}));
    head->next->prev = head;
    freeList(head);

    cout << "\nHasil: " << passed << " PASS, " << failed << " FAIL" << endl;
    return failed == 0 ? 0 : 1;
}