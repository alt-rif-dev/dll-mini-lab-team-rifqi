Task 5-6
Interaksi 1: Implementasi Logika Insert di Tengah dan Delete Node
Prompt
tolong buatkan code untuk task 5 dan 6

AI helped us with
Merancang fungsi insertAfter() untuk menyisipkan node baru (Song X) di antara dua node yang sudah ada dengan mengatur ulang pointer next dan prev secara akurat.

Merancang fungsi deleteNode() untuk menghapus node target (Song C) serta mengarahkan kembali pointer tetangganya agar rantai Doubly Linked List tidak terputus.

Menyediakan kode utuh dari Task 1 sampai Task 6 yang digabungkan agar dapat langsung dikompilasi dan diuji dalam satu file program.

What we changed/tested
Menyalin fungsi penambahan dan penghapusan node ke dalam file src/main.cpp.

Menguji fungsi insertAfter untuk memastikan Song X berhasil masuk di antara Song B dan Song C.

Menguji fungsi deleteNode untuk memastikan Song C terhapus dengan benar dan sisa node tetap terhubung sempurna saat ditelusuri maju maupun mundur.

Interaksi 2: Membersihkan Komentar dan Menyatukan Git Commit
Prompt
tolong kode yang sudah di tambahkan 5 dan 6 hapus note // nya
git commit nya 5 dan 6 disatukan

AI helped us with
Menghilangkan seluruh komentar penjelasan (//) di dalam kode agar tampak bersih dan sesuai standar pengumpulan tugas.

Memberikan perintah Git untuk menggabungkan proses staging dan commit Task 5 serta Task 6 menjadi satu riwayat (commit) yang rapi.

Memberikan solusi ketika Git meminta identitas konfigurasi akun (git config user.name dan git config user.email) sebelum melakukan commit.

What we changed/tested
Memperbarui isi kode di dalam repositori lokal menjadi versi bersih tanpa komentar.

Menjalankan perintah konfigurasi identitas Git agar komputer mengenali akun pemilik repositori.

Melakukan git add . dan git commit -m "Add middle insertion and delete-node pointer update" pada branch terkait.

Interaksi 3: Mengatasi Kendala Git Switch dan Git Push
Prompt
kenapa gak bisa git switch
gimana cara git push nya

AI helped us with
Menjelaskan penyebab error fatal: invalid reference karena branch target belum tersedia secara lokal, serta memberikan solusi menggunakan git fetch atau opsi -c saat switch.

Menjelaskan tata cara melakukan push branch ke GitHub secara aman menggunakan perintah git push origin <nama-branch>.

What we changed/tested
Memeriksa daftar branch aktif menggunakan perintah git branch.

Berhasil mengunggah (push) seluruh perubahan kode Task 5 dan Task 6 ke remote repository GitHub milik tim.