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