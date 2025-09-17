#pragma once
#include "queue.h"

template <typename T>
queue<T>::queue() : c() {}

template <typename T>
queue<T>::queue(const Deque<T>& other) : c(other) {}

template <typename T>
queue<T>::queue(Deque<T>&& other) : c(std::move(other)) {}

template <typename T>
queue<T>::queue(const queue<T>& other) : c(other.c) {}

template <typename T>
queue<T>::queue(queue<T>&& other) noexcept : c(std::move(other.c)) {}

template <typename T>
queue<T>& queue<T>::operator=(const queue<T>& other) {
    if (this != &other) {
        c = other.c;
    }
    return *this;
}

template <typename T>
queue<T>& queue<T>::operator=(queue<T>&& other) noexcept {
    if (this != &other) {
        c = std::move(other.c);
    }
    return *this;
}

template <typename T>
bool queue<T>::operator==(const queue<T>& other) const {
    return c == other.c;
}

template <typename T>
bool queue<T>::operator!=(const queue<T>& other) const {
    return !(*this == other);
}

template <typename T>
bool queue<T>::operator<(const queue<T>& other) const {
    return c < other.c;
}

template <typename T>
bool queue<T>::operator>(const queue<T>& other) const {
    return c > other.c;
}

template <typename T>
void queue<T>::push(const T& value) {
    c.push_back(value);
}

template <typename T>
void queue<T>::push(T&& value) {
    c.push_back(std::move(value));
}

template <typename T>
T& queue<T>::front() {
    return c.front();
}

template <typename T>
const T& queue<T>::front() const {
    return c.front();
}

template <typename T>
T& queue<T>::back() {
    return c.back();
}

template <typename T>
const T& queue<T>::back() const {
    return c.back();
}

template <typename T>
void queue<T>::pop() { 
    c.pop_front();
}

template <typename T>
void queue<T>::shrink_to_fit() {
    c.shrink_to_fit();
}

template <typename T>
void queue<T>::clear() {
    c.clear();
}

template <typename T>
bool queue<T>::empty() const {
    return c.empty();
}

template <typename T>
bool queue<T>::empty() {
    return c.empty();
}


template <typename T>
size_t queue<T>::size() const {
    return c.size();
} 


template <typename T>
size_t queue<T>::size(){
    return c.size();
} 

template <typename T>
void queue<T>::swap(queue<T>& other) {
    c.swap(other.c);
}



