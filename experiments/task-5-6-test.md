# Test Report - Task 5 & 6 (Insert & Delete Operations)

**Tester:** Nayaga
**File yang dites:** `task5_6_operations.cpp` (diuji menggunakan file test harness terpisah)
**Cara tes:** Simpan kode test harness dan file kode operasi di folder yang sama, lalu compile dengan perintah:
`g++ -std=c++17 -Wall -Wextra -o tester_task5_6 tester_task5_6.cpp` dan jalankan `.\tester_task5_6`

## Hasil

| No | Skenario | Hasil | 
| ----- | ----- | ----- | 
| 1 | Inisialisasi awal list 5 lagu (`Song A` s.d. `Song E`) dengan pointer dua arah | PASS | 
| 2 | Task 5: Menyisipkan `Song X` setelah `Song B` di tengah list | PASS | 
| 3 | Task 5: Validasi penelusuran maju (`next`) dan mundur (`prev`) setelah penyisipan | PASS | 
| 4 | Task 6: Menghapus `Song C` di tengah list | PASS | 
| 5 | Task 6: Validasi pembaruan pointer `next` dan `prev` pada node tetangga setelah penghapusan | PASS | 
| 6 | Pengujian kasus batas (menghapus `head`, `tail`, dan node yang tidak ditemukan) | PASS | 
| 7 | Compile dengan flag `-Wall -Wextra` | Tidak ada warning | 

## Temuan (bug dan saran)

1. **Pembaruan Tail pada Task 5 (Minor).** Saat menyisipkan elemen baru tepat setelah node `tail` lama, pastikan pointer `tail` ikut diperbarui agar tidak terjadi ketidakcocokan referensi ujung list.

2. **Validasi Target Kosong.** Penambahan pengecekan awal untuk memastikan string target atau list tidak bernilai `nullptr` akan meningkatkan ketahanan fungsi dari potensi *segmentation fault*.

## Kesimpulan

Task 5 dan Task 6 lulus seluruh pengujian fungsional. Operasi penyisipan (`insertAfter`) dan penghapusan (`deleteNode`) terbukti berhasil memperbarui koneksi pointer `next` dan `prev` secara presisi tanpa merusak integritas Doubly Linked List.