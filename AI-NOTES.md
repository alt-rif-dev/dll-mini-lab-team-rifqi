## Interaksi: Implementasi Task 5-6 (Insert di Tengah & Delete Node)

### Prompt
> 

### AI helped us with
- Merancang fungsi `insertAfter()` untuk menyisipkan node baru (`Song X`) di antara dua node yang sudah ada (`Song B` dan `Song C`) dengan mengatur ulang pointer `next` dan `prev` secara akurat[cite: 2].
- Merancang fungsi `deleteNode()` untuk menghapus node target (`Song C`) serta mengarahkan kembali pointer tetangganya agar rantai *Doubly Linked List* tidak terputus[cite: 2].
- Menggabungkan kode dari Task 1 sampai Task 6 secara utuh tanpa komentar penjelasan (`//`) agar siap dikompilasi dan diuji dalam satu file program.

### What we changed/tested
- Menyalin fungsi `insertAfter` dan `deleteNode` ke dalam file kode utama `main.cpp`.
- Menguji fungsi `insertAfter` untuk memastikan `Song X` berhasil masuk di antara `Song B` dan `Song C`[cite: 2].
- Menguji fungsi `deleteNode` untuk memastikan `Song C` terhapus dengan benar serta melakukan verifikasi traversal maju dan mundur[cite: 2].

---

## Interaksi: Pembuatan Test Report & Kendala Git Push Task 5-6

### Prompt
> 

### AI helped us with
- Membuatkan format laporan pengujian (*Test Report*) lengkap dengan tabel skenario pengujian fungsional untuk Task 5 dan Task 6.
- Menjelaskan cara mengatasi kendala sinkronisasi branch di VS Code menggunakan perintah `git fetch --all --prune` dan `git switch`.
- Memandu proses *staging*, *commit* gabungan Task 5-6, serta cara melakukan *push* ke remote repository GitHub dengan aman.

### What we changed/tested
- Menjalankan file pengujian untuk memvalidasi ketepatan pointer setelah operasi penyisipan dan penghapusan node.
- Menyelesaikan konfigurasi Git lokal dan berhasil melakukan *push* perubahan kode Task 5 dan Task 6 ke branch tim di GitHub.