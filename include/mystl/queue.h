#ifndef QUEUE_H
#define QUEUE_H

#include "deque.h"   // underlying container: Deque<T>

/**
 * @class queue
 * @brief FIFO queue adaptor over Deque<T>
 * 
 * Provides standard queue interface (push/back, pop/front).
 */
template <typename T>
class queue {
private:
    Deque<T> c;  // underlying container

public:
    // ctors / dtors / assignment
    queue();
    explicit queue(const Deque<T>& other);   // copy underlying container
    explicit queue(Deque<T>&& other);        // take ownership of container
    queue(const queue& other);               // copy queue
    queue(queue&& other) noexcept;           // move queue
    queue& operator=(const queue& other);    // copy-assign
    queue& operator=(queue&& other) noexcept;// move-assign

    // comparisons (lexicographic by underlying container)
    bool operator==(const queue& other) const;
    bool operator!=(const queue& other) const;
    bool operator<(const queue& other) const; // lexicographically less
    bool operator>(const queue& other) const; // lexicographically greater

    // modifiers
    void push(const T& value);   // enqueue (copy)
    void push(T&& value);        // enqueue (move)
    void pop();                  // dequeue front
    void shrink_to_fit();        // reduce capacity to size
    void clear();                // remove all elements
    void swap(queue& other);     // O(1) swap containers

    // element access
    T& front();             // reference to front element
    const T& front() const;
    T& back();              // reference to back element
    const T& back() const;

    // capacity
    bool empty() const;     // true if size()==0
    bool empty();           // non-const overload (kept for API parity)
    size_t size() const;    // number of elements
    size_t size();          // non-const overload (kept for API parity)
};

#include "./Details/queue.tpp"
#endif
