#include "../Vector.h"

/*===============================
*    Iterators( Mutable )
*===============================*/
template <typename T>
vector<T>::Iterator::Iterator(T* data , vector<T>* par){
    Data = data;        
    parent = par;
}

template <typename T>
typename vector<T>::Iterator::reference
vector<T>::Iterator::operator*()const{
    return *Data;
}

template <typename T>
typename vector<T>::Iterator::pointer
vector<T>::Iterator:: operator->()const{
    return Data;
}



template <typename T>
typename vector<T>::Iterator&
vector<T>:: Iterator::operator++(){
    ++Data;              // move one step forward
    return *this;
}


template <typename T>
typename vector<T>::Iterator
vector<T>:: Iterator::operator++(int){
    Iterator temp = *this;      // Copy the iterator (to the current element) before incrementing that
    ++(*this);           
    return temp;
}


template <typename T>
typename vector<T>::Iterator&
vector<T>:: Iterator::operator--(){
    --Data;              // move one step backward
    return *this;
}


template <typename T>
typename vector<T>::Iterator
vector<T>:: Iterator::operator--(int){
    Iterator temp = *this;
    --(*this);           
    return temp;
}

template <typename T>
bool vector<T>:: Iterator::operator==(const Iterator& other)const{
    return Data == other.Data;
}


template <typename T>
bool vector<T>:: Iterator::operator!=(const Iterator& other)const{
    return !(Data == other.Data);
}


//**********************Constant Iterator***********************//

template <typename T>
vector<T>::Const_Iterator::Const_Iterator(const T* data ,const vector<T>* par){
    Data = data;
    parent = par;
}

template <typename T>
typename vector<T>::Const_Iterator::reference
vector<T>::Const_Iterator::operator*()const{
    return *Data;
}

template <typename T>
typename vector<T>::Const_Iterator::pointer 
vector<T>::Const_Iterator:: operator->()const{
    return Data;
}



template <typename T>
typename vector<T>::Const_Iterator&
vector<T>::Const_Iterator::operator++(){
    ++Data;              // move one step forward
    return *this;
}


template <typename T>
typename vector<T>::Const_Iterator
vector<T>::Const_Iterator::operator++(int){
    Const_Iterator temp = *this;
    ++(*this);           
    return temp;
}


template <typename T>
typename vector<T>::Const_Iterator&
vector<T>::Const_Iterator::operator--(){
    --Data;              // move one step forward
    return *this;
}


template <typename T>
typename vector<T>::Const_Iterator
vector<T>::Const_Iterator::operator--(int){
    Const_Iterator temp = *this;
    --(*this);           
    return temp;
}

template <typename T>
bool vector<T>::Const_Iterator::operator==(const Const_Iterator& other)const{
    return Data == other.Data;
}


template <typename T>
bool vector<T>::Const_Iterator::operator!=(const Const_Iterator& other)const{
    return !(Data == other.Data);
}

/*================================
 *          Vector(core)
 *===============================*/


template <typename T>
vector<T>::vector() : Data(nullptr), capacity(0), length(0){}

template <typename T>
vector<T>::vector(size_t n) : Data(new T[n]), capacity(n), length(n) {}

template <typename T>
vector<T> :: vector(size_t n , size_t a){
    length = n;
    capacity=n;
    Data = new T[capacity];
    for (size_t i = 0; i < length; i++)
    {
        Data[i] = a;
    }
}
template <typename T>
vector<T>::vector(const vector<T>& other)
{
    length = other.length;
    capacity = other.capacity;
    // if(Data != nullptr){delete[] Data;}
    Data = new T[capacity];
    for (size_t i = 0; i < length; i++)
    {
        Data[i] = other.Data[i];
    }
}

template <typename T>
vector<T>::vector(vector<T>&& other)noexcept        //steal the resources
{
    capacity = other.capacity;
    length = other.length;
    Data = (other.Data);
    other.length = 0;                               // leave the other in valid , empty state
    other.capacity =0;
    other.Data = nullptr;
}

template <typename T>
vector<T>::~vector()                
{
    if(Data == NULL){return;}
    delete[] Data;                                      //frees storage
    length = 0;
    capacity = 0;
}

/*=================
*   Assignment
===================*/
template <typename T>
vector<T>& vector<T>::operator=(vector<T>&& other) noexcept {
    if (this != &other) {
        delete[] Data;              // free the current data
        Data = other.Data;          //steal the data of other
        length = other.length;
        capacity = other.capacity;

        other.Data = nullptr;
        other.length = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this != &other) {
        delete[] Data;
        length = other.length;
        capacity = other.capacity;
        Data = new T[capacity];
        for (size_t i = 0; i < length; i++)
        {
            Data[i] = other.Data[i];
        }
    }
    return *this;
}


/*=========================
        Element access
===========================*/
template <typename T>
T& vector<T>::operator[](size_t index)
{
    if (index >= length )
    {
        throw std::out_of_range("Index out of range");
    }
    return Data[index];
}

template <typename T>
const T& vector<T>::operator[](size_t index) const
{
    if (index >= length )
    {
        throw std::out_of_range("Index out of range");
    }
    return Data[index];
}


template <typename T>
const T& vector<T>::at(size_t index) const
{
    if (index >= length )
    {
        throw std::out_of_range("Index out of range");
    }
    return Data[index];
}



template <typename T>
const T& vector<T>::front() const
{
    if (length == 0)
    {
        throw std::underflow_error("vector is empty");
    }
    return Data[0];
}

template <typename T>
const T& vector<T>::back() const
{
    if (length == 0)
    {
        throw std::underflow_error("vector is empty");
    }
    return Data[length - 1];
}


template <typename T>
T& vector<T>::front()
{
    if (length == 0)
    {
        throw std::underflow_error("vector is empty");
    }
    return Data[0];
}

template <typename T>
T& vector<T>::back()
{
    if (length == 0)
    {
        throw std::underflow_error("vector is empty");
    }
    return Data[length - 1];
}

/*===================
 *  Size / Capacity 
===================== */
template <typename T>
size_t vector<T> :: size(){
    return length ;
}

template <typename T>
size_t vector<T>::get_capacity() const {
    return capacity;
}


template <typename T>
void vector<T>::shrink_to_fit() {
    if (length < capacity) {
        T* new_Data = new T[length];
        for (size_t i = 0; i < length; i++) {
            new_Data[i] = std::move(Data[i]);
        }
        delete[] Data;
        Data = new_Data;
        capacity = length;
    }
}

template <typename T>
size_t vector<T> :: size()const {
    return length ;
}

/*==========================
    Relational operators
============================*/
template <typename T>
bool vector<T>::operator==(const vector<T>& other) {
    if (length != other.length) return false;
    for (size_t i = 0; i < length; ++i) {
        if (!(Data[i] == other.Data[i])) return false;
    }
    return true;
}

template <typename T>
bool vector<T>::operator!=(const vector<T>& other) {
    return !(*this == other);
}

template <typename T>
bool vector<T>::operator<(const vector<T>& other) const {
    size_t min_length = std::min(length, other.length);
    for (size_t i = 0; i < min_length; ++i) {
        if (Data[i] < other.Data[i]) return true;
        if (Data[i] > other.Data[i]) return false;
    }
    return length < other.length; // If all elements are equal, compare lengths
}

template <typename T>
bool vector<T>::operator>(const vector<T>& other) const {
    size_t min_length = std::min(length, other.length);
    for (size_t i = 0; i < min_length; ++i) {
        if (Data[i] > other.Data[i]) return true;
        if (Data[i] < other.Data[i]) return false;
    }
    return length > other.length; // If all elements are equal, compare lengths
}


template <typename T>
bool vector<T>::operator==(const vector<T>& other)const {
    if (length != other.length) return false;
    for (size_t i = 0; i < length; ++i) {
        if (!(Data[i] == other.Data[i])) return false;
    }
    return true;
}

template <typename T>
bool vector<T>::operator!=(const vector<T>& other)const {
    return !(*this == other);
}

template <typename T>
bool vector<T>::operator<(const vector<T>& other) {
    size_t min_length = std::min(length, other.length);
    for (size_t i = 0; i < min_length; ++i) {
        if (Data[i] < other.Data[i]) return true;
        if (Data[i] > other.Data[i]) return false;
    }
    return length < other.length; // If all elements are equal, compare lengths
}

template <typename T>
bool vector<T>::operator>(const vector<T>& other) {
    size_t min_length = std::min(length, other.length);
    for (size_t i = 0; i < min_length; ++i) {
        if (Data[i] > other.Data[i]) return true;
        if (Data[i] < other.Data[i]) return false;
    }
    return length > other.length; // If all elements are equal, compare lengths
}



/*============================
    Pointer 
=============================*/

template <typename T>
T* vector<T>::data()
{
    return Data;
}

template <typename T>
const T* vector<T>::data() const
{
    return Data;
}

template <typename T>
T* vector<T>::begin()
{
    return Data;
}

template <typename T>
T* vector<T>::end()
{
    return Data +length ;
}

template <typename T>
const T* vector<T>::begin() const
{
    return Data;
}

template <typename T>
const T* vector<T>::end() const
{
    return Data + length ;
}



template <typename T>
T* vector<T>::left_rotate(size_t k) {
    if (length == 0) return Data;
    k = k % length;
    std::rotate(Data, Data + k, Data + length);
    return Data;
}


template <typename T>
T* vector<T>::right_rotate(size_t k) {
    if (length == 0) return Data;
    k = k % length;  // Normalize k
    std::rotate(Data, Data + length - k, Data + length);
    return Data;
}

/*===============================
        Capacity adjustments
=================================*/
template <typename T>
void vector<T>::resize(size_t newsize)
{   
    if(newsize <= length){
         T *new_Data = new T[newsize];
        for (size_t i = 0; i < newsize ; i++)
        {
            new_Data[i] = std::move(Data[i]);
        }
        delete[] Data;
        length = std::min(length, newsize); 
        capacity = newsize;
        Data = new_Data;
    }
    else{
         T *new_Data = new T[newsize];
        for (size_t i = 0; i < length ; i++)
        {
            new_Data[i] = std::move(Data[i]);
        }
        delete[] Data;
        for(size_t i = length ; i<newsize;i++){new_Data[i]=0;}
        length = newsize ; 
        capacity = newsize;
        Data = new_Data;
    }
   
}

template <typename T>
void vector<T>::reserve(size_t new_capacity) {
    if (new_capacity <= capacity) return;
    T* new_Data = new T[new_capacity];
    for (size_t i = 0; i < length; i++) {
        new_Data[i] = std::move(Data[i]);
    }
    delete[] Data;
    Data = new_Data;
    capacity = new_capacity;
}

/*==================================================
    Appending /Inserting/delete the elements
===================================================*/
template <typename T>
void vector<T>::push_back(const T& value)
{
    if (length == capacity)
    {
        reserve(capacity == 0 ? 1 : 2 * capacity);
    }
    Data[length++] = value;
}

template <typename T>
void vector<T>::push_back(T&& value)
{
    if (length == capacity)
    {
        reserve(capacity == 0 ? 1 : 2 * capacity);
    }
    Data[length++] = std::move(value);
}

template <typename T>
void vector<T>::pop_back()
{
    if (length == 0)
    {
        throw std::underflow_error("vector is empty.");
    }
    length--;
}


template <typename T>
void vector<T>::clear()
{
    length = 0;
}
// Zero based indexing //
template <typename T>
void vector<T>::insert(size_t index, const T &value)
{
    if (index > length )
    {
        throw std::out_of_range("Insert index is out of bounds");
    }

    if (length == capacity)
    {
        reserve(capacity == 0 ? 1 : 2 * capacity);
    }
    for (int i = length; i > index; i--)
    {
        Data[i] = Data[i - 1];
    }
    Data[index] = value;
    length++;
}

template <typename T>
void vector<T>::erase(size_t index)
{
    if ( index >= length)
    {
        throw std::out_of_range("Index is out of Bounds");
    }
    for (int i = index; i < length - 1; i++)
    {
        Data[i] = Data[i + 1];
    }
    length--;
}



template <typename T>
bool vector<T>::empty()const
{
    return length == 0;
}

template <typename T>
void vector<T>::swap(vector<T>& other)
{
    T *new_ptr = Data;
    size_t temps = length;
    size_t tempc = capacity;
    Data = other.Data;
    other.Data = new_ptr;
    length = other.length;
    capacity = other.capacity;
    other.length = temps;
    other.capacity = tempc;
}


template <typename T>
vector<T>::vector(std::initializer_list<T> init) {
    length = capacity = init.size();
    Data = new T[capacity];
    size_t i = 0;
    for (const auto& elem : init) {
        Data[i++] = elem;
    }
}


template <typename T>
void vector<T>::print() const {
    for (size_t i = 0; i < length; ++i)
        std::cout << Data[i] << " ";
    std::cout << "\n";
}

template <typename T>
vector<T> vector<T>::slice(size_t x, size_t y) const {
    if (x > y) {
        throw std::underflow_error("Invalid range");
    }
    if (y >= this->length) {
        throw std::out_of_range("Out of bounds");
    }

    vector<T> result(y - x + 1);
    for (size_t i = x; i <= y; ++i) {
        result[i - x] = Data[i];
    }
    return result;
}


