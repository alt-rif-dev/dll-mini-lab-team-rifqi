# Test Report - PR #1 (Task 1-2: Node dan Build List)

**Tester:** Muhammad Ghassan Firdian
**File yang dites:** main.cpp
**Cara tes:** copy `tester_task1_2.cpp` ke folder yang sama dengan `main.cpp`, lalu
`g++ -std=c++17 -Wall -Wextra -o tester tester_task1_2.cpp` dan `.\tester`

## Hasil
| No | Skenario | Hasil |
|----|----------|-------|
| 1 | createNode menyimpan data, prev dan next awal nullptr | PASS |
| 2 | displayList dengan list kosong (nullptr) | PASS, tidak crash, hanya newline |
| 3 | displayList dengan 1 node | PASS, tanpa panah |
| 4 | Data string kosong | PASS |
| 5 | Data string panjang (1000 karakter) | PASS |
| 6 | Karakter spesial | PASS |
| 7 | Data duplikat | PASS |
| 8 | Output main sesuai spesifikasi Task 2 | PASS |
| 9 | Compile dengan -Wall -Wextra | Tidak ada warning |

## Temuan (bug dan saran)
1. **Memory leak (minor).** Node dibuat dengan `new` tapi tidak pernah di-`delete`
   (terdeteksi AddressSanitizer). Untuk program kecil tidak berdampak, tapi sebaiknya
   ada fungsi pembersih list di akhir program.
2. **Belum ada `#include <string>`.** Tetap jalan di g++, tapi bisa error di compiler lain.
3. **Pointer `prev` belum bisa diuji lewat program.** Task 2 hanya traversal maju, jadi
   kebenaran semua `prev` baru terbukti setelah ada backward traversal (Task 4).

## Kesimpulan
Task 1-2 lulus semua tes. Tidak ada bug fungsional. Dua temuan di atas bersifat saran.