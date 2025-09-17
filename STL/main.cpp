#include <iostream>
#include "set.h"

int main() {
    // 1) Empty set
    set<int> s;
    std::cout << "Empty? " << (s.empty() ? "yes" : "no") << "\n";

    // 2) Insert a few values (with duplicates)
    int vals[] = {5, 3, 7, 3, 1, 9, 5};
    for (int x : vals) {
        auto res = s.insert(x);
        std::cout << "insert(" << x << ") -> " << (res.second ? "inserted" : "duplicate") << "\n";
    }

    // 3) Show size and contents (ascending order)
    std::cout << "size = " << s.size() << "\n";
    std::cout << "contents: ";
    for (auto it = s.begin(); it != s.end(); ++it) std::cout << *it << " ";
    std::cout << "\n";

    // 4) contains / count / find
    int q1 = 3, q2 = 4;
    std::cout << "contains(" << q1 << ")? " << (s.contains(q1) ? "yes" : "no") << "\n";
    std::cout << "contains(" << q2 << ")? " << (s.contains(q2) ? "yes" : "no") << "\n";

    auto it7 = s.find(7);
    if (it7 != s.end()) std::cout << "find(7) -> " << *it7 << "\n";
    else                std::cout << "find(7) -> not found\n";

    // 5) lower_bound / upper_bound
    auto lb4 = s.lower_bound(4); // first >= 4
    std::cout << "lower_bound(4) -> ";
    if (lb4 != s.end()) std::cout << *lb4 << "\n"; else std::cout << "end\n";

    auto ub5 = s.upper_bound(5); // first > 5
    std::cout << "upper_bound(5) -> ";
    if (ub5 != s.end()) std::cout << *ub5 << "\n"; else std::cout << "end\n";

    // 6) erase by key and by iterator
    std::cout << "erase(100) -> " << s.erase(100) << " (should be 0)\n";
    std::cout << "erase(3)   -> " << s.erase(3)   << " (should be 1 if 3 existed)\n";

    auto it5 = s.find(5);
    if (it5 != s.end()) {
        auto next = s.erase(it5);
        std::cout << "erased iterator at 5, next is ";
        if (next != s.end()) std::cout << *next << "\n"; else std::cout << "end\n";
    }

    std::cout << "after erases, contents: ";
    for (auto it = s.begin(); it != s.end(); ++it) std::cout << *it << " ";
    std::cout << "\n";

    // 7) range erase: erase all elements < 8
    auto first = s.begin();
    auto last  = s.lower_bound(8);
    s.erase(first, last);

    std::cout << "after erase([begin, lower_bound(8))), contents: ";
    for (auto it = s.begin(); it != s.end(); ++it) std::cout << *it << " ";
    std::cout << "\n";

    // 8) initializer_list + swap
    set<int> t{4,4,2,10};
    std::cout << "t contents: ";
    for (auto it = t.begin(); it != t.end(); ++it) std::cout << *it << " ";
    std::cout << "\n";

    swap(s, t);
    std::cout << "after swap:\n";
    std::cout << "s: ";
    for (auto it = s.begin(); it != s.end(); ++it) std::cout << *it << " ";
    std::cout << "\n";
    std::cout << "t: ";
    for (auto it = t.begin(); it != t.end(); ++it) std::cout << *it << " ";
    std::cout << "\n";

    return 0;
}
