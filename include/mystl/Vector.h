#ifndef VECTOR_H
#define VECTOR_H
#include "C.h"

#include <assert.h>
#include <cstring>
#include <iostream>
#include <cstddef>
#include <algorithm>

/**
*@file Vector.hpp
*@brief : Header file for minimal std::vector like container with bidirectional iterator support
*
*@tparam T element type stored by the container 
*
*@note Semantics are similar(not identical) to std::vector . Capacity/size management,
*       Iterator invalidation rules , exception guarantees depend on the corresponding 
*       implementation in Vector.tpp file .
*/

/**
*@class vector
*@brief: Contiguous dynamic array providing random access 
*
*The container manages raw heap heap buffer , grows on demand and
*exposes basic modifiers and accessors .
*Iterators are simple wrapper around raw pointers.
*/

template <typename T>
class vector
{   
public:
    /**
     * @class Iterator
     * @brief Bidirectional iterator over @ref vector
     * 
     * wraps the raw pointer into the underlying data . suppports *,->,++,--
     * equality and inequality comparisons .
     * 
     * @warning All usual iterator invalidation rules apply: Any operation 
     * that re-allocates the underlying buffer (e.g. resize ,erase etc. )
     * invalidate the outstanding iterators.
     * 
     */
    class Iterator{                                                     
    private:
        T* Data ;              ///< Current element pointer         
        vector<T>* parent;     ///< Owning Container
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = value_type*;
        using reference         = value_type&;    

        /// @name Constructor / core operations
        /// @{ 
        Iterator(T* Data = NULL ,vector<T>* parent = NULL);  ///< Constructor 
        reference operator*()const;                          
        pointer operator->()const;
        Iterator& operator++();                              ///< pre-increment
        Iterator operator++(int);                            ///< post-increment
        Iterator& operator--();                              ///< pre-decrement
        Iterator operator--(int);                            ///< post-decrement
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        ///@}
    };
    /**
     * @class Const_Iterator
     * @brief Const bidirection iterator over @ref vector
     * Provides read only access to the elements and same invalidation rules as @ref Iterator .
     */
    class Const_Iterator{
    private:
        const T* Data ;                   ///< current element pointer (const)
        const vector<T>* parent;          ///< Owning Container (const)
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = const value_type*;
        using reference         = const value_type&;    
        /// @name Constructoe / core operations
        /// @{
        Const_Iterator(const T* Data = NULL , const vector<T>* parent = NULL);
        reference operator*()const;       
        pointer operator->()const;
        Const_Iterator& operator++();       ///< pre-increment
        Const_Iterator operator++(int);     ///< post-increment
        Const_Iterator& operator--();       ///< pre-decrement
        Const_Iterator operator--(int);     ///< post-decrement
        bool operator==(const Const_Iterator& other) const;
        bool operator!=(const Const_Iterator& other) const;
        ///@}
    };
    
protected:
    T* Data;            ///< Pointer to the contiguous storage (size: @ref capacity)
    size_t capacity;    ///< Allocated elements slots
    size_t length;      ///< Number of constructed elements 

public:
    /// @name Contructor /Destructor /Assignment
    ///@{
    vector();                                           ///< Default : empty container
    vector(size_t n);                                   ///< size ctor : value initializes n elemnts
    vector(size_t n , size_t a);                        ///< size+value ctor : initializes n elements with value a
    vector(const vector<T>& other);                     ///< Copy constructor
    vector(vector<T>&& other) noexcept;                 ///< Move constructor
    vector(std::initializer_list<T> init);              ///< Assignment constructor
    vector<T>& operator=(vector<T>&& other) noexcept;   ///< move operator  
    vector<T>& operator=(const vector<T>& other);       ///< copy operator
    ~vector();                                          ///< Destructor ( destroys elements and frees storage )
    ///@}

    /// @name Element access
    ///@{
    T& operator[](size_t index);                    ///< Unchecked Access
    const T& operator[](size_t index) const;        ///< Unchecked constant access
    const T& at(size_t index) const;                ///< Bounds checked constant access
    const T& front() const;                         ///< Const reference to first element (precondition : size>0) 
    T& back() ;                                     ///< Reference to last element (pre-cond: size>0)
    T& front();                                     ///< Reference to first element (pre-cond: size>0)
    const T& back() const;                          ///< Const reference to last element (pref-cond : size>0)
    T* data();                                      ///< Pointer to underlying array
    const T* data() const;                          ///< Pointer to underlying array (const)
    /// @}

    /// @name Relational operators (lexographical)
    /// @{  
    bool operator==(const vector<T>& other);        ///< equality ( non-const overload)
    bool operator==(const vector<T>& other)const;   ///< equality (const overload)
    bool operator!=(const vector<T>& other) ;       ///< Inequality ( non-const overload)
    bool operator!=(const vector<T>& other) const;  ///< Inequality ( const overload)
    bool operator<(const vector<T>& other);         ///< lexographically less (non -const overload) 
    bool operator>(const vector<T>& other);         
    bool operator<(const vector<T>& other) const; 
    bool operator>(const vector<T>& other) const; 
    /// @}

    /// @name Capacity/Size
    /// @{
    void resize(size_t newsize);                    ///< Construct/destruct elements based on new-size
    void reserve(size_t new_capacity);              ///< Increase the capacity to max(current capacity , new_capacity)
    size_t size();                                  ///< Number of elements (non-const overload)
    void shrink_to_fit();                           ///< Reduce the capacity to fit size 
    size_t get_capacity() const;                    ///< Number of elements which can be stored 
    size_t size() const;                            ///< NUmber of elements ( const-overload)
    bool empty()const;                              ///< true if size=0
    /// @}

    /// @name Modifiers
    /// @{ 
    void push_back(const T& value);                 ///< append copy of element
    void push_back(T&& value);                      ///< append moved value
    void pop_back();                                ///< remove last element (pre-cond: size>0)
    void clear();                                   ///< destroys all elements ( size->0 , capacity remains same)
    void insert(size_t index, const T& value);      ///< Insert element at desired index
    void erase(size_t index);                       ///< Delete element at desired index
    void swap(vector<T>& other);                    ///< Swap  contents with other
    vector<T> slice(size_t x, size_t y) const;      ///< returns the sub-range [x,y] as new vector
    ///@}
   
    /// @name Pointer
    /// @{
    T* begin();                                     ///< Pointer to First element 
    T* end();                                       ///< Pointer to one-past the last element
    const T* begin() const;                         ///< Pointer to First element (const-overload)
    const T* end() const;                           ///< Pointer to last element(const-overload)
    T* left_rotate(size_t k);                       ///< left-rotate the array by k units then returns pointer to first element
    T*  right_rotate(size_t k);                     ///< right-rotate the array by k units then returns pointer to first element
    /// @}
    void print() const;                             ///< Prints the elements of the vector with spaces between them 

    

};

#include "./Details/Vector.tpp"

#endif
