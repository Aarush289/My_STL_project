#ifndef STACK_H
#define STACK_H
#include "Vector.h"

/**
 * @file stack.h
 * @brief std::stack like class backed by vector
 * 
 * This class implements stack which is FILO (First in last out) container
 * using vector
 */
/**
 * @class stack
 * @brief Minimal stack adapter over vector (LIFO)
 */
template <typename T>
class stack {
private:
    vector<T> c;                 // underlying container

public:
    stack();                     // default-construct empty stack
    explicit stack(const vector<T>& other);   // copy-construct from vector
    explicit stack(vector<T>&& other);        // move-construct from vector
    stack(const stack& other);                 // copy-construct
    stack(stack&& other) noexcept;            // move-construct
    stack& operator=(const stack& other);     // copy-assign
    stack& operator=(stack&& other) noexcept; // move-assign

    bool operator==(const stack& other) const; // compare underlying containers
    bool operator!=(const stack& other) const;
    bool operator<(const stack& other) const;  // lexicographic by c
    bool operator>(const stack& other) const;

    void push(const T&);         // push element on top
    T& top();                    // access top (mutable)
    const T& top() const;        // access top (const)
    void pop();                  // remove top (precondition: not empty)

    void shrink_to_fit();        // reduce capacity to size
    void clear();                // remove all elements
    bool empty() const;          // true if no elements
    size_t size() const;         // number of elements
    void swap(stack& other);     // swap contents with other
};

#include "./Details/stack.tpp"
#endif