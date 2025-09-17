# **Custom C++ STL Implementation**

## **Overview**
This project is a **Custom C++ Standard Template Library (STL)** implementation that includes `Vector`, `String`, `Map`, `Set`, `Stack`, `Queue`, `Priority Queue`, and `Deque`. It’s built from scratch to deepen understanding and improve efficiency in common operations. Notable optimizations include a **circular array** for `Vector` (fast front push/pop) and **KMP** for substring search.

## **Features**
- **Vector** — dynamic array using a **circular buffer** for efficient front/back ops
- **String** — custom string with manipulation utilities and **KMP** substring search
- **Map / Set** — unique keys/elements with efficient insert/find/erase
- **Stack / Queue / Deque** — classic LIFO/FIFO and double-ended structures
- **Priority Queue** — heap-based ordering by priority

## **Key Optimizations**
- **KMP Substring Search**: O(n + m) pattern matching (faster than naive).

## **Installation and Setup**
**Prerequisites**: C++17+ compiler (g++/clang++/MSVC)

### Compile and run the code:
```bash

# 1) Clone and enter
git clone https://github.com/your-username/My-STL-Project.git
cd My-STL-Project

# 2) Build & run a demo (adjust paths to your entry file, e.g., examples/main.cpp)
# Linux/macOS (Bash/zsh):
mkdir -p build
g++ -std=gnu++17 -O2 -Wall -Wextra -Iinclude examples/main.cpp -o build/demo && ./build/demo

# Windows (PowerShell) — if using MinGW:
# mkdir build
# g++ -std=c++17 -O2 -Wall -Wextra -Iinclude examples/main.cpp -o build/demo.exe ; ./build/demo.exe

# Windows (MSVC cl.exe, from "Developer Command Prompt for VS"):
# mkdir build
# cl /std:c++17 /O2 /I include examples\main.cpp /Fe:build\demo.exe && build\demo.exe
