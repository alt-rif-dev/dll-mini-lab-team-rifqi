## Interaksi 1: Belajar logika Node dan Linked List

### Prompt

```
tolong ajarin aja gimana nulis code dan logicnya biar aku paham
```

### AI helped us with

- Menjelaskan konsep node (`data`, `prev`, `next`) dan pointer
- Menjelaskan kenapa menyambung dua node butuh dua baris (`a->next = b` dan `b->prev = a`)
- Menjelaskan traversal dengan pointer `current` yang berpindah dari node ke node

### What we changed/tested

- Menulis kodenya di `src/main.cpp` (struct `Node`, `createNode`, penyambungan 5 node, `displayList`)
- Compile dan menjalankan program untuk memastikan list tampil dari Song A sampai Song E

---

## Interaksi 2: Debug infinite loop pada `displayList`

### Prompt

```
kenapa ngebug ya
```

(dengan menempelkan kode `main.cpp` yang berisi fungsi `displayList`)

### AI helped us with

- Menemukan penyebab bug: baris `current = current->next;` berada di dalam blok `if`, sehingga di node terakhir `current` tidak pernah berpindah ke `nullptr` dan loop berjalan terus
- Menunjukkan bahwa `cout << endl;` di dalam loop membuat setiap node tercetak di baris berbeda

### What we changed/tested

- Memindahkan `current = current->next;` keluar dari `if` supaya selalu dieksekusi di setiap putaran
- Memindahkan `cout << endl;` ke luar `while`
- Compile ulang dan menjalankan program: output menjadi `Song A <-> Song B <-> Song C <-> Song D <-> Song E`
- Commit perbaikan: `fixing bug and add main.exe`

### Bagaimana kami memverifikasi hasil AI

Program dijalankan ulang dan outputnya dibandingkan dengan hasil yang diminta soal. Putaran loop di node terakhir juga ditelusuri satu per satu untuk memahami kenapa versi lama tidak pernah berhenti.

---

## Interaksi 3: Alur Git dan Pull Request

### Prompt

```
sudah ku commit dan push di branch create list, trus apa skrg
```

(dan beberapa pertanyaan lanjutan tentang struktur folder, merge conflict, dan memilih Reviewer)

### AI helped us with

- Menjelaskan cara membuat struktur folder `src/`, `experiments/`, `screenshots/` dengan benar (sebelumnya folder tertumpuk)
- Menjelaskan cara membuka Pull Request, memilih Reviewer, dan menghubungkan Issue dengan `Closes #1`
- Menjelaskan cara menyelesaikan merge conflict pada `README.md`
- Mengingatkan agar `main.exe` tidak ikut ter-commit (pakai `.gitignore`)

### What we changed/tested

- Memperbaiki struktur folder sehingga `src`, `experiments`, dan `screenshots` sejajar
- Menyelesaikan conflict `README.md` dan melakukan commit `Resolve README merge conflict`
- Membuka PR #2 yang terhubung dengan Issue #1

---
