#pragma once
#include "stack.h"

// ----------------- Constructors -----------------
template <typename T>
stack<T>::stack() : c() {}

template <typename T>
stack<T>::stack(const vector<T>& other) : c(other) {}

template <typename T>
stack<T>::stack(vector<T>&& other) : c(std::move(other)) {}

template <typename T>
stack<T>::stack(const stack& other) : c(other.c) {}

template <typename T>
stack<T>::stack(stack&& other) noexcept {
    if (this != &other) {
        c = std::move(other.c);   // <-- move assignment of vector
    }
    //return *this;
}

// ----------------- Assignment Operators -----------------
template <typename T>
stack<T>& stack<T>::operator=(const stack& other) {
    if (this != &other) {
        c = other.c;
    }
    return *this;
}

template <typename T>
stack<T>& stack<T>::operator=(stack&& other) noexcept {
    if (this != &other) {
        c = std::move(other.c);
    }
    return *this;
}

// ----------------- Comparison Operators -----------------
template <typename T>
bool stack<T>::operator==(const stack& other) const {
    return c == other.c;
}

template <typename T>
bool stack<T>::operator!=(const stack& other) const {
    return c != other.c;
}

template <typename T>
bool stack<T>::operator<(const stack& other) const {
    return c < other.c;
}

template <typename T>
bool stack<T>::operator>(const stack& other) const {
    return c > other.c;
}

// ----------------- Modifiers -----------------
template <typename T>
void stack<T>::push(const T& val) {
    c.push_back(val);
}

template <typename T>
void stack<T>::pop() {
    if(!c.empty()) {
        c.pop_back();
    }
    //c.pop_back();
}

template <typename T>
void stack<T>::swap(stack& other) {
    c.swap(other.c);
}

template <typename T>
void stack<T>::shrink_to_fit() {
    c.shrink_to_fit();
}

// ----------------- Element Access -----------------
template <typename T>
T& stack<T>::top() {
    return c[c.size() - 1];
}

template <typename T>
void stack<T>::clear() {
    c.clear();   // simply clear the underlying vector
}


template <typename T>
const T& stack<T>::top() const {
    return c[c.size() - 1];
}

// ----------------- Capacity -----------------
template <typename T>
bool stack<T>::empty() const {
    return c.size() == 0;
}

template <typename T>
size_t stack<T>::size() const {
    return c.size();
}
