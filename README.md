# **Custom C++ STL Implementation**

## **Overview**

This project is a **Custom C++ Standard Template Library (STL)** implementation that includes common data structures such as `Vector`, `String`, `Map`, `Set`, `Stack`, `Queue`, `Priority Queue`, and `Deque`. This library is implemented from scratch to provide a deeper understanding of these core data structures and to improve efficiency in certain use cases. Optimizations like the **circular array** for `Vector` and the **Knuth-Morris-Pratt (KMP)** algorithm for string matching have been applied to enhance the performance of common operations.

## **Features**

- **Vector**: Implements dynamic arrays using a **circular array** to make operations like `push_front` and `pop_front` more efficient.
- **String**: Custom string class with essential string manipulation methods.
- **Map**: A key-value store with efficient lookup, insertion, and deletion operations.
- **Set**: An unordered collection of unique elements, optimized for fast operations.
- **Stack**: Supports the Last In, First Out (**LIFO**) principle.
- **Queue**: Supports the First In, First Out (**FIFO**) principle.
- **Priority Queue**: A heap-based priority queue that processes elements based on priority.
- **Deque**: A double-ended queue supporting efficient operations at both ends.

## **Key Optimizations**

1. **Circular Array for Vector**:  
   To improve efficiency, the `Vector` implementation uses a **circular array**. This allows for efficient `push` and `pop` operations at the front, reducing the time complexity from \(O(n)\) to \(O(1)\).

2. **Knuth-Morris-Pratt (KMP) Algorithm for Substring Search**:  
   The **KMP algorithm** is used for substring searching within the `String` class. Unlike the naive approach, KMP runs in \(O(n + m)\) time complexity, where `n` is the length of the text and `m` is the length of the pattern, making it significantly faster.

## **Data Structures Implemented**

### **1. Vector**
   - A dynamic array that allows for efficient resizing and element access.
   - The circular array optimization ensures that operations at the front of the vector are as fast as operations at the back.

### **2. String**
   - A custom string class with the ability to modify, search, and manipulate strings.
   - Includes the **KMP algorithm** for efficient substring search.

### **3. Map**
   - A key-value store where keys are unique. It provides efficient `insert`, `delete`, and `search` operations.

### **4. Set**
   - A collection of unique elements, where duplicates are not allowed. Supports fast insertions, deletions, and lookups.

### **5. Stack**
   - Implements the stack data structure following the **LIFO (Last In, First Out)** principle, with push and pop operations.

### **6. Queue**
   - Implements a queue with the **FIFO (First In, First Out)** principle. Allows efficient `enqueue` and `dequeue` operations.

### **7. Priority Queue**
   - A heap-based priority queue where elements are dequeued in order of their priority, allowing efficient access to the highest (or lowest) priority element.

### **8. Deque**
   - A double-ended queue that supports efficient `push` and `pop` operations from both ends of the sequence.

## **Installation and Setup**

### Prerequisites
- A C++ compiler (GCC or Clang)
- Standard C++ libraries

### How to Use

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/your-username/My-STL-Project.git
   cd My-STL-Project
