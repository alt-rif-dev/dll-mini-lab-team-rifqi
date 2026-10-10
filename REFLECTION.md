Individual Reflection

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
