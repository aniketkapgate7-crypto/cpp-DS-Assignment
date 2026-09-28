# C++ Data Structures & Algorithms - Lab Assignments

This repository contains basic C++ implementations for Data Structures and Algorithms laboratory assignments.

---

## Assignment 1: Smart Library Book Management System

Covers core array and search/sort operations for managing library book records:

- **`basic_io.cpp`**: Basic console input and display of multiple book records.
- **`search_book_id.cpp`**: Linear search algorithm to find books by Book ID.
- **`sort_books.cpp`**: Bubble sort algorithm to organize Book IDs in ascending order.
- **`menu_driven_library.cpp`**: Interactive menu-driven program supporting add, display, search, and exit operations.

---

## Assignment 2: Student Performance & Ranking Management System

Covers class structures, record management, and merit ranking using arrays:

- **`student_class.cpp`**: Class-based modeling for student records with `input()` and `display()` methods.
- **`search_rollno.cpp`**: Linear search implementation to locate student records by Roll Number.
- **`merit_sort.cpp`**: Descending bubble sort algorithm on student marks to generate merit lists.

---

## Assignment 3: Smart Restaurant Order Management System

Covers linear data structures (Queue, Stack) and recursion concepts:

- **`restaurant_queue.cpp`**: Implements a First-In-First-Out (FIFO) Queue to accept and process 5 customer orders.
- **`canceled_order.cpp`**: Implements a Last-In-First-Out (LIFO) Stack to store canceled orders and review recent cancellations first.
- **`menu_recursion.cpp`**: Interactive restaurant food menu loop implemented purely using recursion without while loops.

---

## Compilation

Compile any program using standard `g++`:

```bash
g++ Assignment_1_Smart_Library/menu_driven_library.cpp -o library
./library
```