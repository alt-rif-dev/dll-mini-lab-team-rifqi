# Test Report - Task 3 & 4 (Forward & Backward Traversal)

**Tester:** Nayaga
**File yang dites:** task3_4_traversal.cpp (diuji menggunakan file test harness terpisah)
**Cara tes:** Simpan kode test harness dan file kode traversal di folder yang sama, lalu compile dengan perintah:
`g++ -std=c++17 -Wall -Wextra -o tester_task3_4 tester_task3_4.cpp` dan jalankan `.\tester_task3_4`

## Hasil
| No | Skenario | Hasil |
|----|----------|-------|
| 1 | Inisialisasi list 5 lagu secara manual dengan pointer dua arah | PASS |
| 2 | Forward Traversal dari head ke tail (Song A sampai Song E) | PASS |
| 3 | Backward Traversal dari tail ke head (Song E sampai Song A) | PASS |
| 4 | Ketepatan penggunaan pointer next untuk penelusuran maju | PASS |
| 5 | Ketepatan penggunaan pointer prev untuk penelusuran mundur | PASS |
| 6 | Penghentian loop traversal saat mencapai nullptr | PASS |
| 7 | Compile dengan flag -Wall -Wextra | Tidak ada warning |

## Temuan (bug dan saran)
1. **Format teks cetak (minor).** Fungsi bawaan mencetak label header statis (`Forward Traversal:` dan `Backward Traversal:`) di dalam fungsi, sehingga pemanggilan berulang atau pengujian otomatis akan menampilkan teks tersebut berulang kali di terminal. Sebaiknya pemisahan antara logika pencetakan label dan traversal dipisah agar lebih fleksibel.
2. **Penanganan list kosong.** Belum ada pengecekan kondisi awal `nullptr` di dalam fungsi `traverseForward` dan `traverseBackward`. Meskipun dalam skenario utama list sudah terisi, penambahan validasi `if (head == nullptr)` akan membuat fungsi jauh lebih aman dari potensi segmentation fault.

## Kesimpulan
Task 3 dan Task 4 lulus semua pengujian fungsional. Pointer `next` dan `prev` berfungsi dengan sempurna untuk melakukan navigasi secara bolak-balik pada Doubly Linked List. Temuan di atas hanya berupa catatan pemeliharaan kode agar lebih modular.