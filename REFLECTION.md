## Nayaga 

**Peran:** Builder (Task 5-6) dan Tester (Task 7-9)

### My main contribution

**Builder, Task 5-6.** Saya mengimplementasikan fungsi penyisipan di tengah dan penghapusan node ke dalam proyek tim tanpa mengubah kode Task 1-4 yang sudah ada:

- **Task 5 (Insert in the Middle):** Membuat fungsi `insertAfter()` untuk menyisipkan node baru (`Song X`) di antara `Song B` dan `Song C` dengan mengatur ulang pointer `next` dan `prev` secara presisi.
- **Task 6 (Delete a Node):** Membuat fungsi `deleteNode()` untuk menghapus node target (`Song C`) serta memperbarui koneksi pointer tetangga agar struktur list tetap utuh saat ditelusuri maju maupun mundur.
- **Integrasi Kode:** Menggabungkan seluruh implementasi dari Task 1 sampai Task 6 ke dalam `main.cpp` secara bersih tanpa komentar penjelasan (`//`).

**Tester, Task 7-9.** Saya melakukan pengujian dan verifikasi untuk bagian akhir eksperimen:
- Menguji skenario dunia nyata (Task 7) pada simulasi *Browser History*, menguji prediksi program saat node dihapus (Task 8), serta menganalisis perbedaan struktur pointer pada eksperimen *Break and Fix* (Task 9).
- Memastikan bahwa hasil eksekusi program sesuai dengan ekspektasi modul eksperimen (*Predict -> Run -> Observe -> Change -> Explain*).

### What I learned about next and prev

- Pointer `next` digunakan untuk bergerak maju ke node berikutnya, sedangkan `prev` digunakan untuk bergerak mundur ke node sebelumnya.
- Saat melakukan operasi penyisipan (*insert*) atau penghapusan (*delete*), kedua arah pointer (`next` dan `prev`) harus diperbarui secara bersamaan agar rantai *Doubly Linked List* tidak terputus.
- Pada operasi penghapusan node di ujung list, penanganan khusus pada pointer `head` atau `tail` sangat penting agar tidak terjadi kesalahan akses memori (*segmentation fault*).

### The hardest part

Bagian tersulit adalah memastikan bahwa penyesuaian pointer pada fungsi `insertAfter` dan `deleteNode` tidak mengabaikan kondisi batas (*edge cases*), seperti ketika node yang disisipkan berada tepat setelah node terakhir atau ketika menghapus node di tengah list. 

Selain itu, saya juga sempat mengalami kendala sinkronisasi di Git, seperti branch remote baru di GitHub yang tidak otomatis muncul di VS Code, sehingga saya harus menggunakan perintah `git fetch --all --prune` dan `git switch` untuk melacak dan menariknya ke komputer lokal.

### What AI helped me with

AI membantu merancang logika pointer untuk fungsi `insertAfter()` dan `deleteNode()`, menggabungkan kode secara utuh ke dalam struktur `main.cpp`, menyusun format *Test Report* pengujian, serta memberikan solusi langkah-langkah untuk mengatasi kendala sinkronisasi branch di Git dan VS Code. Detailnya terdokumentasi di `AI-NOTES.md`.

### What I changed or fixed myself

- Menyalin dan menyesuaikan fungsi Task 5 dan Task 6 agar selaras dengan struktur kode dasar dari tim tanpa merusak fungsi penelusuran sebelumnya.
- Menghapus seluruh komentar penjelasan (`//`) pada file kode program utama agar tampil bersih sesuai standar pengumpulan tugas.
- Melakukan verifikasi hasil kompilasi program menggunakan flag `-Wall -Wextra` dan memastikan tidak ada *warning* ataupun potensi *memory leak*.
- Menyelesaikan sendiri kendala Git dengan melakukan *fetch*, memperbarui referensi *remote branch*, serta melakukan *commit* dan *push* perubahan kode ke GitHub dengan aman.

### GitHub Issue / PR / Commit I contributed

- **Issue:** (Isi sesuai kontribusi issue kamu di GitHub, misal: Membuat isu terkait perbaikan pointer delete node)
- **Pull Request:** (Isi nomor atau tautan PR kamu, misal: PR Task 5-6 Insert & Delete Operation)
- **Commit:** Menambahkan implementasi Task 5 (insertAfter) dan Task 6 (deleteNode), membersihkan komentar kode, serta sinkronisasi branch Git.
- **Komentar/Review:** (Isi tautan komentar atau diskusi pada PR tim jika ada)