#include <iostream>
#include <functional>
#include "../include/mystl/priority_queue.h"

int main() {
    priority_queue<int> maxpq;            // max-heap
    for (int v : {5,1,9,3,7}) maxpq.push(v);
    std::cout << "max: "; while(!maxpq.empty()){ std::cout<<maxpq.top()<<" "; maxpq.pop(); } std::cout<<"\n";

    // ctor takes non-const ref in your API
    std::greater<int> cmp;
    priority_queue<int, std::greater<int>> minpq(cmp);
    for (int v : {5,1,9,3,7}) minpq.push(v);
    std::cout << "min: "; while(!minpq.empty()){ std::cout<<minpq.top()<<" "; minpq.pop(); } std::cout<<"\n";
    return 0;
}
