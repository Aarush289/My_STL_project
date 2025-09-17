#ifndef DEQUE_H
#define DEQUE_H

#include "deque.h"

template <typename T>
class Deque {
    class iterator{
        Deque<T>* D;
        size_t index;
    public:
        iterator();
        iterator(Deque<T>* d, size_t idx) ;
        iterator(const iterator& other);
        iterator& operator=(const iterator& other);
        T& operator*() const { return (*D)[index]; }

        // Increment / Decrement
        iterator& operator++() { ++index; return *this; }
        iterator operator++(int) { auto tmp = *this; ++index; return tmp; }
        iterator& operator--() { --index; return *this; }
        iterator operator--(int) { auto tmp = *this; --index; return tmp; }

        // Random access
        iterator operator+(int n) const { return iterator(D, index + n); }
        iterator operator-(int n) const { return iterator(D, index - n); }
        int operator-(const iterator& other) const { return (int)index - (int)other.index; }
        T& operator[](int n) const { return (*D)[index + n]; }

        // Comparisons
        bool operator==(const iterator& other) const { return D == other.dq && index == other.index; }
        bool operator!=(const iterator& other) const { return !(*this == other); }
        bool operator<(const iterator& other) const { return index < other.index; }
        bool operator>(const iterator& other) const { return index > other.index; }
        bool operator<=(const iterator& other) const { return index <= other.index; }
        bool operator>=(const iterator& other) const { return index >= other.index; }
    };
    private:
        T* data;
        size_t capacity;
        size_t frontIndex;
        size_t length;
    public:
        Deque();
        Deque(size_t initial_capacity );
        Deque(size_t initial_capacity  , const T& value);
        Deque(const Deque& other);
        Deque(Deque&& other) noexcept;
        Deque& operator=(const Deque& other);
        Deque& operator=(Deque&& other) noexcept;
        bool operator==(const Deque& other) const;
        bool operator!=(const Deque& other) const;
        bool operator<(const Deque& other) const; // lexographically less than
        bool operator>(const Deque& other) const;
        void reserve(size_t new_capacity);
        void push_front(const T& value);
        void push_back(const T& value);
        void pop_front();
        void pop_back();
        T& operator[](size_t index);
        const T& operator[](size_t index) const;  
        T& front();
        T& back();
        bool empty() const;
        size_t size() const;
        void clear();
        void swap(Deque& other);
        void shrink_to_fit();      
        void print() const;
         ~Deque();
        
};

#include "priority_queue.tpp"
#endif