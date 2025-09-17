#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Vector.h"
#include <functional>
#include <utility>
template<class T , class Compare = std::less<T>>
class priority_queue{
    private :
        vector<T> data;
        Compare comp_;
        void shift_up(size_t idx);
        void shift_down(size_t idx);
        void rebuild_heap();
    public :
        priority_queue();
        priority_queue(Compare& other);
        priority_queue(const priority_queue& other);
        priority_queue(priority_queue&& other) noexcept;
        priority_queue<T, Compare>& operator=(const priority_queue& other);
        priority_queue<T, Compare>& operator=(priority_queue&& other) noexcept;
        void push(const T& key);
        void push(T&& key) ; 
        void pop();
        const T& top()const;
        bool empty() const;
        size_t size()const;
        void set_compare(const Compare& comp);

};
#include "priority_queue.tpp"
#endif