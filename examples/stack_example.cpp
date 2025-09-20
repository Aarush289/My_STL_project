#include <iostream>
#include "../include/mystl/stack.h"

int main() {
    stack<int> st;
    for (int x: {1,2,3,4}) st.push(x);
    std::cout << "top=" << st.top() << " size=" << st.size() << "\n";
    while (!st.empty()) { std::cout << st.top() << " "; st.pop(); }
    std::cout << "\n";

    // copy/move
    stack<int> a; a.push(7); a.push(8);
    stack<int> b(a);
    stack<int> c(std::move(b));
    std::cout << "c.top=" << c.top() << " c.size=" << c.size() << "\n";
    return 0;
}
