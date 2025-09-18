// tests/test_vector.cpp
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../mystl/Vector.h"

// Alias to avoid confusion with std::vector (your class is ::vector)
template <typename T>
using MyVec = ::vector<T>;

struct Tracer {
    int v;
    static int copies;
    static int moves;
    Tracer(int x = 0) : v(x) {}
    Tracer(const Tracer& o) : v(o.v) { ++copies; }
    Tracer(Tracer&& o) noexcept : v(o.v) { ++moves; }
    Tracer& operator=(const Tracer& o) { v = o.v; ++copies; return *this; }
    Tracer& operator=(Tracer&& o) noexcept { v = o.v; ++moves; return *this; }
    bool operator==(const Tracer& o) const { return v == o.v; }
    bool operator<(const Tracer& o) const { return v < o.v; }
};
int Tracer::copies = 0;
int Tracer::moves = 0;

static void test_default_ctor() {
    MyVec<int> v;
    assert(v.size() == 0);
    assert(v.get_capacity() == 0);
    assert(v.empty());
    std::cout << "default_ctor ok\n";
}

static void test_size_ctor_and_assignment() {
    MyVec<int> v(5);
    assert(v.size() == 5);
    // Values are unspecified in your implementation; assign and check
    for (size_t i = 0; i < v.size(); ++i) v[i] = static_cast<int>(i + 1);
    for (size_t i = 0; i < v.size(); ++i) assert(v[i] == static_cast<int>(i + 1));
    std::cout << "size_ctor_and_assignment ok\n";
}

static void test_size_value_ctor() {
    MyVec<int> v(4, 7);
    assert(v.size() == 4);
    for (size_t i = 0; i < v.size(); ++i) assert(v[i] == 7);
    std::cout << "size_value_ctor ok\n";
}

static void test_init_list_ctor() {
    MyVec<int> v{1,2,3,4};
    assert(v.size() == 4);
    assert(v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4);
    std::cout << "init_list_ctor ok\n";
}

static void test_push_back_and_growth() {
    MyVec<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i * 10);
    assert(v.size() == 10);
    for (int i = 0; i < 10; ++i) assert(v[i] == i * 10);
    assert(v.get_capacity() >= v.size());
    std::cout << "push_back_and_growth ok\n";
}

static void test_front_back_at() {
    MyVec<int> v{11,22,33};
    assert(v.front() == 11);
    assert(v.back() == 33);
    assert(v.at(1) == 22);
    bool threw = false;
    try { (void)v.at(3); } catch (const std::out_of_range&) { threw = true; }
    assert(threw);
    std::cout << "front_back_at ok\n";
}

static void test_reserve_resize_shrink() {
    MyVec<int> v;
    v.reserve(32);
    assert(v.get_capacity() >= 32);
    v.push_back(5);
    v.push_back(6);
    v.resize(6); // your resize fills new slots with 0 for int
    assert(v.size() == 6);
    assert(v[0] == 5 && v[1] == 6);
    for (size_t i = 2; i < 6; ++i) assert(v[i] == 0);
    v.resize(2);
    assert(v.size() == 2);
    v.shrink_to_fit();
    assert(v.get_capacity() == v.size());
    std::cout << "reserve_resize_shrink ok\n";
}

static void test_insert_erase_pop_clear() {
    MyVec<int> v{1,3,5};
    v.insert(1, 2); // 1,2,3,5
    assert(v.size() == 4);
    assert(v[0]==1 && v[1]==2 && v[2]==3 && v[3]==5);
    v.insert(4, 6); // 1,2,3,5,6
    assert(v[4]==6);
    v.erase(3); // 1,2,3,6
    assert(v.size()==4);
    assert(v[0]==1 && v[1]==2 && v[2]==3 && v[3]==6);
    v.pop_back(); // 1,2,3
    assert(v.size()==3 && v.back()==3);
    size_t cap = v.get_capacity();
    v.clear();
    assert(v.size()==0);
    assert(v.get_capacity()==cap); // clear keeps capacity
    std::cout << "insert_erase_pop_clear ok\n";
}

static void test_data_iter_like() {
    MyVec<int> v{10,20,30};
    int sum = 0;
    for (const int* it = v.begin(); it != v.end(); ++it) sum += *it;
    assert(sum == 60);
    std::cout << "data_iter_like ok\n";
}

static void test_relops() {
    MyVec<int> a{1,2,3};
    MyVec<int> b{1,2,3};
    MyVec<int> c{1,2,4};
    assert(a == b);
    assert(a != c);
    assert(a < c);
    assert(c > a);
    std::cout << "relops ok\n";
}

static void test_swap() {
    MyVec<int> a{1,2};
    MyVec<int> b{9};
    a.swap(b);
    assert(a.size()==1 && a[0]==9);
    assert(b.size()==2 && b[0]==1 && b[1]==2);
    std::cout << "swap ok\n";
}

static void test_rotate() {
    MyVec<int> v{1,2,3,4,5};
    v.left_rotate(2);  // 3,4,5,1,2
    assert(v[0]==3 && v[1]==4 && v[2]==5 && v[3]==1 && v[4]==2);
    v.right_rotate(1); // 2,3,4,5,1
    assert(v[0]==2 && v[1]==3 && v[2]==4 && v[3]==5 && v[4]==1);
    std::cout << "rotate ok\n";
}

static void test_slice() {
    MyVec<int> v{10,20,30,40,50};
    auto s = v.slice(1,3); // 20,30,40
    assert(s.size()==3 && s[0]==20 && s[1]==30 && s[2]==40);
    bool threw = false;
    try { (void)v.slice(3, 10); } catch (const std::out_of_range&) { threw = true; }
    assert(threw);
    std::cout << "slice ok\n";
}

static void test_copy_move_semantics() {
    Tracer::copies = Tracer::moves = 0;

    MyVec<Tracer> v;
    v.push_back(Tracer{1});          // move or copy depending on growth
    v.push_back(Tracer{2});
    v.push_back(Tracer{3});
    MyVec<Tracer> cpy = v;           // copy ctor
    MyVec<Tracer> mv  = std::move(v);// move ctor
    assert(mv.size() == 3);
    assert(cpy.size() == 3);
    assert(v.size() == 0);           // moved-from should be empty by your impl

    MyVec<Tracer> assign;
    assign = cpy;                    // copy assign
    MyVec<Tracer> moveAssign;
    moveAssign = std::move(assign);  // move assign
    assert(moveAssign.size() == cpy.size());

    // We won't assert exact copy/move counts because your implementation copies/moves
    // via reallocation steps; but we ensure no crashes and invariants hold.
    std::cout << "copy_move_semantics ok (copies=" << Tracer::copies
              << ", moves=" << Tracer::moves << ")\n";
}

static void test_exceptions() {
    MyVec<int> v;
    bool threw = false;
    try { v.pop_back(); } catch (const std::underflow_error&) { threw = true; }
    assert(threw);

    threw = false;
    try { (void)v.front(); } catch (const std::underflow_error&) { threw = true; }
    assert(threw);

    threw = false;
    try { (void)v.back(); } catch (const std::underflow_error&) { threw = true; }
    assert(threw);

    threw = false;
    try { v.insert(1, 42); } catch (const std::out_of_range&) { threw = true; }
    assert(threw);

    threw = false;
    try { v.erase(0); } catch (const std::out_of_range&) { threw = true; }
    assert(threw);

    std::cout << "exceptions ok\n";
}

int main() {
    std::cout << "Running vector tests...\n";

    test_default_ctor();
    test_size_ctor_and_assignment();
    test_size_value_ctor();
    test_init_list_ctor();
    test_push_back_and_growth();
    test_front_back_at();
    test_reserve_resize_shrink();
    test_insert_erase_pop_clear();
    test_data_iter_like();
    test_relops();
    test_swap();
    test_rotate();
    test_slice();
    test_copy_move_semantics();
    test_exceptions();

    std::cout << "All vector tests passed ✅\n";
    return 0;
}
