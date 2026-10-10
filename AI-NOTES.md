## Rifqi Bhadrika Adwitiya

## Interaksi 1: Belajar logika Node dan Linked List

### Prompt

```
tolong ajarin aja gimana nulis code dan logicnya biar aku paham
```

### AI helped us with

- Menjelaskan konsep node (`data`, `prev`, `next`) dan pointer
- Menjelaskan kenapa menyambung dua node butuh dua baris (`a->next = b` dan `b->prev = a`)
- Menjelaskan traversal dengan pointer `current` yang berpindah dari node ke node

### What we changed/tested

- Menulis kodenya di `src/main.cpp` (struct `Node`, `createNode`, penyambungan 5 node, `displayList`)
- Compile dan menjalankan program untuk memastikan list tampil dari Song A sampai Song E

---

## Interaksi 2: Debug infinite loop pada `displayList`

### Prompt

```
kenapa ngebug ya
```

(dengan menempelkan kode `main.cpp` yang berisi fungsi `displayList`)

### AI helped us with

- Menemukan penyebab bug: baris `current = current->next;` berada di dalam blok `if`, sehingga di node terakhir `current` tidak pernah berpindah ke `nullptr` dan loop berjalan terus
- Menunjukkan bahwa `cout << endl;` di dalam loop membuat setiap node tercetak di baris berbeda

### What we changed/tested

- Memindahkan `current = current->next;` keluar dari `if` supaya selalu dieksekusi di setiap putaran
- Memindahkan `cout << endl;` ke luar `while`
- Compile ulang dan menjalankan program: output menjadi `Song A <-> Song B <-> Song C <-> Song D <-> Song E`
- Commit perbaikan: `fixing bug and add main.exe`

### Bagaimana kami memverifikasi hasil AI

Program dijalankan ulang dan outputnya dibandingkan dengan hasil yang diminta soal. Putaran loop di node terakhir juga ditelusuri satu per satu untuk memahami kenapa versi lama tidak pernah berhenti.

---
## Muhammad Dzaki Lukmanul Hakim

## Interaksi 3: Alur Git dan Pull Request

### Prompt

```
sudah ku commit dan push di branch create list, trus apa skrg
```

(dan beberapa pertanyaan lanjutan tentang struktur folder, merge conflict, dan memilih Reviewer)

### AI helped us with

- Menjelaskan cara membuat struktur folder `src/`, `experiments/`, `screenshots/` dengan benar (sebelumnya folder tertumpuk)
- Menjelaskan cara membuka Pull Request, memilih Reviewer, dan menghubungkan Issue dengan `Closes #1`
- Menjelaskan cara menyelesaikan merge conflict pada `README.md`
- Mengingatkan agar `main.exe` tidak ikut ter-commit (pakai `.gitignore`)

### What we changed/tested

- Memperbaiki struktur folder sehingga `src`, `experiments`, dan `screenshots` sejajar
- Menyelesaikan conflict `README.md` dan melakukan commit `Resolve README merge conflict`
- Membuka PR #2 yang terhubung dengan Issue #1

---
# Task 3-4

## Interaksi 1: Belajar Logika Penelusuran (Traversal)

### Prompt

### AI helped us with
- Menjelaskan konsep dasar penelusuran maju (Forward Traversal) dari node pertama ke node terakhir menggunakan pointer `next`.
- Menjelaskan konsep dasar penelusuran mundur (Backward Traversal) dari node terakhir kembali ke node pertama menggunakan pointer `prev`.
- Memberikan logika loop conditional (`while (current != nullptr)`) untuk mengakses nilai data di setiap node.

### What we changed/tested
- Menulis implementasi fungsi utama penelusuran di dalam file `src/main.cpp`.
- Melakukan compile dan menjalankan program untuk memastikan data lagu tampil berurutan dari Song A sampai Song E (untuk forward) dan dari Song E ke Song A (untuk backward).

---

## Interaksi 2: Implementasi Fungsi Tambahan Cetak Format (Formatting Output)

### Prompt

### AI helped us with
- Memberikan logika kondisi (`if (current->next != nullptr)`) di dalam loop agar tanda panah `<->` hanya dicetak di antara node dan tidak muncul di akhir ujung list.
- Membantu merancang fungsi tambahan `printListFormatted` agar visualisasi struktur data *Doubly Linked List* terlihat jelas di terminal.

### What we changed/tested
- Menambahkan fungsi cetak kustom ke dalam kode agar output terminal menampilkan format: `Song A <-> Song B <-> Song C <-> Song D <-> Song E`.
- Menguji fungsi tersebut pada penelusuran maju maupun mundur guna memastikan pointer `prev` dan `next` benar-benar terhubung secara dua arah.

---

## Interaksi 3: Mengatasi Kendala Git Remote Branch

### Prompt

### AI helped us with
- Menemukan penyebab error: perintah `git switch` mendeteksi argumen sebagai remote branch penuh (`remotes/origin/...`), bukan nama branch lokal yang valid.
- Memberikan solusi perbaikan perintah menggunakan cara modern `git switch task-1-2-create-list` agar Git otomatis melacak (track) remote branch dengan nama yang sesuai di komputer lokal.

### What we changed/tested
- Menjalankan perintah `git switch task-1-2-create-list` pada terminal repositori `dll-mini-lab-team-rifqi`.
- Berhasil berpindah (switch) ke branch target dengan aman tanpa mengalami status *detached HEAD*.

---

## Bagaimana kami memverifikasi hasil AI
1. **Verifikasi Output Code:** Menjalankan program hasil *compile* dan mencocokkannya dengan spesifikasi soal. Output cetak terformat terbukti mempermudah pelacakan arah pointer saat melompat maju (`next`) maupun mundur (`prev`).
2. **Verifikasi Status Git:** Menjalankan perintah `git branch` setelah mengikuti saran perbaikan perintah Git dari AI untuk memastikan posisi kerja tim sudah berada di branch yang tepat.


---

## Nayaga Radhitya


---

## Muhammad Ghassan Firdian

**Peran:** Builder (Task 7-9) dan Tester (Task 1-2)

### My main contribution

**Builder, Task 7-9.** Saya menambahkan tiga bagian ke main.cpp tim tanpa mengubah kode Task 1-6:

- **Task 7:** simulasi Browser History. Saya membuat 5 halaman dengan appendNode(), menampilkannya maju dan mundur, mensimulasikan tombol Back (prev) dan Forward (next), lalu menghapus satu halaman dengan deleteNode().
- **Task 8:** eksperimen Predict Before Running pada list A, B, C, D dengan node C dihapus. 
- **Task 9:** Break and Fix dengan membandingkan deleteNodeBuggy() dan `deleteNode()`. Catatannya ada di `experiments/task9_break_and_fix.md`.

**Tester, Task 1-2.** Saya membuat tester_task1_2.cpp (12 tes) dan tester_edge_cases.cpp (15 tes) untuk menguji list kosong, list satu node, hapus head, hapus tail, hapus node terakhir, dan append setelah hapus. Dari pengujian ini saya menemukan bahwa insertAfter() tidak memperbarui tail saat menyisipkan setelah node terakhir.

### What I learned about next and prev

- next dipakai untuk bergerak maju dan prev untuk bergerak mundur. Pada Browser History, Forward memakai next dan Back memakai prev.
- Saat menghapus node, kedua arah harus diperbarui: prev->next dan next->prev. Kalau salah satu terlupa, list bisa tampak benar dari satu arah tetapi salah dari arah lain.
- Kalau node yang dihapus ada di ujung, pointer head atau tail juga harus ikut diperbarui.

### The hardest part

Bagian tersulit adalah Task 9: memahami kenapa kode yang salah tampak benar pada forward traversal (A -> B -> D) dan baru ketahuan pada backward traversal (D -> C -> B -> A). Penyebabnya, B->next sudah menunjuk ke D, tetapi D->prev masih menunjuk ke C. Saya juga perlu memahami bahaya dangling pointer kalau node C langsung di-delete.

Selain itu, saya sempat kena beberapa error Git: pathspec did not match karena file belum ada di folder repo, git switch ditolak karena ada perubahan yang belum di-commit, dan git push ditolak karena branch di GitHub punya commit yang belum ada di laptop saya.

### What AI helped me with

Claude menjelaskan apa yang diminta di Task 7-9, membuat kode Task 7-9 yang disesuaikan dengan gaya `main.cpp` tim, membuat kode pengujian untuk peran Tester, dan menjelaskan penyebab serta solusi error Git. Detailnya ada di AI-NOTES.md.

### What I changed or fixed myself

- Memasukkan kode Task 7-9 ke repo tim dan menyesuaikannya dengan main.cpp terbaru (Task 1-6), sehingga fungsi yang sudah ada seperti traverseForward(), traverseBackward(), dan deleteNode() dipakai ulang tanpa mengubah kode anggota lain.
- Menghapus semua komentar dari file kode agar kode lebih bersih.
- Mengisi file catatan eksperimen task8_prediction.md dan task9_break_and_fix.md, lalu menyamakan formatnya dengan output main.cpp terbaru (Forward: A -> B -> D).
- Menaruh file pengujian (tester_task1_2.cpp, tester_edge_cases.cpp, dan edge-cases.md) di folder experiments/ dan men-commit-nya.
- Menyelesaikan sendiri tiga error Git: file belum ada di folder repo (saya salin ke folder yang benar), pindah branch ditolak (saya commit dulu perubahannya), dan push ditolak karena branch di GitHub punya commit baru.

### GitHub Issue / PR / Commit I contributed

- **Issue:** -
- **Pull Request:** #10 Task 7-9: Real-World Experiment, Predict Before Running, Break and Fix the Code
- **Commit:** Menambah Task 7-9: browser history, predict delete, break and fix, 
    Commit-ScreenShot, Add Task 9 to REFLECTION.m
- **Komentar/Review:** https://github.com/alt-rif-dev/dll-mini-lab-team-rifqi/pull/8#issuecomment-6092950432 , 

---

## Interaksi 4: Memahami tugas Builder Task 7-9

### Prompt

```
saya sebagai builder tasknya task 7-9 , disuruh ngapain aja
```

### AI helped us with

- Menjelaskan apa yang diminta di Task 7 (contoh dunia nyata), Task 8 (prediksi sebelum run), dan Task 9 (break and fix)
- Menjelaskan syarat GitHub per mahasiswa (Issue, commit, Pull Request, komentar) dan isi AI-NOTES.md serta REFLECTION.md
- Menyarankan menulis dan meng-commit prediksi Task 8 sebelum program dijalankan

### What we changed/tested

- Memilih Browser History sebagai contoh dunia nyata untuk Task 7
- Menulis prediksi Task 8 di `experiments/task8_prediction.md` sebelum menjalankan program

---

## Interaksi 5: Membuat kode Task 7-9 dan menyatukannya ke main.cpp tim

### Prompt

```
bantu lewat github sama buatin kodenya
```

```
ini adalah main.cpp dari task 5-6 kerjakan task 7-9
```

(dengan menempelkan `main.cpp` tim yang berisi Task 1-6)

### AI helped us with

- Membuat `appendNode`, `freeList`, `deleteNodeBuggy`, serta fungsi `task7BrowserHistory`, `task8PredictBeforeRunning`, dan `task9BreakAndFix`
- Menyesuaikan gaya kode dengan `main.cpp` tim (struct Node, createNode, traverseForward, traverseBackward) tanpa mengubah kode Task 1-6
- Membuat catatan eksperimen `task8_prediction.md` dan `task9_break_and_fix.md`
- Menghapus semua komentar dari file kode atas permintaan kami

### What we changed/tested

- Compile dengan `g++ -std=c++17 -Wall -Wextra` dan menjalankan program: Task 7, 8, 9 tampil berurutan setelah Task 6
- Membandingkan hasil Task 8 dengan prediksi: `A -> B -> D` (forward) dan `D -> B -> A` (backward)
- Membuktikan bug Task 9: pada versi buggy, forward `A -> B -> D` tampak benar tetapi backward `D -> C -> B -> A` salah
- [ISI SENDIRI: perubahan yang kami buat, contoh mengganti daftar halaman Browser History]

### Bagaimana kami memverifikasi hasil AI

Program dijalankan sendiri dan outputnya dibandingkan dengan prediksi yang sudah ditulis sebelumnya. Bug Task 9 dijelaskan ulang dengan menelusuri pointer D->prev dan B->next satu per satu. Kode juga diperiksa dengan AddressSanitizer dan tidak ada memory leak.

---

## Interaksi 6: Pengujian sebagai Tester

### Prompt

```
gini aja test codenya, experiment code saya jika ada bug error atau yg lainnya, atau hapus head bikin crash, insert tail, hapus node terakhir masih error, atau delete head delete tail dll
```

### AI helped us with

- Membuat `tester_task1_2.cpp` (12 tes) untuk createNode dan displayList: list kosong, 1 node, string kosong, string panjang, karakter spesial, data duplikat
- Membuat `tester_edge_cases.cpp` (15 tes) untuk append dan delete: hapus head, tail, tengah, satu-satunya node, node yang tidak ada, hapus semua dari head dan dari tail, serta append setelah hapus
- Membuat fungsi `verify()` yang memeriksa traversal maju, traversal mundur, `head->prev`, dan `tail->next`
- Menemukan bug pada `insertAfter()` Task 5: `tail` tidak diperbarui saat menyisipkan setelah node terakhir, sehingga node baru tidak muncul pada backward traversal

### What we changed/tested

- Menaruh file tes di folder `experiments/`, menjalankannya, dan mencatat hasil di `edge-cases.md`
- Hasil: semua tes PASS pada kode Task 1-2 dan pada fungsi hapus
- Melaporkan temuan (`#include <string>`, memory leak minor, dan bug `insertAfter`) di Pull Request atau Issue 

### Bagaimana kami memverifikasi hasil AI

Tes diuji dengan sengaja memasukkan versi delete yang salah (lupa update `prev`) dan `verify()` berhasil mendeteksinya. Tes juga dijalankan dengan AddressSanitizer dan bersih dari error memori. Bug `insertAfter` direproduksi dengan list A, B lalu menyisipkan X setelah B: forward `A -> B -> X` tetapi backward hanya `B -> A`.

---

### AI helped us with

- Menjelaskan bahwa `git add` hanya bisa menambahkan file yang benar-benar ada di folder repo, sehingga file harus disalin ke folder yang benar dulu
- Menjelaskan bahwa `git switch` ditolak karena ada perubahan yang belum di-commit, sehingga perubahan harus di-commit dulu sebelum pindah branch
- Menjelaskan bahwa `git push` ditolak karena branch di GitHub punya commit yang belum ada di laptop, dan menyarankan memakai branch sendiri agar tidak mengganggu branch anggota lain

### What we changed/tested

- Menyalin file ke folder `experiments/` di dalam repo lalu memeriksa dengan `git status`
- Men-commit perubahan sebelum berpindah branch
- [CEK: sesuaikan dengan yang benar-benar dilakukan, contoh membuat branch `tester-edge-cases` lalu push ke branch itu, atau `git pull` lalu push]
- Memastikan `tester.exe` tidak ikut ter-commit


### Task 9 - Break and Fix

**What I changed:** Di `deleteNodeBuggy()` (`main.cpp`) saya menghapus bagian yang mengupdate `prev` milik node sesudahnya, yaitu `target->next->prev = target->prev;`. Versi benarnya ada di `deleteNode()` sebagai `current->next->prev = current->prev;`.

**What happened:**
- Forward: `A -> B -> D`
- Backward: `D -> C -> B -> A` (salah, C yang sudah dilepas masih muncul)

**Why:** Forward memakai `next`, dan `B->next` sudah diarahkan ke D sehingga C terlewati. Backward memakai `prev`, dan `D->prev` masih menunjuk ke C. Kalau node C langsung di-`delete`, `D->prev` menjadi dangling pointer (menunjuk memori yang sudah dibebaskan) dan program bisa crash. Pada demo, node pada versi buggy sengaja tidak di-delete supaya aman.

**Fix:** Update kedua arah, `prev->next` dan `next->prev`. Hasil setelah fix: Forward `A -> B -> D`, Backward `D -> B -> A`.

---
