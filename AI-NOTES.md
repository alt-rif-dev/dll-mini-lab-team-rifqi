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
- Melaporkan temuan (`#include <string>`, memory leak minor, dan bug `insertAfter`) di Pull Request atau Issue [ISI NOMOR]

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
