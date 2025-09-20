#include <iostream>
#include "../include/mystl/deque.h"

int main() {
    Deque<int> d;
    d.push_back(2); d.push_front(1); d.push_back(3); d.push_front(0); // [0,1,2,3]
    std::cout << "size=" << d.size() << " front=" << d.front() << " back=" << d.back() << "\n";
    for (size_t i=0;i<d.size();++i) std::cout << d[i] << " ";
    std::cout << "\n";
    return 0;
}
