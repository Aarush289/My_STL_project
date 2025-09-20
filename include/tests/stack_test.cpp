// stack_test.cpp
#include <cassert>
#include <iostream>
#include "../mystl/stack.h"   // your header from earlier

// Tiny helper to show progress without a test framework
static int g_passed = 0, g_failed = 0;
#define EXPECT_TRUE(cond) do { \
    if (cond) { ++g_passed; } else { \
        ++g_failed; \
        std::cerr << "EXPECT_TRUE failed at " << __FILE__ << ":" << __LINE__ \
                  << " -> " #cond << std::endl; \
    } \
} while(0)

template <typename T>
void fill_stack(stack<T>& s, std::initializer_list<T> vals) {
    for (const auto& v : vals) s.push(v);
}

void test_default_ctor_and_basic_ops() {
    stack<int> s;
    EXPECT_TRUE(s.empty());
    EXPECT_TRUE(s.size() == 0);

    // push 1..5
    for (int i = 1; i <= 5; ++i) s.push(i);
    EXPECT_TRUE(!s.empty());
    EXPECT_TRUE(s.size() == 5);
    EXPECT_TRUE(s.top() == 5);

    // pop and top changes
    s.pop();
    EXPECT_TRUE(s.size() == 4);
    EXPECT_TRUE(s.top() == 4);

    // clear and shrink
    s.clear();
    s.shrink_to_fit(); // cannot easily verify capacity, just ensure it compiles
    EXPECT_TRUE(s.empty());
    EXPECT_TRUE(s.size() == 0);
}

void test_copy_ctor_assignment() {
    stack<int> a;
    fill_stack(a, {1,2,3,4});

    stack<int> b(a); // copy ctor
    EXPECT_TRUE(b.size() == a.size());
    EXPECT_TRUE(b == a);
    EXPECT_TRUE(!(b != a));

    stack<int> c;
    c = a; // copy assign
    EXPECT_TRUE(c.size() == a.size());
    EXPECT_TRUE(c == a);

    // mutate original, copies must be independent
    a.pop();
    a.push(99);
    EXPECT_TRUE(a.top() == 99);
    EXPECT_TRUE(b.top() == 4);
    EXPECT_TRUE(c.top() == 4);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a != c);
}

void test_move_ctor_assignment() {
    stack<int> a;
    fill_stack(a, {7,8,9});

    stack<int> b(std::move(a)); // move ctor
    EXPECT_TRUE(b.size() == 3);
    EXPECT_TRUE(b.top() == 9);
    // moved-from 'a' state is valid but unspecified; don't assert on it

    stack<int> c;
    c = std::move(b); // move assign
    EXPECT_TRUE(c.size() == 3);
    EXPECT_TRUE(c.top() == 9);
}

void test_comparisons_lexicographic() {
    stack<int> x, y, z;
    fill_stack(x, {1,2,3});
    fill_stack(y, {1,2,4});
    fill_stack(z, {1,2,3,5});

    // Assuming your relational operators are lexicographic on the underlying container
    EXPECT_TRUE(x < y);   // [1,2,3] < [1,2,4]
    EXPECT_TRUE(y > x);
    EXPECT_TRUE(x != y);
    EXPECT_TRUE(!(x == y));

    // Prefix equality & length difference
    EXPECT_TRUE(x < z);   // [1,2,3] < [1,2,3,5]
    EXPECT_TRUE(!(z < x));
}

void test_const_top() {
    stack<int> s;
    fill_stack(s, {10,20,30});
    const stack<int> cs = s; // copy to const

    // const overload
    EXPECT_TRUE(cs.top() == 30);

    // non-const still works and independent
    EXPECT_TRUE(s.top() == 30);
    // ensure reading top() doesn't change size
    (void)cs.top();
    EXPECT_TRUE(cs.size() == 3);
}

void test_equality_semantics() {
    stack<int> a, b;
    EXPECT_TRUE(a == b);
    a.push(1);
    EXPECT_TRUE(a != b);
    b.push(1);
    EXPECT_TRUE(a == b);
    a.push(2); b.push(2);
    EXPECT_TRUE(a == b);
    a.pop(); a.push(3);
    EXPECT_TRUE(a != b);
}

int main() {
    std::cout << "Running stack tests...\n";

    test_default_ctor_and_basic_ops();
    test_copy_ctor_assignment();
    test_move_ctor_assignment();
    test_comparisons_lexicographic();
    test_const_top();
    test_equality_semantics();

    std::cout << "Tests passed: " << g_passed << "\n";
    std::cout << "Tests failed: " << g_failed << "\n";
    if (g_failed == 0) {
        std::cout << "ALL TESTS PASSED ✅\n";
        return 0;
    } else {
        std::cout << "SOME TESTS FAILED ❌\n";
        return 1;
    }
}
