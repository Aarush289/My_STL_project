// tests/test_string.cpp
#include <cassert>
#include <cstring>
#include <iostream>

#include "../mystl/string.h"   // your custom ::string
#include "../mystl/Vector.h"   // for vector<string> used by split/join

// Avoid confusion with std::
template <typename T>
using MyVec = ::vector<T>;
using MyStr  = ::string;

static void test_ctors_and_assign() {
    MyStr s1;
    assert(s1.size() == 0);

    MyStr s2("hello");
    assert(s2.size() == 5);
    assert(std::strcmp(s2.c_str(), "hello") == 0);

    MyStr s3 = s2;                // copy
    assert(s3 == s2);

    MyStr s4(std::move(s3));      // move
    assert(s4 == MyStr("hello"));

    s1 = s4;                      // copy assign
    assert(s1 == MyStr("hello"));

    s3 = "world";                 // assign c-string
    assert(s3 == MyStr("world"));

    std::cout << "ctors_and_assign ok\n";
}

static void test_concat() {
    MyStr a("foo");
    MyStr b("bar");
    a += b;
    assert(a == MyStr("foobar"));

    MyStr c = MyStr("abc") + MyStr("def");
    assert(c == MyStr("abcdef"));

    std::cout << "concat ok\n";
}

static void test_compare_ops() {
    MyStr a("abc"), b("abc"), c("abd"), d("ab");
    assert(a == b);
    assert(a != c);
    assert(a > d);
    assert(d < a);
    assert(a <= b && a >= b);

    // strcmp-like compare: int return (negative/zero/positive)
    assert(a.compare(b) == 0);
    assert(a.compare(c) < 0);
    assert(c.compare(a) > 0);

    std::cout << "compare_ops ok\n";
}

static void test_cstr_cache_behavior() {
    MyStr s("cache");
    const char* p1 = s.c_str();              // build cache
    const char* p2 = s.c_str();              // reuse cache
    assert(std::strcmp(p1, "cache") == 0);
    assert(p1 == p2);                        // stable within no-mutation calls

    s += MyStr("d");                         // mutate -> cache must reflect new content
    const char* p3 = s.c_str();              // rebuild or update cache
    assert(std::strcmp(p3, "cached") == 0);  // content correctness is what we care about
    // Do NOT assert pointer inequality; allocator may reuse the same address.

    std::cout << "cstr_cache ok\n";
}

static void test_size_length_clear() {
    MyStr s("xyz");
    assert(s.size() == 3);
    assert(s.length() == 3);
    s.clear();
    assert(s.size() == 0);
    assert(std::strcmp(s.c_str(), "") == 0);
    std::cout << "size_length_clear ok\n";
}

static void test_substr_find_rfind() {
    MyStr s("bananaban");

    MyStr sub1 = s.substr(0, 6);   // "banana"
    assert(sub1 == MyStr("banana"));

    MyStr sub2 = s.substr(6);      // "ban"
    assert(sub2 == MyStr("ban"));

    size_t i1 = s.find(MyStr("ana"));   // first "ana" at 1
    assert(i1 == 1);

    size_t i2 = s.rfind(MyStr("ban"));  // last "ban" at 6
    assert(i2 == 6);

    size_t nf = s.find(MyStr("zzz"));   // not found
    assert(nf == MyStr::npos);

    std::cout << "substr_find_rfind ok\n";
}

static void test_insert_erase_append() {
    MyStr s("abc");
    s.append(MyStr("def"));              // "abcdef"
    assert(s == MyStr("abcdef"));

    s.insert(3, MyStr("_"));             // "abc_def"
    assert(s == MyStr("abc_def"));

    s.erase(3, 1);                       // "abcdef"
    assert(s == MyStr("abcdef"));

    s.insert(s.size(), MyStr("X"));      // "abcdefX"
    assert(s == MyStr("abcdefX"));

    std::cout << "insert_erase_append ok\n";
}

static void test_prefix_suffix() {
    MyStr s("unittest");
    assert(s.starts_with(MyStr("unit")));
    assert(!s.starts_with(MyStr("x")));
    assert(s.ends_with(MyStr("test")));
    assert(!s.ends_with(MyStr("y")));
    std::cout << "prefix_suffix ok\n";
}

static void test_split_join_case() {
    MyStr s("a,b,,c");
    MyVec<MyStr> parts = s.split(',');     // ["a","b","","c"]
    assert(parts.size() == 4);
    assert(parts[0] == MyStr("a"));
    assert(parts[1] == MyStr("b"));
    assert(parts[2] == MyStr(""));
    assert(parts[3] == MyStr("c"));

    char delim = '-';
    MyStr joined;
    joined.join(parts, delim);             // "a-b--c"
    assert(joined == MyStr("a-b--c"));

    MyStr t("AbCz");
    t.to_upper();                          // "ABCZ"
    assert(t == MyStr("ABCZ"));
    t.to_lower();                          // "abcz"
    assert(t == MyStr("abcz"));

    std::cout << "split_join_case ok\n";
}

int main() {
    std::cout << "Running string tests...\n";

    test_ctors_and_assign();
    test_concat();
    test_compare_ops();
    test_cstr_cache_behavior();
    test_size_length_clear();
    test_substr_find_rfind();
    test_insert_erase_append();
    test_prefix_suffix();
    test_split_join_case();

    std::cout << "All string tests passed ✅\n";
    return 0;
}

