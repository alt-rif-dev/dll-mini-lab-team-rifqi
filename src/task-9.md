### Task 9 - Break and Fix

**What I changed:** Di `deleteNodeBuggy()` (`main.cpp`) saya menghapus bagian yang mengupdate `prev` milik node sesudahnya, yaitu `target->next->prev = target->prev;`. Versi benarnya ada di `deleteNode()` sebagai `current->next->prev = current->prev;`.

**What happened:**
- Forward: `A -> B -> D`
- Backward: `D -> C -> B -> A` (salah, C yang sudah dilepas masih muncul)

**Why:** Forward memakai `next`, dan `B->next` sudah diarahkan ke D sehingga C terlewati. Backward memakai `prev`, dan `D->prev` masih menunjuk ke C. Kalau node C langsung di-`delete`, `D->prev` menjadi dangling pointer (menunjuk memori yang sudah dibebaskan) dan program bisa crash. Pada demo, node pada versi buggy sengaja tidak di-delete supaya aman.

**Fix:** Update kedua arah, `prev->next` dan `next->prev`. Hasil setelah fix: Forward `A -> B -> D`, Backward `D -> B -> A`.