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

