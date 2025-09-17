#pragma once
#include "priority_queue.h"

template<class T  , class Compare>
void priority_queue<T , Compare>::shift_up(size_t idx){
    while(idx>0){
        size_t parent = (idx-1)/2;
        if(!comp_(data[parent] , data[idx])){break;}
        std::swap(data[idx] , data[parent]);
        idx = parent;
    }
}

template<class T  , class Compare>
void priority_queue<T , Compare>::shift_down(size_t idx){
   size_t n = data.size();
   while(1){
        size_t left = 2*idx+1;
        size_t right = 2*idx+2;
        size_t best = idx;
        if(left < n && comp_(data[best] ,data[left])) best =left;
        if(right < n && comp_(data[best] ,data[right])) best =right;
        if(best == idx) break;
        std::swap(data[best] , data[idx]);
        idx = best ;
   }    
}

template<class T  , class Compare>
void priority_queue<T , Compare>::rebuild_heap(){
    for(size_t i= data.size()/2 -1 ; i>=0;i--){
        shift_down(i);
    }
}

template<class T  , class Compare>
priority_queue<T , Compare>::priority_queue(): data() , comp_(){}


template<class T  , class Compare>
priority_queue<T , Compare>::priority_queue(Compare& other): data() , comp_(other){}

template<class T  , class Compare>
priority_queue<T , Compare>::priority_queue(const priority_queue& other){
    data = other.data ;
    comp_ = other.comp_;
}

template<class T  , class Compare>
priority_queue<T , Compare>::priority_queue(priority_queue&& other)noexcept{
    data = std:: move(other.data);
    comp_ = other.comp_;
}

template<class T  , class Compare>
priority_queue<T, Compare>& priority_queue<T , Compare>::operator=(const priority_queue& other){
    if(this!=&other){
        data = other.data;
        comp_ = other.comp_;
    }
    return *this;
}


template<class T  , class Compare>
priority_queue<T, Compare>& priority_queue<T , Compare>::operator=(priority_queue&& other)noexcept{
    if(this!= &other){
        data = std::move(other.data);
        comp_ = std::move(other.comp_);
    }
    return *this;
}

template<class T , class Compare>
void priority_queue<T,Compare>::push(const T& key){
    data.push_back(key);
    shift_up(data.size()-1);
}

template<class T , class Compare>
void priority_queue<T,Compare>::push(T&& key){
    data.push_back(std::move(key));
    shift_up(data.size()-1);
}

template<class T , class Compare>
void priority_queue<T,Compare>::pop(){
    std::swap(data[0] , data[data.size()-1]);
    data.pop_back();
    shift_down(0);
}

template<class T , class Compare>
const T& priority_queue<T,Compare>::top() const{
    return data[0];
}

template<class T , class Compare>
bool priority_queue<T,Compare>::empty()const{
    return data.empty();
}

template<class T , class Compare>
size_t priority_queue<T,Compare>::size()const{
    return data.size();
}

template<class T , class Compare>
void priority_queue<T,Compare>::set_compare(const Compare& comp){
    comp_ = comp;
}

