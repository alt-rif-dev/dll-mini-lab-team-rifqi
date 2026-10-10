Name: Rifqi Bhadrika Adwitiya

My main contribution: Sebagai Builder di Task 1-2, saya membuat repository tim, menyiapkan struktur folder, menulis README.md, lalu membuat struct Node, fungsi createNode(), membangun list 5 node (Song A sampai Song E), dan menulis displayList(). Saya juga membuka Issue #1 dan Pull Request #2, serta menyelesaikan merge conflict pada README.md.

What I learned about next and prev: next menunjuk ke node sesudahnya dan dipakai untuk bergerak maju, sedangkan prev menunjuk ke node sebelumnya dan dipakai untuk bergerak mundur. Saat menyambung dua node, kedua pointer harus diisi: a->next = b dan b->prev = a. Kalau salah satunya terlupa, traversal di satu arah akan putus. Node pertama punya prev = nullptr dan node terakhir punya next = nullptr, dan nilai nullptr itulah yang menghentikan loop traversal.

The hardest part: Bug pada displayList(): program tidak pernah berhenti. Awalnya saya tidak tahu penyebabnya, karena program terlihat benar. Setelah ditelusuri putaran demi putaran, ternyata current = current->next berada di dalam if, sehingga di node terakhir current tidak pernah berpindah ke nullptr. Bagian lain yang sulit adalah merge conflict di README.md, karena baru pertama kali menyelesaikannya.

What AI helped me with: Claude membantu menjelaskan isi soal dalam bahasa Indonesia, menjelaskan logika node dan pointer, menemukan penyebab bug infinite loop di displayList(), serta menjelaskan alur Git (branch, Pull Request, merge conflict). Detailnya ada di AI-NOTES.md.

What I changed or fixed myself: Saya memperbaiki displayList() dengan memindahkan current = current->next keluar dari if dan memindahkan cout << endl ke luar while. Saya juga memperbaiki struktur folder yang awalnya tertumpuk (src/experiments/screenshots) menjadi sejajar, dan menyelesaikan conflict README.md sendiri.

GitHub Issue / PR / Commit I contributed:

Issue: #1 (Task 1-2: Create Node struct and 5 node list)
PR: #2 (Task 1-2: Create Node and build list)
Commit:
add node struct and make createNode function
add displaylist procedure and main
fixing bug and add main.exe
Resolve README merge conflict


---

Name: Muhammad Dzaki Lukmanul Hakim

My main contribution:
Sebagai Builder di Task 3-4, saya bertanggung jawab mengimplementasikan logika penelusuran dua arah (Forward dan Backward Traversal) pada repositori tim. Saya menulis fungsi utama untuk mencetak list dari depan ke belakang (`Song A` sampai `Song E`) menggunakan pointer `next` dan fungsi kustom tambahan untuk mencetak secara terbalik dari belakang ke depan menggunakan pointer `prev`.

**What I learned about next and prev:** 
Pointer `next` menunjuk ke node sesudahnya dan digunakan untuk bergerak maju (*forward*), sedangkan pointer `prev` menunjuk ke node sebelumnya untuk bergerak mundur (*backward*). Saya belajar bahwa penelusuran mundur hanya bisa berhasil jika pointer `prev` pada setiap node sudah terhubung dengan benar. Proses iterasi/looping pada kedua arah ini akan terus berjalan dan baru akan berhenti ketika pointer menemukan nilai `nullptr`.

**The hardest part:** 
Bagian tersulit adalah saat mencoba berpindah ke branch kerja menggunakan terminal. Saya sempat mengalami error *fatal: a branch is expected* karena salah memasukkan jalur remote branch lengkap (`remotes/origin/...`) ke dalam perintah Git switch. Selain itu, merancang logika pemformatan tanda panah `<->` agar tercetak rapi di antara node tanpa muncul berlebih di ujung list juga membutuhkan ketelitian logika di awal.

**What AI helped me with:** 
AI membantu memberikan referensi algoritma loop bersyarat untuk membaca *Doubly Linked List* secara mundur menggunakan pointer `prev`, serta memberikan solusi instan mengenai cara kerja perintah `git switch` yang benar saat mendapati error pembacaan remote branch.

**What I changed or fixed myself:** 
Saya memperbaiki kesalahan perintah Git secara mandiri dengan membuang teks jalur remote dan langsung menggunakan perintah `git switch [nama-branch]` yang valid. Saya juga menulis dan memodifikasi sendiri fungsi cetak tambahan (`printListFormatted`) dengan menyisipkan kondisi `if` khusus agar tampilan *output* di terminal rapi menggunakan pembatas tanda panah dua arah.

**GitHub Issue / PR / Commit I contributed:**
*(Catatan: Sesuaikan nomor Issue/PR dan pesan commit di bawah ini dengan riwayat asli di GitHub tim Anda)*

- **Issue:** #3 (Task 3-4: Implement Forward and Backward Traversal)
- **PR:** #4 (Task 3-4: Traversal Logic and Custom Formatted Output)
- **Commit:**
  - `add forward and backward traversal functions`
  - `add custom formatted output with arrows`
  - `fix switch branch reference issue`

---

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

