#include <iostream>
#include "../include/mystl/Vector.h"

int main() {
    vector<int> v;                 // your custom vector
    for (int i=1;i<=5;++i) v.push_back(i*10);  // 10 20 30 40 50

    std::cout << "vector size=" << v.size() << " front=" << v[0]
              << " back=" << v[v.size()-1] << "\n";

    // iterate
    for (size_t i=0;i<v.size();++i) std::cout << v[i] << " ";
    std::cout << "\n";

    // copy & move
    vector<int> a = v;             // copy
    vector<int> b = std::move(a);  // move
    std::cout << "moved size=" << b.size() << "\n";
    return 0;
}
