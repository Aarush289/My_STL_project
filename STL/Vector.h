#ifndef VECTOR_H
#define VECTOR_H
#include "C.h"

#include <assert.h>
#include <cstring>
#include <iostream>
#include <cstddef>
#include <algorithm>

template <typename T>
class vector
{   
public:
    class Iterator{
    private:
        T* Data ;
        vector<T>* parent;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = value_type*;
        using reference         = value_type&;    

        Iterator(T* Data = NULL ,vector<T>* parent = NULL);
        reference operator*()const;
        pointer operator->()const;
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };
    class Const_Iterator{
    private:
        const T* Data ;
        const vector<T>* parent;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = const value_type*;
        using reference         = const value_type&;    

        Const_Iterator(const T* Data = NULL , const vector<T>* parent = NULL);
        reference operator*()const;
        pointer operator->()const;
        Const_Iterator& operator++();
        Const_Iterator operator++(int);
        Const_Iterator& operator--();
        Const_Iterator operator--(int);
        bool operator==(const Const_Iterator& other) const;
        bool operator!=(const Const_Iterator& other) const;
    };
    
protected:
    T* Data;
    size_t capacity;
    size_t length;

public:
    vector();
    vector(size_t n);
    vector(size_t n , size_t a);
    vector(const vector<T>& other);
    vector(vector<T>&& other) noexcept;
    vector(std::initializer_list<T> init);
    ~vector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    vector<T>& operator=(vector<T>&& other) noexcept;
    vector<T>& operator=(const vector<T>& other);
    bool operator==(const vector<T>& other);
    bool operator==(const vector<T>& other)const;
    bool operator!=(const vector<T>& other) ;
    bool operator!=(const vector<T>& other) const;
    bool operator<(const vector<T>& other);
    bool operator>(const vector<T>& other);
    bool operator<(const vector<T>& other) const; // lexographically less than
    bool operator>(const vector<T>& other) const; // lexographically greater than
    const T& at(size_t index) const;
    const T& front() const;
    T& back() ;
    T& front();
    const T& back() const;
    T* data();
    const T* data() const;

    void resize(size_t newsize);
    void reserve(size_t new_capacity);
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void clear();
    void insert(size_t index, const T& value);
    void erase(size_t index);
    size_t size();
    void shrink_to_fit();
    size_t get_capacity() const;
    size_t size() const;

    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
    T* left_rotate(size_t k);
    T*  right_rotate(size_t k);
    void print() const;
    bool empty()const;
    void swap(vector<T>& other);
    vector<T> slice(size_t x, size_t y) const;

};

#include "Vector.tpp"

#endif
