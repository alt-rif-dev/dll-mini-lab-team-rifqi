Name: Rifqi Bhadrika Adwitiya

My main contribution: Sebagai Builder di Task 1-2, saya membuat repository tim, menyiapkan struktur folder, menulis README.md, lalu membuat struct Node, fungsi createNode(), membangun list 5 node (Song A sampai Song E), dan menulis displayList(). Saya juga membuka Issue #1 dan Pull Request #2, serta menyelesaikan merge conflict pada README.md.

What I learned about next and prev: next menunjuk ke node sesudahnya dan dipakai untuk bergerak maju, sedangkan prev menunjuk ke node sebelumnya dan dipakai untuk bergerak mundur. Saat menyambung dua node, kedua pointer harus diisi: a->next = b dan b->prev = a. Kalau salah satunya terlupa, traversal di satu arah akan putus. Node pertama punya prev = nullptr dan node terakhir punya next = nullptr, dan nilai nullptr itulah yang menghentikan loop traversal.

The hardest part: Bug pada displayList(): program tidak pernah berhenti. Awalnya saya tidak tahu penyebabnya, karena program terlihat benar. Setelah ditelusuri putaran demi putaran, ternyata current = current->next berada di dalam if, sehingga di node terakhir current tidak pernah berpindah ke nullptr. Bagian lain yang sulit adalah merge conflict di README.md, karena baru pertama kali menyelesaikannya.

What AI helped me with: Claude membantu menjelaskan isi soal dalam bahasa Indonesia, menjelaskan logika node dan pointer, menemukan penyebab bug infinite loop di displayList(), serta menjelaskan alur Git (branch, Pull Request, merge conflict). Detailnya ada di AI-NOTES.md.

What I changed or fixed myself: Saya memperbaiki displayList() dengan memindahkan current = current->next keluar dari if dan memindahkan cout << endl ke luar while. Saya juga memperbaiki struktur folder yang awalnya tertumpuk (src/experiments/screenshots) menjadi sejajar, dan menyelesaikan conflict README.md sendiri.

GitHub Issue / PR / Commit I contributed:

Issue: #1 (Task 1-2: Create Node struct and 5 node list)
PR: #2 (Task 1-2: Create Node and build list)
Commit:
add node struct and make createNode function
add displaylist procedure and main
fixing bug and add main.exe
Resolve README merge conflict