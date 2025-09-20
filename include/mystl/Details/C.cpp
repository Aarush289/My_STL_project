#include "../C.h"

C:: C(size_t n):value(n){}
C:: C(const C &other) : value(other.value) {}

C:: C(C &&other) noexcept : value(other.value) { other.value = 0; }
C& C:: operator= (const C &other) {
    if (this != &other) {
      value = other.value;
    }
    return *this;
  }
C& C::operator=(C &&other) noexcept {
    if (this != &other) {
      value = other.value;
      other.value = 0;
    }
    return *this;
  }
C:: ~C() {}
size_t C::get_val() { return value; }