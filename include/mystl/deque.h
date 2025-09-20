#ifndef DEQUE_H
#define DEQUE_H

/**
 * @class Deque.h
 * @brief Simple double-ended queue with random access and an internal iterator.
 * 
 * API highlights:
 * - push_front / push_back, pop_front / pop_back
 * - front(), back(), operator[](i)
 * - size(), empty(), clear(), reserve(), shrink_to_fit(), swap()
 * - copy/move semantics and lexicographic comparisons
 */
template <typename T>
class Deque {
    // Lightweight random-access iterator over Deque<T>
    class iterator {
        Deque<T>* D;     // owning deque (non-const; iterator is mutable)
        size_t index;    // logical index into deque
    public:
        iterator();
        iterator(Deque<T>* d, size_t idx);
        iterator(const iterator& other);
        iterator& operator=(const iterator& other);

        // Dereference
        T& operator*() const { return (*D)[index]; }

        // Increment / Decrement (prefix/postfix)
        iterator& operator++() { ++index; return *this; }
        iterator operator++(int) { auto tmp = *this; ++index; return tmp; }
        iterator& operator--() { --index; return *this; }
        iterator operator--(int) { auto tmp = *this; --index; return tmp; }

        // Random access navigation
        iterator operator+(int n) const { return iterator(D, index + n); }
        iterator operator-(int n) const { return iterator(D, index - n); }
        int operator-(const iterator& other) const { return (int)index - (int)other.index; }
        T& operator[](int n) const { return (*D)[index + n]; }

        // Comparisons (same container, index-based)
        bool operator==(const iterator& other) const { return D == other.D && index == other.index; }
        bool operator!=(const iterator& other) const { return !(*this == other); }
        bool operator<(const iterator& other) const { return index < other.index; }
        bool operator>(const iterator& other) const { return index > other.index; }
        bool operator<=(const iterator& other) const { return index <= other.index; }
        bool operator>=(const iterator& other) const { return index >= other.index; }
    };

private:
    // Storage and layout
    T* data;             // contiguous buffer (capacity elements)
    size_t capacity;     // allocated slots
    size_t frontIndex;   // index of logical front within buffer
    size_t length;       // number of elements stored

public:
    // Constructors / assignment / destructor
    Deque();
    Deque(size_t initial_capacity);
    Deque(size_t initial_capacity, const T& value); // fill-construct
    Deque(const Deque& other);                       // deep copy
    Deque(Deque&& other) noexcept;                   // move
    Deque& operator=(const Deque& other);            // copy-assign (strong/ basic guarantee per impl)
    Deque& operator=(Deque&& other) noexcept;        // move-assign
    ~Deque();

    // Relational operators (lexicographic compare by contents)
    bool operator==(const Deque& other) const;
    bool operator!=(const Deque& other) const;
    bool operator<(const Deque& other) const;  // lexicographically less
    bool operator>(const Deque& other) const;

    // Capacity management
    void reserve(size_t new_capacity);  // grow to at least new_capacity
    void shrink_to_fit();               // reduce capacity to size (best effort)

    // Modifiers
    void push_front(const T& value);    // amortized O(1)
    void push_back(const T& value);     // amortized O(1)
    void pop_front();                   // O(1)
    void pop_back();                    // O(1)
    void clear();                       // O(n), destroys elements
    void swap(Deque& other);            // O(1) swap internals

    // Element access
    T& operator[](size_t index);              // O(1) unchecked access
    const T& operator[](size_t index) const;  // O(1) unchecked const access
    T& front();                                // reference to first element
    T& back();                                 // reference to last element
    // (Consider adding const overloads if needed)

    // Observers
    bool empty() const;                 // size() == 0
    size_t size() const;                // number of elements

    // Debug
    void print() const;                 // print contents (format per impl)
};

#include "./Details/deque.tpp"
#endif
