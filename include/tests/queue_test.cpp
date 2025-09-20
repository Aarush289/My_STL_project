// queue_test.cpp
#include <iostream>
#include <string>
#include <utility>
#include "../mystl/queue.h"

// --- Tiny test harness (no frameworks) ---
static int g_passed = 0, g_failed = 0;

#define EXPECT_TRUE(cond) do { \
  if (cond) { ++g_passed; } \
  else { ++g_failed; std::cerr << "EXPECT_TRUE failed at " << __FILE__ << ":" << __LINE__ \
                               << " -> " #cond << std::endl; } \
} while(0)

#define EXPECT_EQ(a,b) EXPECT_TRUE((a) == (b))

// A small move/copy-counting type to validate move paths
struct Counter {
  int x{0};
  static inline int copies = 0, moves = 0;
  Counter() = default;
  explicit Counter(int v): x(v) {}
  Counter(const Counter& o): x(o.x) { ++copies; }
  Counter(Counter&& o) noexcept: x(o.x) { ++moves; }
  Counter& operator=(const Counter& o) { x = o.x; ++copies; return *this; }
  Counter& operator=(Counter&& o) noexcept { x = o.x; ++moves; return *this; }
  friend bool operator==(const Counter& a, const Counter& b){ return a.x==b.x; }
  friend bool operator<(const Counter& a, const Counter& b){ return a.x<b.x; }
};

// 1) Basic push/pop/front/back and size/empty
void test_basic_ops() {
  queue<int> q;
  EXPECT_TRUE(q.empty());
  EXPECT_EQ(q.size(), 0u);
  EXPECT_TRUE(q.empty() == q.empty()); // hit non-const overload too
  EXPECT_TRUE(q.size()  == q.size());

  // push 1,2,3
  q.push(1); q.push(2); q.push(3);
  EXPECT_TRUE(!q.empty());
  EXPECT_EQ(q.size(), 3u);
  EXPECT_EQ(q.front(), 1);
  EXPECT_EQ(q.back(),  3);

  // pop
  q.pop(); // drop 1
  EXPECT_EQ(q.front(), 2);
  EXPECT_EQ(q.back(),  3);
  EXPECT_EQ(q.size(),  2u);

  // clear + shrink_to_fit
  q.clear();
  q.shrink_to_fit();
  EXPECT_TRUE(q.empty());
  EXPECT_EQ(q.size(), 0u);
}

// 2) Copy ctor / copy assign (independence)
void test_copy_semantics() {
  queue<std::string> a;
  a.push(std::string("aa"));
  a.push(std::string("bb"));
  a.push(std::string("cc"));

  queue<std::string> b(a); // copy-ctor
  EXPECT_TRUE(b == a);
  EXPECT_TRUE(!(b != a));
  EXPECT_EQ(b.front(), std::string("aa"));
  EXPECT_EQ(b.back(),  std::string("cc"));

  queue<std::string> c;
  c = a; // copy-assign
  EXPECT_TRUE(c == a);

  // Mutate a; b,c should remain unchanged
  a.pop();             // a: bb, cc
  a.push(std::string("zz")); // a: bb, cc, zz
  EXPECT_TRUE(a != b);
  EXPECT_TRUE(a != c);
  EXPECT_EQ(b.front(), std::string("aa"));
  EXPECT_EQ(c.front(), std::string("aa"));
}

// 3) Move ctor / move assign (semantic checks, not move counts)
void test_move_semantics() {
  Counter::copies = Counter::moves = 0;

  // Build source queue with both rvalue and lvalue pushes
  queue<Counter> a;
  Counter c1(1), c2(2);
  a.push(std::move(c1));   // rvalue
  a.push(c2);              // lvalue (copy)
  a.push(Counter{3});      // temporary (rvalue)

  // Move-construct
  queue<Counter> b(std::move(a));
  EXPECT_EQ(b.size(), 3u);
  EXPECT_EQ(b.front().x, 1);
  EXPECT_EQ(b.back().x,  3);

  // After move-construct, 'a' is valid but unspecified. We won't assert on size/front/back.
  // We just ensure we can still use it (push/pop) without UB:
  a.push(Counter{42});
  EXPECT_TRUE(a.size() >= 1u);

  // Move-assign
  queue<Counter> c;
  c = std::move(b);
  EXPECT_EQ(c.size(), 3u);
  EXPECT_EQ(c.front().x, 1);
  EXPECT_EQ(c.back().x,  3);

  // Mutate 'c' and ensure 'b' no longer owns elements (but is still usable)
  c.pop();                     // drop 1 -> [2,3]
  EXPECT_EQ(c.front().x, 2);
  b.push(Counter{77});         // 'b' should still be a valid empty/rehydratable queue
  EXPECT_TRUE(b.size() >= 1u);

  // No assertions on Counter::moves/copies — they’re implementation dependent.
}


// 4) Lexicographic comparisons via underlying container
void test_lexicographic() {
  queue<int> x, y, z;
  // x = [1,2,3]
  x.push(1); x.push(2); x.push(3);
  // y = [1,2,4]
  y.push(1); y.push(2); y.push(4);
  // z = [1,2,3,5]
  z.push(1); z.push(2); z.push(3); z.push(5);

  EXPECT_TRUE(x < y);
  EXPECT_TRUE(y > x);
  EXPECT_TRUE(x != y);
  EXPECT_TRUE(!(x == y));

  EXPECT_TRUE(x < z);      // prefix shorter is less
  EXPECT_TRUE(!(z < x));
}

// 5) swap + shrink_to_fit stability
void test_swap_and_shrink() {
  queue<int> a, b;
  a.push(1); a.push(2); a.push(3);
  b.push(9);

  a.swap(b);
  EXPECT_EQ(a.size(), 1u);
  EXPECT_EQ(a.front(), 9);
  EXPECT_EQ(a.back(),  9);

  EXPECT_EQ(b.size(), 3u);
  EXPECT_EQ(b.front(), 1);
  EXPECT_EQ(b.back(),  3);

  b.shrink_to_fit(); // behavior not directly observable; just ensure no throw
  EXPECT_EQ(b.size(), 3u);
}

int main() {
  std::cout << "Running queue tests...\n";

  test_basic_ops();
  test_copy_semantics();
  test_move_semantics();
  test_lexicographic();
  test_swap_and_shrink();

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

