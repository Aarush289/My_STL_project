#include <iostream>
#include <string>
#include "../include/mystl/map.h"

int main() {
    map<std::string,int> m;
    m.insert("alice",10); m.insert("bob",20); m["carol"]=30; m["bob"]=25;

    std::cout << "contains(bob)=" << m.contains("bob") << " bob=" << m.at("bob") << "\n";
    std::cout << "in-order: ";
    for (auto it=m.begin(); it!=m.end(); ++it) std::cout << "("<<it->first<<":"<<it->second<<") ";
    std::cout << "\n";

    m.erase("alice");
    std::cout << "size=" << m.size() << "\n";
    return 0;
}
