// examples/main.cpp
#include <iostream>
#include <string>
#include <functional>

#include "../include/mystl/Vector.h"
#include "../include/mystl/deque.h"
#include "../include/mystl/queue.h"
#include "../include/mystl/priority_queue.h"
#include "../include/mystl/map.h"

int main() {
    std::cout << "== Vector ==\n";
    vector<int> v;
    for (int i = 1; i <= 5; ++i) v.push_back(i * 10);
    for (size_t i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << "\n";

    std::cout << "== Deque ==\n";
    Deque<int> d;
    d.push_front(1); d.push_back(2); d.push_back(3);
    for (size_t i = 0; i < d.size(); ++i) std::cout << d[i] << " ";
    std::cout << "\n";

    std::cout << "== Queue ==\n";
    queue<std::string> q;
    q.push("alpha"); q.push("beta"); q.push("gamma");
    std::cout << "front=" << q.front() << " back=" << q.back() << "\n";
    while (!q.empty()) { std::cout << q.front() << " "; q.pop(); }
    std::cout << "\n";

    std::cout << "== Priority Queue (max-heap) ==\n";
    priority_queue<int> maxpq;
    for (int x : {5, 1, 9, 3, 7}) maxpq.push(x);
    while (!maxpq.empty()) { std::cout << maxpq.top() << " "; maxpq.pop(); }
    std::cout << "\n";

    std::cout << "== Map ==\n";
    map<std::string,int> m;
    m.insert("alice", 10);
    m.insert("bob",   20);
    m["carol"] = 30;
    m["bob"]   = 25;
    for (auto it = m.begin(); it != m.end(); ++it)
        std::cout << "(" << it->first << ":" << it->second << ") ";
    std::cout << "\n";

    return 0;
}
