#include <iostream>
#include <string>
#include "../include/mystl/queue.h"

int main() {
    queue<std::string> q;
    q.push("alpha"); q.push("beta"); q.push("gamma");
    std::cout << "front=" << q.front() << " back=" << q.back() << "\n";
    while (!q.empty()) { std::cout << q.front() << " "; q.pop(); }
    std::cout << "\n";
    return 0;
}
