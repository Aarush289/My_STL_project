#ifndef QUEUE_H
#define QUEUE_H

#include "deque.h"

template < typename T >
class queue {
    private :
        Deque<T> c;
    public :
        queue();
        explicit queue(const Deque<T>& other);
        explicit queue(Deque<T>&& other);
        queue(const queue& other);
        queue(queue&& other) noexcept;  
        queue& operator=(const queue& other);
        queue& operator=(queue&& other) noexcept;
        bool operator==(const queue& other) const;
        bool operator!=(const queue& other) const;
        bool operator<(const queue& other) const; // lexographically less than
        bool operator>(const queue& other) const; // lexographically greater than
        void push(const T& value);
        void push(T&& value);
        T& front();
        const T& front() const;
        T& back();
        const T& back() const;
        void pop();
        void shrink_to_fit();
        void clear();
        bool empty() const;
        bool empty();
        size_t size() const;
        size_t size();
        void swap(queue& other);
};

#include "queue.tpp"
#endif