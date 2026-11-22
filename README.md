# C++ Data Structures

Classic data structures I implemented from scratch in C++ while studying them, with raw pointers and manual memory management instead of standard containers.

| Structure | File | Operations |
|---|---|---|
| Singly linked list (template) | `Practice/SLL.cpp` | `Add`, `Contains`, `Remove`, `Print` |
| Doubly linked list | `Practice/DLL.cpp` | `Add`, `Remove`, `Print` |
| Binary search tree (template) | `Practice/BST.cpp` | `insert`, `contains`, `remove`, `preorder` |
| Max-heap | `Practice/Heap.cpp` | `insert`, `pop` |
| Hash table, open addressing | `Practice/Hash.cpp` | `Add`, `Search`, `Resize` (quadratic probing) |

# Comment on Hashmap 

Since Hashtable has a lot of options, I picked open addressing with quadratic probing, and a `Resize` that doubles the table and re-inserts the entries when it is 75% full.
