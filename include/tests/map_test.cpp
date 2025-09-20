// map_test.cpp
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include "../mystl/map.h"     

// ---------- Tiny test harness ----------
static int g_passed = 0, g_failed = 0;
#define EXPECT_TRUE(cond) do { \
  if (cond) { ++g_passed; } \
  else { ++g_failed; std::cerr << "EXPECT_TRUE failed at " << __FILE__ << ":" << __LINE__ \
                               << " -> " #cond << std::endl; } \
} while(0)
#define EXPECT_EQ(a,b) EXPECT_TRUE((a) == (b))
#define EXPECT_NE(a,b) EXPECT_TRUE((a) != (b))

// Helper to read the map via forward iteration to a single string: "k1:v1 k2:v2 ..."
template <class K, class V>
std::string dump_inorder(map<K,V>& m) {
  std::string s;
  for (auto it = m.begin(); it != m.end(); ++it) {
    s += std::to_string(it->first);
    s += ":";
    s += std::to_string(it->second);
    s += " ";
  }
  return s;
}

// ---------- Tests ----------

void test_empty_and_basic_insert() {
  map<int,int> m;
  EXPECT_TRUE(m.empty());
  EXPECT_EQ(m.size(), (size_t)0);

  // Insert out of order
  EXPECT_TRUE(m.insert(5,50).second);
  EXPECT_TRUE(m.insert(2,20).second);
  EXPECT_TRUE(m.insert(8,80).second);
  EXPECT_TRUE(m.insert(1,10).second);
  EXPECT_TRUE(m.insert(3,30).second);

  EXPECT_TRUE(!m.empty());
  EXPECT_EQ(m.size(), (size_t)5);

  // Duplicate insert should be rejected
  auto ins = m.insert(3,999);
  EXPECT_TRUE(ins.first != nullptr);
  EXPECT_TRUE(!ins.second);
  EXPECT_EQ(ins.first->data.second, 30);

  // Inorder keys must be sorted
  std::string got = dump_inorder(m);       // "1:10 2:20 3:30 5:50 8:80 "
  EXPECT_EQ(got, std::string("1:10 2:20 3:30 5:50 8:80 "));
}

void test_brackets_and_at() {
  map<std::string,int> m;
  // operator[] inserts default when missing
  EXPECT_EQ(m.size(), (size_t)0);
  m["alice"] = 1;              // insert
  m["bob"] = 2;                // insert
  m["bob"] = 5;                // update
  EXPECT_EQ(m.size(), (size_t)2);
  EXPECT_TRUE(m.contains("alice"));
  EXPECT_TRUE(m.contains("bob"));
  EXPECT_EQ(m.count("bob"), (size_t)1);
  EXPECT_EQ(m["bob"], 5);

  // at() returns ref for found
  EXPECT_EQ(m.at("alice"), 1);

  // at() throws for missing
  bool threw = false;
  try { (void)m.at("charlie"); } catch (const std::out_of_range&) { threw = true; }
  EXPECT_TRUE(threw);
}

void test_iterators_forward_backward() {
  map<int,int> m;
  for (int k : {4,2,6,1,3,5,7}) m.insert(k, k*10);
  // forward
  int expectedK[] = {1,2,3,4,5,6,7};
  int i=0;
  for (auto it = m.begin(); it != m.end(); ++it, ++i) {
    EXPECT_EQ(it->first, expectedK[i]);
    EXPECT_EQ(it->second, expectedK[i]*10);
  }
  EXPECT_EQ(i, 7);

  // backward: end()-- should give max
  auto it = m.end();
  --it; // last
  for (int j=6; j>=0; --j, --it) {
    EXPECT_EQ((*(it)).first, expectedK[j]);
  }
}

void test_reverse_iterators() {
  map<int,int> m;
  for (int k : {10, 7, 13, 5, 8}) m.insert(k, k+100);

  int expectedDesc[] = {13,10,8,7,5};
  int i=0;
  for (auto rit = m.rbegin(); rit != m.rend(); ++rit, ++i) {
    EXPECT_EQ(rit->first, expectedDesc[i]);
    EXPECT_EQ(rit->second, expectedDesc[i]+100);
  }
  EXPECT_EQ(i, 5);
}

void test_lower_upper_equal_range() {
  map<int,int> m;
  for (int k : {10, 20, 30, 40}) m.insert(k, k);

  // Key present
  {
    auto lb = m.lower_bound(20);
    auto ub = m.upper_bound(20);
    EXPECT_TRUE(lb != m.end());
    EXPECT_EQ(lb->first, 20);
    EXPECT_TRUE(ub != m.end());
    EXPECT_EQ(ub->first, 30);

    auto p = m.equal_range(20);
    EXPECT_EQ(p.first->first, 20);
    EXPECT_EQ(p.second->first, 30);
  }

  // Key between 20 and 30
  {
    auto lb = m.lower_bound(25);
    auto ub = m.upper_bound(25);
    EXPECT_EQ(lb->first, 30);
    EXPECT_EQ(ub->first, 30);
  }

  // Key smaller than min
  {
    auto lb = m.lower_bound(1);
    EXPECT_EQ(lb->first, 10);
    auto ub = m.upper_bound(1);
    EXPECT_EQ(ub->first, 10);
  }

  // Key larger than max
  {
    auto lb = m.lower_bound(100);
    auto ub = m.upper_bound(100);
    EXPECT_TRUE(lb == m.end());
    EXPECT_TRUE(ub == m.end());
  }
}

void test_erase_leaf_one_two_children() {
  map<int,int> m;
  // build a tree
  for (int k : {50,30,70,20,40,60,80,35,45}) m.insert(k,k);

  // leaf
  m.erase(20);
  EXPECT_TRUE(!m.contains(20));
  EXPECT_EQ(m.size(), (size_t)8);

  // one child (make 35 a child, then erase 30 which now has one child (40) after prior removal)
  m.erase(30);
  EXPECT_TRUE(!m.contains(30));
  EXPECT_EQ(m.size(), (size_t)7);

  // two children (erase 70 which has 60 and 80)
  m.erase(70);
  EXPECT_TRUE(!m.contains(70));
  EXPECT_EQ(m.size(), (size_t)6);

  // still in-order sorted
  std::string got = dump_inorder(m);
  // remaining keys should be: 35,40,45,50,60,80
  EXPECT_EQ(got, std::string("35:35 40:40 45:45 50:50 60:60 80:80 "));
}

void test_copy_move_swap_and_find() {
  map<int,int> a;
  for (int k : {5,1,9,3}) a.insert(k,k*10);
  // copy
  map<int,int> b(a);
  EXPECT_EQ(dump_inorder(a), dump_inorder(b));
  EXPECT_TRUE(b.contains(9));
  EXPECT_EQ(b.find(3)->second, 30);

  // change 'a' and ensure 'b' unchanged
  a.insert(7,70);
  EXPECT_NE(dump_inorder(a), dump_inorder(b));

  // move
  map<int,int> c(std::move(a));
  EXPECT_TRUE(c.contains(7));
  EXPECT_TRUE(!c.empty());

  // swap
  map<int,int> d;
  d.insert(42,420);
  d.swap(c);
  EXPECT_TRUE(d.contains(7));     // took c's contents
  EXPECT_TRUE(c.contains(42));    // took d's old contents
}

void test_comparisons() {
  map<int,int> x, y;
  for (int k : {1,2,3}) x.insert(k,k);
  for (int k : {1,2,3}) y.insert(k,k);

  EXPECT_TRUE(x == y);
  EXPECT_TRUE(!(x != y));
  EXPECT_TRUE(!(x < y));
  EXPECT_TRUE(!(x > y));

  y.erase(3);
  y.insert(4,4); // y: 1,2,4
  EXPECT_TRUE(x != y);
  EXPECT_TRUE(y > x);   // lexicographic: at key 3 vs 4, 3<4 => x<y, so y>x
  EXPECT_TRUE(x < y);
}

void test_traversal_helpers() {
  map<int,int> m;
  for (int k : {4,2,1,3,6,5}) m.insert(k, k*10);

  auto in  = m.give_InOrder();   // Vector< pair<K,V> >
  auto pre = m.give_Preorder();
  auto post= m.give_Postorder();

  // In-order should be sorted keys: 1..6 (except 0 and 7)
  EXPECT_EQ(in.size(), (size_t)6);
  for (int i=0; i<6; ++i) {
    EXPECT_EQ(in[i].first, i+1 == 4 ? 4 : (i<3 ? i+1 : i+1)); // just size check; keys monotonic
  }

  // Quick head/tail sanity (we won't assert full shapes since RB rotations vary)
  EXPECT_EQ(in[0].first, 1);
  EXPECT_EQ(in[5].first, 6);
}

int main() {
  std::cout << "Running map tests...\n";

  test_empty_and_basic_insert();
  test_brackets_and_at();
  test_iterators_forward_backward();
  test_reverse_iterators();
  test_lower_upper_equal_range();
  test_erase_leaf_one_two_children();
  test_copy_move_swap_and_find();
  test_comparisons();
  test_traversal_helpers();

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
