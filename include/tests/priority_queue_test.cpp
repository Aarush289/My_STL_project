// priority_queue_test.cpp
#include <iostream>
#include <vector>
#include <string>
#include <functional>     // std::less, std::greater
#include <utility>        // std::move
#include <cstdint>
#include "../mystl/priority_queue.h"   // adjust include path to your header

// ---- Tiny test harness ----
static int g_passed = 0, g_failed = 0;

#define EXPECT_TRUE(cond) do { \
  if (cond) { ++g_passed; } \
  else { ++g_failed; std::cerr << "EXPECT_TRUE failed at " << __FILE__ << ":" << __LINE__ \
                               << " -> " #cond << std::endl; } \
} while(0)

#define EXPECT_EQ(a,b) EXPECT_TRUE((a) == (b))
#define EXPECT_NE(a,b) EXPECT_TRUE((a) != (b))

// ---------- Tests ----------

// 1) Default (max-heap) basic push/top/pop order
void test_max_heap_basic() {
  priority_queue<int> pq; // default Compare = std::less<int> -> max-heap

  int vals[] = {5, 1, 9, 3, 7, 7, -2};
  for (int v : vals) pq.push(v);

  std::vector<int> out;
  while (!pq.empty()) {
    out.push_back(pq.top());
    pq.pop();
  }
  // Expected non-increasing order
  std::vector<int> want = {9, 7, 7, 5, 3, 1, -2};
  EXPECT_EQ(out, want);
}

// 2) Min-heap via comparator (ctor takes non-const ref per your interface)
void test_min_heap_via_ctor() {
  std::greater<int> cmp; // min-heap
  priority_queue<int, std::greater<int>> pq(cmp);

  for (int v : {5, 1, 9, 3, 7, -2}) pq.push(v);

  std::vector<int> out;
  while (!pq.empty()) { out.push_back(pq.top()); pq.pop(); }

  std::vector<int> want = {-2, 1, 3, 5, 7, 9};
  EXPECT_EQ(out, want);
}

// 3) set_compare BEFORE inserting (so no rebuild needed)
void test_set_compare_on_empty_then_use() {
  priority_queue<int, std::greater<int>> pq; // default constructed with std::greater<int>?
  // To be explicit:
  std::greater<int> g;
  pq.set_compare(g);      // safe because pq is empty; no rebuild requirement

  for (int v : {4, 4, 2, 8, 1}) pq.push(v);

  std::vector<int> out;
  while (!pq.empty()) { out.push_back(pq.top()); pq.pop(); }
  std::vector<int> want = {1, 2, 4, 4, 8}; // min-heap behavior
  EXPECT_EQ(out, want);
}

// 4) top() and size() sanity without popping all
void test_top_and_size_peek() {
  priority_queue<int> pq;
  pq.push(10);
  pq.push(3);
  pq.push(42);
  pq.push(7);

  EXPECT_EQ(pq.size(), (size_t)4);
  EXPECT_EQ(pq.top(), 42);

  pq.pop();
  EXPECT_EQ(pq.size(), (size_t)3);
  EXPECT_EQ(pq.top(), 10);
}

// 5) Copy semantics (independence)
void test_copy_semantics() {
  priority_queue<std::string> a;
  a.push(std::string("aa"));
  a.push(std::string("zz"));
  a.push(std::string("mm"));

  priority_queue<std::string> b(a);       // copy-ctor
  EXPECT_TRUE(!b.empty());
  EXPECT_EQ(b.size(), a.size());
  EXPECT_EQ(b.top(), a.top());            // both should have "zz" on top for max-heap

  priority_queue<std::string> c;
  c = a;                                   // copy-assign
  EXPECT_EQ(c.size(), a.size());
  EXPECT_EQ(c.top(), a.top());

  // Mutate a; b and c should be unchanged
  a.pop();            // remove "zz"
  a.push(std::string("xx"));
  EXPECT_NE(a.top(), b.top());
  EXPECT_NE(a.top(), c.top());
}

// 6) Move semantics (shape/value preserved; moved-from usable)
void test_move_semantics() {
  priority_queue<int> a;
  for (int v : {10, 20, 5}) a.push(v);

  priority_queue<int> b(std::move(a));  // move-ctor
  EXPECT_EQ(b.size(), (size_t)3);
  EXPECT_EQ(b.top(), 20);
  // 'a' valid but unspecified; ensure we can reuse it:
  a.push(99);
  EXPECT_EQ(a.top(), 99);

  priority_queue<int> c;
  c = std::move(b);                     // move-assign
  EXPECT_EQ(c.size(), (size_t)3);
  EXPECT_EQ(c.top(), 20);
  // 'b' should be reusable after move-assign-away
  b.push(7);
  EXPECT_EQ(b.top(), 7);
}

// 7) Custom comparator on struct (order by key, tiebreaker by id)
struct Item {
  int key;
  int id;
};
struct ByKeyThenIdMax {
  bool operator()(const Item& a, const Item& b) const {
    // std::less-like: return true if a < b; for max-heap we want "largest" at top.
    if (a.key != b.key) return a.key < b.key;
    return a.id < b.id;
  }
};
bool operator==(const Item& a, const Item& b) { return a.key == b.key && a.id == b.id; }

void test_custom_struct_maxheap() {
  ByKeyThenIdMax cmp;
  priority_queue<Item, ByKeyThenIdMax> pq(cmp);

  pq.push(Item{3, 10});
  pq.push(Item{5,  2});
  pq.push(Item{5,  8});
  pq.push(Item{1, 99});
  pq.push(Item{5,  1});

  // Expected pop order: key desc, id desc (because max-heap; our comparator says a<b if key smaller,
  // so "largest" = highest key, then highest id)
  std::vector<Item> out;
  while (!pq.empty()) { out.push_back(pq.top()); pq.pop(); }

  std::vector<Item> want = {
    {5, 8}, {5, 2}, {5, 1}, {3, 10}, {1, 99}
  };
  EXPECT_EQ(out.size(), want.size());
  for (size_t i = 0; i < out.size(); ++i) {
    EXPECT_EQ(out[i].key, want[i].key);
    EXPECT_EQ(out[i].id,  want[i].id);
  }
}

// 8) Many pops to empty (safety)
void test_pop_until_empty_safety() {
  priority_queue<int> pq;
  for (int v = 0; v < 100; ++v) pq.push(v);
  EXPECT_EQ(pq.top(), 99);
  for (int i = 0; i < 100; ++i) {
    EXPECT_TRUE(!pq.empty());
    pq.pop();
  }
  EXPECT_TRUE(pq.empty());
  EXPECT_EQ(pq.size(), (size_t)0);
}

// ---------- Main ----------
int main() {
  std::cout << "Running priority_queue tests...\n";

  test_max_heap_basic();
  test_min_heap_via_ctor();
  test_set_compare_on_empty_then_use();
  test_top_and_size_peek();
  test_copy_semantics();
  test_move_semantics();
  test_custom_struct_maxheap();
  test_pop_until_empty_safety();

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
