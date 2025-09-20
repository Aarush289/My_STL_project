#include <iostream>
// Adjust header name if yours differs (e.g. "String.h")
#include "../include/mystl/string.h"

int main() {
    string s = "hello";
    s.push_back(' ');
    s += "world";
    std::cout << s << "\n";

    // common ops
    string t = s.substr(0, 5);      // "hello"
    size_t pos = s.find("world");   // expect 6
    std::cout << "substr=" << t << " find(world)=" << pos << "\n";

    // copy/move
    string a = s;
    string b = std::move(a);
    std::cout << "moved: " << b << "\n";
    return 0;
}
