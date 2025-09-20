#pragma once
#include "../deque.h"

/*==========================
    Ctor/Dtor/Assignment
===========================*/
template <typename T>
Deque<T>::Deque() : data(nullptr), capacity(0), frontIndex(0), length(0) {}

template <typename T>
Deque<T>::Deque(size_t initial_capacity) 
    : data(new T[initial_capacity]), capacity(initial_capacity), frontIndex(0),length(0) {}

template <typename T>
Deque<T>::Deque(size_t initial_capacity ,const T& value){
    data = new T[initial_capacity];
    capacity = initial_capacity;
    frontIndex = 0;
    length = capacity;
    for(size_t i=0;i<capacity;i++){
        data[i] = value; // Initialize all elements with the provided value
    } 
}

template <typename T>
Deque<T>::Deque(const Deque& other) {
    capacity = other.capacity;
    frontIndex = 0;              // <--- normalize front
    length = other.length;
    data = new T[capacity];
    for (size_t i = 0; i < length; ++i) {
        data[i] = other.data[(other.frontIndex + i) % other.capacity];
    }
}

template <typename T>
Deque<T>::Deque(Deque&& other) noexcept{
    data = other.data;
    capacity = other.capacity;
    frontIndex = other.frontIndex;
    length = other.length;

    other.data = nullptr;
    other.capacity = 0;
    other.frontIndex = 0;
    other.length = 0;
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque& other) {
    if (this != &other) {
        delete[] data; // Free existing memory
        capacity = other.capacity;
        frontIndex = 0; // Normalize front
        length = other.length;
        data = new T[capacity];
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[(other.frontIndex + i) % other.capacity];
        }
    }
    return *this;
}

template <typename T>
Deque<T>& Deque<T>::operator=(Deque&& other) noexcept {
    if (this != &other) {
        delete[] data; // Free existing memory
        data = other.data;
        capacity = other.capacity;
        frontIndex = other.frontIndex;
        length = other.length;

        other.data = nullptr;
        other.capacity = 0;
        other.frontIndex = 0;
        other.length = 0;
    }
    return *this;
}

/*===============================
    Comparison operators
================================*/

template <typename T>
bool Deque<T>::operator==(const Deque& other) const {
    if(length!= other.length){return false;}
    for(size_t i=0;i<length;i++){
        if(data[(frontIndex + i) % capacity] != other.data[(other.frontIndex + i) % other.capacity]){
            return false;
        }
    }
    return true;
}

template <typename T>
bool Deque<T>::operator!=(const Deque& other) const {
    return !(*this == other);
}

template <typename T>
bool Deque<T>::operator<(const Deque& other) const {
    if(*this == other){return false;}
    for(size_t i=0;i<length;i++){
        if(data[(frontIndex + i) % capacity] < other.data[(other.frontIndex + i) % other.capacity]){
            return true;
        }
        if( data[(frontIndex + i) % capacity] > other.data[(other.frontIndex + i) % other.capacity]){
            return false;
        }
    }
    return length < other.length;
}

template <typename T>
bool Deque<T>::operator>(const Deque& other) const {
    return !(*this == other || *this < other);
}

/*=================================
    Capacity increase 
===================================*/
template <typename T>
void Deque<T>::reserve(size_t new_capacity){
    if (new_capacity <= capacity) {
        return; // No need to reserve less than or equal to current capacity
    }
    T* new_data = new T[new_capacity];
    for(size_t i = 0 ; i <length ;i++){
        new_data[i] = data[(frontIndex + i) % capacity];
    }
    delete[] data; // Free old memory
    data = new_data;
    capacity = new_capacity;
    frontIndex = 0; // Reset front index to 0 after reallocation
    length = length; // Maintain the same length

}

template <typename T>
void Deque<T>::push_front(const T& value){
    if(length == capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2); // Double the capacity if full
    }
    frontIndex = (frontIndex-1+capacity)%capacity ;
    data[frontIndex] = value;
    length++;
}


template <typename T>
void Deque<T>::push_back(const T& value) {
    if(length == capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2); // Double the capacity if full
    }
    data[(frontIndex + length) % capacity] = value;
    length++;
}

template <typename T>
void Deque<T>::pop_front() {
    if (length == 0) {
        throw std::out_of_range("Deque is empty");
    }
    frontIndex = (frontIndex + 1) % capacity; // Move front index forward
    length--;
}

template <typename T>
void Deque<T>::pop_back() {
    if (length == 0) {
        throw std::out_of_range("Deque is empty");
    }
    length--;
}

template <typename T>
T& Deque<T>::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[(frontIndex + index) % capacity];
}

template <typename T>
const T& Deque<T>::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[(frontIndex + index) % capacity];
}

template <typename T>
T& Deque<T>::front() {
    if (length == 0) {
        throw std::out_of_range("Deque is empty");
    }
    return data[frontIndex];
}

template <typename T>
T& Deque<T>::back() {
    if (length == 0) {
        throw std::out_of_range("Deque is empty");
    }
    return data[(frontIndex + length - 1) % capacity];
}

template <typename T>
bool Deque<T>::empty() const {
    return length == 0;
}

template <typename T>
size_t Deque<T>::size() const {
    return length;
}

template <typename T>
void Deque<T>::print() const {
    if (length == 0) {
        std::cout << "Deque is empty" << std::endl;
        return;
    }
    std::cout << "Deque elements: ";
    for (size_t i = 0; i < length; ++i) {
        std::cout << data[(frontIndex + i) % capacity] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Deque<T>::clear() {
    delete[] data; // Free existing memory
    data = nullptr;
    capacity = 0;
    frontIndex = 0;
    length = 0;
}

template <typename T>
void Deque<T>::swap(Deque& other) {
    std::swap(data, other.data);
    std::swap(capacity, other.capacity);
    std::swap(frontIndex, other.frontIndex);
    std::swap(length, other.length); 
}

template <typename T>
void Deque<T>::shrink_to_fit() {
    if (length == capacity) return; // nothing to shrink

    T* newData = new T[length]; // allocate exact size

    // Copy elements in logical order
    for (size_t i = 0; i < length; ++i) {
        newData[i] = data[(frontIndex + i) % capacity];
    }

    delete[] data;
    data = newData;
    capacity = length;
    frontIndex = 0;  // reset to start
}


template <typename T>
Deque<T>::~Deque() {
    clear(); // Free allocated memory
}

