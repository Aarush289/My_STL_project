#ifndef C_H
#define C_H

#include <assert.h>
#include <cstring>
#include <iostream>
#include <cstddef>  

class C { // Needed for testing
private:
  size_t value;

public:
  C(size_t v = 0) ;
  C(const C &other) ;
  C(C &&other);
  C &operator=(const C &other) ;
  C &operator=(C &&other) noexcept;
  ~C() {}
  size_t get_val() ;
};

#endif