#ifndef STACK_H
#define STACK_H
#include "vector.h"

template < typename T >
class stack{
private:
   vector<T> c;
public:
    stack();
    explicit stack(const vector<T>& other);
    explicit stack(vector<T>&& other);
    stack(const stack& other);
    stack(stack&& other) noexcept;
    stack& operator=(const stack& other);
    stack& operator=(stack&& other)noexcept;
    bool operator==(const stack& other) const ;
    bool operator!=(const stack& other) const ;
    bool operator<(const stack& other) const; // lexographically less than
    bool operator>(const stack& other) const; // lexographically greater than
    void push(const T&);
    T& top();
    void pop();
    void shrink_to_fit() ;
    const T& top() const;
    void clear() ;
    bool empty() const;
    size_t size() const;
    void swap(stack& other);

};

#include "stack.tpp"
#endif