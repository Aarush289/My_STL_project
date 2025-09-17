#include<iostream>
#include<utility>

template <typename Type>
class Unique_Ptr{
    private:
                Type* ptr;

    public:
            explicit Unique_Ptr(Type* p=nullptr) : ptr(p){}
            ~Unique_Ptr(){
                delete ptr;
            }

            Unique_Ptr(const Unique_Ptr&)=delete;
            Unique_Ptr& operator=(const Unique_Ptr&)=delete;

            Unique_Ptr(Unique_Ptr&& other) noexcept : ptr(other.ptr){
                other.ptr=nullptr;
            }

            Unique_Ptr& operator=(Unique_Ptr&& other) noexcept {
                if(this!=&other){
                    delete ptr;
                    ptr=other.ptr;
                    other.ptr=nullptr;
                }
                return *this;
            }

            Type& operator*() const{
                return *ptr;
            }

            Type* operator->() const{
                return ptr;
            }

            bool isValid() const{
                if (ptr==nullptr){
                    return true;
                }
                else{
                    return false;
                }
            }
};