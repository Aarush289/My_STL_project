#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Vector.h"     // underlying dynamic array type: vector<T>
#include <functional>   // std::less (default Compare)
#include <utility>      // std::move, std::swap

/**
 * @class priority_queue
 * @brief Minimal std::priority_queue-like adaptor built on top of vector<T>.
 *
 * Invariant (max-heap by default): for all valid parent/child indices i:
 *   !comp_(data[parent], data[child])  // i.e., parent is not "less than" child
 *
 * Layout: implicit binary heap in level-order inside 'data':
 *   parent(i) = (i - 1) / 2, left(i) = 2*i + 1, right(i) = 2*i + 2
 *
 * Complexity:
 *   push / pop: O(log n), top/empty/size: O(1), rebuild_heap: O(n)
 *
 * Notes:
 * - Compare defaults to std::less<T> → max-heap (top() is the largest).
 * - To switch ordering after construction, call set_compare() which rebuilds.
 */
template <class T, class Compare = std::less<T>>
class priority_queue {
private:
    vector<T> data;     ///< underlying container storing the heap in level-order
    Compare   comp_;    ///< comparison functor; comp_(a,b)==true means a<b (by default)

    /**
     * @brief Move element at index 'idx' up the heap until the heap property holds.
     * @param idx index of the newly inserted element (typically size()-1)
     * @post Heap property restored on the path from idx to root.
     */
    void shift_up(size_t idx);

    /**
     * @brief Move element at index 'idx' down the heap until the heap property holds.
     * @param idx index to sift down (typically 0 after pop())
     * @post Heap property restored in the affected subtree.
     */
    void shift_down(size_t idx);

    /**
     * @brief Rebuild heap from arbitrary 'data' in O(n) time (Floyd heapify).
     * @post Entire 'data' satisfies the heap property.
     */
    void rebuild_heap();

public:
    /** @brief Default-construct an empty priority queue with default Compare(). */
    priority_queue();

    /**
     * @brief Construct with a comparator.
     * @param other comparator instance (copied into comp_)
     * @note Signature takes Compare& per your interface; typically const Compare& is preferred.
     */
    priority_queue(Compare& other);

    /** @brief Copy-construct from another priority_queue (copies comparator and data). */
    priority_queue(const priority_queue& other);

    /** @brief Move-construct from another priority_queue; other becomes valid but unspecified. */
    priority_queue(priority_queue&& other) noexcept;

    /** @brief Copy-assign from another priority_queue. */
    priority_queue<T, Compare>& operator=(const priority_queue& other);

    /** @brief Move-assign from another priority_queue; other becomes valid but unspecified. */
    priority_queue<T, Compare>& operator=(priority_queue&& other) noexcept;

    /**
     * @brief Insert a new element by copy and restore heap property.
     * @param key value to insert
     * @post size() increases by 1; top() may change.
     * @complexity O(log n)
     */
    void push(const T& key);

    /**
     * @brief Insert a new element by move and restore heap property.
     * @param key rvalue to insert
     * @post size() increases by 1; top() may change.
     * @complexity O(log n)
     */
    void push(T&& key);

    /**
     * @brief Remove the top element (extreme per Compare).
     * @pre !empty()
     * @post size() decreases by 1; top() changes to next extreme if not empty.
     * @complexity O(log n)
     */
    void pop();

    /**
     * @brief Access the highest-priority element.
     * @pre !empty()
     * @return const reference to data.front() (root of heap)
     * @complexity O(1)
     */
    const T& top() const;

    /** @brief Check whether the container has no elements. @return true if size()==0. */
    bool empty() const;

    /** @brief Number of elements stored. */
    size_t size() const;

    /**
     * @brief Replace the comparator and rebuild the heap to respect the new order.
     * @param comp new comparator to use
     * @post Heap property holds under 'comp'.
     * @complexity O(n) due to rebuild_heap().
     */
    void set_compare(const Compare& comp);
};

#include "./Details/priority_queue.tpp"
#endif
