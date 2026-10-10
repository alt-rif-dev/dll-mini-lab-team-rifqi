# Test Report - PR #__ (Task 7-8: Real-World Experiment dan Predict Before Running)

**Tester:** Rifqi Bhadrika Adwitiya
**File yang dites:** `main.cpp` (fungsi `task7BrowserHistory()`, `task8PredictBeforeRunning()`, `deleteNode`, `appendNode`, dan `task9BreakAndFix()` yang ikut terpanggil)
**Cara tes:** copy `tester_task7.cpp` dan `tester_task8.cpp` ke folder yang sama dengan `main.cpp`, lalu:

```
g++ -std=c++17 -Wall -Wextra -o tester7 tester_task7.cpp
.\tester7
g++ -std=c++17 -Wall -Wextra -o tester8 tester_task8.cpp
.\tester8
```

Tester memakai `#define main original_main` lalu `#include "main.cpp"`, jadi yang dites adalah fungsi asli di `main.cpp`, bukan salinan.

## Hasil Task 7 (Real-World Experiment: Browser History) - 21 PASS, 0 FAIL

| No | Skenario | Hasil |
|----|----------|-------|
| 1 | createNode menyimpan data, prev dan next awal nullptr | PASS |
| 2 | 5 halaman: traversal maju dan mundur benar | PASS |
| 3 | Back 2 kali dari halaman terakhir: github.com | PASS |
| 4 | Forward 1 kali: stackoverflow.com | PASS |
| 5 | Back lalu Forward kembali ke halaman yang sama | PASS |
| 6 | Forward di halaman terakhir: tetap di tail, tidak crash | PASS |
| 7 | Back di halaman pertama: tetap di head, tidak crash | PASS |
| 8 | Back 10 kali (melebihi panjang list): berhenti di head | PASS |
| 9 | Forward 10 kali: berhenti di tail | PASS |
| 10 | Output: Halaman sekarang = kampus.ac.id | PASS |
| 11 | Output: Back pertama = stackoverflow.com | PASS |
| 12 | Output: Back kedua = github.com | PASS |
| 13 | Output: Forward = stackoverflow.com | PASS |
| 14 | Output: forward setelah hapus youtube.com benar | PASS |
| 15 | Output: backward setelah hapus youtube.com benar | PASS |
| 16 | List 1 node: head == tail, prev dan next nullptr | PASS |
| 17 | Data string kosong | PASS |
| 18 | Data duplikat | PASS |
| 19 | Data string panjang (1000 karakter) | PASS |
| 20 | Karakter spesial | PASS |
| 21 | Sanity check: verify() mendeteksi prev yang rusak | PASS |

## Hasil Task 8 (Predict: A <-> B <-> C <-> D, hapus C) - 24 PASS, 0 FAIL

| No | Skenario | Hasil |
|----|----------|-------|
| 1 | Append ke list kosong: head == tail == A | PASS |
| 2 | Append beberapa kali: A <-> B <-> C | PASS |
| 3 | Hapus head: B <-> C <-> D | PASS |
| 4 | Hapus tail: A <-> B <-> C | PASS |
| 5 | Hapus tengah (C): A <-> B <-> D | PASS |
| 6 | Hapus satu-satunya node: list kosong, head dan tail nullptr | PASS |
| 7 | Hapus node terakhir dari 2 node: A saja | PASS |
| 8 | Hapus head lalu tail: B <-> C | PASS |
| 9 | Hapus data yang tidak ada: list tidak berubah | PASS |
| 10 | Hapus dari list kosong: tidak crash | PASS |
| 11 | Data duplikat: hanya kemunculan pertama yang dihapus | PASS |
| 12 | Hapus semua dari depan satu per satu: list kosong | PASS |
| 13 | Hapus semua dari belakang satu per satu: list kosong | PASS |
| 14 | Hapus tail lalu append: A <-> B <-> X | PASS |
| 15 | Kosongkan list lalu append lagi: Z | PASS |
| 16 | Output Task 8 sebelum hapus C: forward dan backward benar | PASS (2 cek) |
| 17 | Output Task 8 sesudah hapus C: A -> B -> D dan D -> B -> A | PASS (2 cek) |
| 18 | Output Task 9 BUGGY: forward A -> B -> D, backward masih lewat C | PASS (2 cek) |
| 19 | Output Task 9 FIXED: forward dan backward benar | PASS (2 cek) |
| 20 | Sanity check: verify() mendeteksi bug prev yang terlupa | PASS |

Compile dengan `-Wall -Wextra`: tidak ada warning. Dijalankan dengan AddressSanitizer dan UBSan: tidak ada error dan tidak ada memory leak, baik untuk tester maupun `main.cpp` sendiri.

## Temuan (bug dan saran)

1. **Bug di `insertAfter` (Task 5): tail tidak ikut diupdate.** Fungsi ini tidak menerima `tail`, jadi kalau target adalah node terakhir, node baru masuk setelah tail tapi variabel `tail` tetap menunjuk node lama. Dibuktikan dengan `A <-> B`, lalu `insertAfter(head, "B", "X")`: forward menampilkan `A -> B -> X`, tapi backward hanya `B -> A`. Untuk Task 5 (sisip di tengah, setelah Song B) aman, tapi akan kena kalau dosen minta "tambah node di ujung" saat demo. Saran: ubah signature jadi `insertAfter(Node* head, Node*& tail, ...)` dan tambahkan `else tail = newNode;` di dalam `if (current->next != nullptr)`.
2. **`task7BrowserHistory()` memakai `currentPage->prev` dan `->next` tanpa cek nullptr.** Aman untuk data sekarang (5 halaman), tapi akan crash kalau list diperpendek atau tombol Back ditekan terlalu banyak. Saran minor: cek dulu `if (currentPage->prev != nullptr)`.
3. **`deleteNode` hanya menghapus kemunculan pertama kalau ada data duplikat.** Ini perilaku yang masuk akal, cukup dicatat di README supaya jelas.
4. Tidak ada `#include <vector>` yang dibutuhkan di `main.cpp`, dan tidak ada memory leak. Tidak ada saran untuk bagian itu.

## Kesimpulan

Task 7 dan Task 8 lulus semua tes (45 dari 45 cek) dan hasil prediksi Task 8 sesuai: setelah C dihapus, forward `A -> B -> D` dan backward `D -> B -> A`. Ada satu bug fungsional di `insertAfter` untuk kasus sisip setelah tail (temuan 1) yang sebaiknya diperbaiki Builder sebelum PR di-merge.