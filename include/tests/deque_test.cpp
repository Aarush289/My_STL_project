// deque_test.cpp
#include <iostream>
#include <string>
#include <utility>
#include "../mystl/deque.h"

// --- Tiny test harness ---
static int g_passed = 0, g_failed = 0;

#define EXPECT_TRUE(cond) do { \
  if (cond) { ++g_passed; } \
  else { ++g_failed; std::cerr << "EXPECT_TRUE failed at " << __FILE__ << ":" << __LINE__ \
                               << " -> " #cond << std::endl; } \
} while(0)

#define EXPECT_EQ(a,b) EXPECT_TRUE((a) == (b))
#define EXPECT_NE(a,b) EXPECT_TRUE((a) != (b))

// 1) Basic push/pop at both ends, indexing, front/back, size/empty/clear
void test_basic_ops() {
  Deque<int> d;
  EXPECT_TRUE(d.empty());
  EXPECT_EQ(d.size(), 0u);

  // push_back then push_front to check both ends
  d.push_back(2);   // [2]
  d.push_front(1);  // [1,2]
  d.push_back(3);   // [1,2,3]
  d.push_front(0);  // [0,1,2,3]

  EXPECT_TRUE(!d.empty());
  EXPECT_EQ(d.size(), 4u);
  EXPECT_EQ(d.front(), 0);
  EXPECT_EQ(d.back(),  3);

  // operator[]
  EXPECT_EQ(d[0], 0);
  EXPECT_EQ(d[1], 1);
  EXPECT_EQ(d[2], 2);
  EXPECT_EQ(d[3], 3);

  // pop from both ends
  d.pop_front(); // [1,2,3]
  EXPECT_EQ(d.front(), 1);
  d.pop_back();  // [1,2]
  EXPECT_EQ(d.back(),  2);
  EXPECT_EQ(d.size(),  2u);

  d.clear();
  EXPECT_TRUE(d.empty());
  EXPECT_EQ(d.size(), 0u);
}

// 2) reserve / shrink_to_fit (no capacity API -> smoke test only)
void test_reserve_and_shrink() {
  Deque<int> d;
  d.reserve(64);  // should not crash and should accept further pushes
  for (int i = 0; i < 10; ++i) d.push_back(i);
  EXPECT_EQ(d.size(), 10u);
  EXPECT_EQ(d.front(), 0);
  EXPECT_EQ(d.back(),  9);

  d.shrink_to_fit(); // just ensure it doesn't change logical size or values
  EXPECT_EQ(d.size(), 10u);
  EXPECT_EQ(d[0], 0);
  EXPECT_EQ(d[9], 9);
}

// 3) Copy ctor / copy assign (independence checks)
void test_copy_semantics() {
  Deque<std::string> a;
  a.push_back(std::string("A"));
  a.push_back(std::string("B"));
  a.push_back(std::string("C"));    // a = ["A","B","C"]

  Deque<std::string> b(a);          // copy-ctor
  EXPECT_TRUE(b == a);
  EXPECT_TRUE(!(b != a));
  EXPECT_EQ(b.size(), 3u);
  EXPECT_EQ(b.front(), std::string("A"));
  EXPECT_EQ(b.back(),  std::string("C"));

  Deque<std::string> c;
  c = a;                            // copy-assign
  EXPECT_TRUE(c == a);

  // Mutate a; b and c must remain unchanged
  a.pop_front();                    // a = ["B","C"]
  a.push_back(std::string("Z"));    // a = ["B","C","Z"]
  EXPECT_TRUE(a != b);
  EXPECT_TRUE(a != c);
  EXPECT_EQ(b.front(), std::string("A"));
  EXPECT_EQ(c.front(), std::string("A"));
}

// 4) Move ctor / move assign (shape/values preserved; moved-from still usable)
void test_move_semantics() {
  Deque<int> a;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);

  Deque<int> b(std::move(a));   // move-ctor
  EXPECT_EQ(b.size(), 3u);
  EXPECT_EQ(b.front(), 10);
  EXPECT_EQ(b.back(),  30);

  // 'a' is valid but unspecified; ensure we can still use it
  a.push_back(42);
  EXPECT_TRUE(a.size() >= 1u);
  EXPECT_EQ(a.back(), 42);

  Deque<int> c;
  c = std::move(b);             // move-assign
  EXPECT_EQ(c.size(), 3u);
  EXPECT_EQ(c.front(), 10);
  EXPECT_EQ(c.back(),  30);

  // Mutate c; b should be reusable
  c.pop_front();                // c = [20,30]
  EXPECT_EQ(c.front(), 20);
  b.push_back(77);              // b should be valid after move-assign-away
  EXPECT_TRUE(b.size() >= 1u);
  EXPECT_EQ(b.back(), 77);
}

// 5) Lexicographic comparisons
void test_lexicographic() {
  Deque<int> x, y, z;
  // x = [1,2,3]
  x.push_back(1); x.push_back(2); x.push_back(3);
  // y = [1,2,4]
  y.push_back(1); y.push_back(2); y.push_back(4);
  // z = [1,2,3,5]
  z.push_back(1); z.push_back(2); z.push_back(3); z.push_back(5);

  EXPECT_TRUE(x < y);
  EXPECT_TRUE(y > x);
  EXPECT_NE(x, y);
  EXPECT_TRUE(!(x == y));

  EXPECT_TRUE(x < z);     // prefix shorter is less
  EXPECT_TRUE(!(z < x));
}

// 6) swap correctness
void test_swap() {
  Deque<int> a, b;
  a.push_back(1); a.push_back(2); a.push_back(3);   // a = [1,2,3]
  b.push_back(9);                                   // b = [9]

  a.swap(b);
  EXPECT_EQ(a.size(), 1u);
  EXPECT_EQ(a.front(), 9);
  EXPECT_EQ(a.back(),  9);

  EXPECT_EQ(b.size(), 3u);
  EXPECT_EQ(b.front(), 1);
  EXPECT_EQ(b.back(),  3);
}

// 7) const operator[] access (no const front/back assumed)
void test_const_index_access() {
  Deque<int> d;
  d.push_back(5);
  d.push_back(6);
  d.push_back(7);

  const Deque<int>& cd = d; // const view
  EXPECT_EQ(cd[0], 5);
  EXPECT_EQ(cd[1], 6);
  EXPECT_EQ(cd[2], 7);
}

int main() {
  std::cout << "Running deque tests...\n";

  test_basic_ops();
  test_reserve_and_shrink();
  test_copy_semantics();
  test_move_semantics();
  test_lexicographic();
  test_swap();
  test_const_index_access();

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
