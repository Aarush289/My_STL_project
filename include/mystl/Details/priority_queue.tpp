#pragma once
#include "../priority_queue.h"

/**
 * sift the element at index `idx` UP the heap until the heap property holds.
 * For a max-heap with Compare = std::less<T>, we bubble up while parent < child.
 * Complexity: O(log n)
 */
template<class T, class Compare>
void priority_queue<T, Compare>::shift_up(size_t idx) {
    while (idx > 0) {
        size_t parent = (idx - 1) / 2;
        // If parent is NOT "less than" child, heap property holds => stop.
        if (!comp_(data[parent], data[idx])) break;
        std::swap(data[idx], data[parent]);
        idx = parent;
    }
}

/**
 * sift the element at index `idx` DOWN the heap until the heap property holds.
 * Picks the better (higher-priority) child and swaps if needed.
 * Complexity: O(log n)
 */
template<class T, class Compare>
void priority_queue<T, Compare>::shift_down(size_t idx) {
    size_t n = data.size();
    while (true) {
        size_t left  = 2 * idx + 1;
        size_t right = 2 * idx + 2;
        size_t best  = idx;

        // If child has higher priority than current "best", choose that child
        if (left  < n && comp_(data[best], data[left]))   best = left;
        if (right < n && comp_(data[best], data[right]))  best = right;

        // Already satisfies heap property
        if (best == idx) break;

        std::swap(data[best], data[idx]);
        idx = best;
    }
}

/**
 * Rebuild heap from arbitrary array state (Floyd heapify).
 * Complexity: O(n)
 */
template<class T, class Compare>
void priority_queue<T, Compare>::rebuild_heap() {
    if (data.empty()) return;
    for (size_t i = (data.size() - 1) / 2 + 1; i-- > 0; ) {
        shift_down(i);
        if (i == 0) break; // prevent size_t wrap-around
    }
}

/** Default-construct empty heap with default Compare(). */
template<class T, class Compare>
priority_queue<T, Compare>::priority_queue() : data(), comp_() {}

/**
 * Construct with comparator.
 * NOTE: typically you'd take `const Compare&` instead of `Compare&`.
 */
template<class T, class Compare>
priority_queue<T, Compare>::priority_queue(Compare& other) : data(), comp_(other) {}

/** Copy-construct: copy data and comparator. */
template<class T, class Compare>
priority_queue<T, Compare>::priority_queue(const priority_queue& other) {
    data = other.data;
    comp_ = other.comp_;
}

/** Move-construct: steal data; comparator copied (could also std::move(comp_) if desired). */
template<class T, class Compare>
priority_queue<T, Compare>::priority_queue(priority_queue&& other) noexcept {
    data = std::move(other.data);
    comp_ = other.comp_;
}

/** Copy-assign: copy data and comparator; self-assign safe. */
template<class T, class Compare>
priority_queue<T, Compare>& priority_queue<T, Compare>::operator=(const priority_queue& other) {
    if (this != &other) {
        data = other.data;
        comp_ = other.comp_;
    }
    return *this;
}

/** Move-assign: move data and comparator; self-assign safe. */
template<class T, class Compare>
priority_queue<T, Compare>& priority_queue<T, Compare>::operator=(priority_queue&& other) noexcept {
    if (this != &other) {
        data  = std::move(other.data);
        comp_ = std::move(other.comp_);
    }
    return *this;
}

/**
 * Insert by copy; restore heap property by sifting up from last element.
 * Complexity: O(log n)
 */
template<class T, class Compare>
void priority_queue<T, Compare>::push(const T& key) {
    data.push_back(key);
    shift_up(data.size() - 1);
}

/**
 * Insert by move; restore heap property by sifting up from last element.
 * Complexity: O(log n)
 */
template<class T, class Compare>
void priority_queue<T, Compare>::push(T&& key) {
    data.push_back(std::move(key));
    shift_up(data.size() - 1);
}

/**
 * Remove highest-priority element.
 * Precondition: !empty()
 * Steps: swap root with tail, pop tail, then sift new root down.
 * Complexity: O(log n)
 */
template<class T, class Compare>
void priority_queue<T, Compare>::pop() {
    std::swap(data[0], data[data.size() - 1]);
    data.pop_back();
    if (!data.empty()) shift_down(0); // guard for size()==0 after pop
}

/**
 * Access highest-priority element.
 * Precondition: !empty()
 * Complexity: O(1)
 */
template<class T, class Compare>
const T& priority_queue<T, Compare>::top() const {
    return data[0];
}

/** True iff the heap has no elements. */
template<class T, class Compare>
bool priority_queue<T, Compare>::empty() const {
    return data.empty();
}

/** Number of elements. */
template<class T, class Compare>
size_t priority_queue<T, Compare>::size() const {
    return data.size();
}

/**
 * Replace comparator.
 */
template<class T, class Compare>
void priority_queue<T, Compare>::set_compare(const Compare& comp) {
    comp_ = comp;
    rebuild_heap();
}
