#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include <iostream>
#include <utility>
#include <iterator>
#include "Vector.h" 

#define temp template <typename K, typename V>

/**
 * @struct Node
 * @brief This struct stores details of a Node (RB-tree Node)
 * including data, parent , left ,right and its own color 
 */
template <typename K, typename V>
struct Node {
    std::pair<const K, V> data;
    bool red;
    Node* left;
    Node* right;
    Node* parent;
    Node(const K& key = K(), const V& value = V())
        : data(key, value), red(true), left(nullptr), right(nullptr), parent(nullptr) {}
};


/**
 * @class map
 * @brief Red-Black Tree based associative container mapping unique keys K -> values V.
 *
 * Properties:
 *  - Unique keys (at most one value per key).
 *  - Ordered by key (in-order traversal is sorted ascending by K).
 *  - Insert/erase/find in O(log n) average/worst case due to RB-tree balancing.
 */

template <typename K, typename V >
class map {
public:
    /**
     * @class Iterator
     * @brief Bidirectional iterator over map elements in key order
     * Maintains pointer to current element and the parent map
     */
    class Iterator {
        Node<K,V>* current;         ///< Current element
        map<K,V>* owner;            ///< Owner map of the Iterator class
        void advance();             ///< Increment the iterator
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = std::pair<const K, V>;
        using difference_type   = std::ptrdiff_t;
        using pointer           = value_type*;
        using reference         = value_type&;

        /// @name Ctor/Increment/Decrement/comparison
        /// @{
        Iterator(Node<K,V>* node = nullptr, map<K,V>* m = nullptr);
        reference operator*() const;
        pointer operator->() const;
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        ///@}
    };

    /**
     * @class ConstIterator
     * @brief constant bidirectional iterator over map elements in key order
     * Maintains pointer to current element and the parent map
     */
    class ConstIterator {
        const Node<K,V>* current;
        const map<K,V>* owner;
        void advance();
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = std::pair<const K, V>;
        using difference_type   = std::ptrdiff_t;
        using pointer           = const value_type*;
        using reference         = const value_type&;

        ConstIterator(const Node<K,V>* node = nullptr, const map<K,V>* m = nullptr);
        reference operator*() const;
        pointer operator->() const;
        ConstIterator& operator++();
        ConstIterator operator++(int);
        ConstIterator& operator--();
        ConstIterator operator--(int);
        bool operator==(const ConstIterator& other) const;
        bool operator!=(const ConstIterator& other) const;
    };

private:
    Node<K,V>* root;    ///< Root of the tree( null when empty)
    Node<K,V>* Head;    ///< sentinel/end marker (used to represent end())
    size_t node_count;  ///< Count of Nodes

    ///@name Core operations
    ///@{
    void right_rotate(Node<K, V>*& root, Node<K, V>* node);     ///< standard RB-tree right rotate
    void left_rotate(Node<K, V>*& root, Node<K, V>* node);      ///< standard RB-tree left rotate
    void recolor(Node<K, V>*& root, Node<K, V>* node);          ///< Recolor needed for fixing up after insertion/deletion
    void fix_insert(Node<K, V>*& root, Node<K, V>* node);       ///< Fix after Insertion ,restore RB-tree properties after insertion
    void transplant(Node<K, V>*& root, Node<K, V>*, Node<K, V>*);   ///< Replace subtree u with 
    void fixDelete(Node<K, V>*& root, Node<K, V>* node);        ///< Restore RB-tree properties after node deletion
    Node<K, V>* minimum(Node<K, V>* u) const;                     ///< Leftmost element in the subtree with root u
    Node<K, V>* maximum(Node<K, V>* u) const;                     ///< Rightmost element in the subtree with root u
    Node<K, V>* findNode(const K&) const;                        ///< Find node with given key
    Node<K, V>* copyTree(const Node<K, V>* node, Node<K, V>* parent);
    void destroy(Node<K, V>*);
    ///@}

public:
    /// @name ctor/dtor/asignment
    ///@{
    map();
    map(const map& other);
    map& operator=(map other);
    map(map&& other) noexcept;
    ~map();
    ///@}

    //-- Successor/Predecessor utilities for Iterator support--//
    Node<K, V>* successor(Node<K, V>* node);                     
    const Node<K, V>* successor(const Node<K, V>* node) const;
    Node<K,V>* predecessor(Node<K, V>* node) ;
    const Node<K,V>* predecessor(const Node<K, V>* node) const;

    bool empty() const;
    size_t size() const;

    // Iterators
    using iterator = Iterator;
    using const_iterator = ConstIterator;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    void swap(map& other) noexcept;
    void swap(map<K, V>& lhs, map<K, V>& rhs) noexcept {
        lhs.swap(rhs);  
    }

    iterator begin() ;
    iterator end()  ;

    const_iterator begin() const ;
    const_iterator end()   const ;

    const_iterator cbegin() const ;
    const_iterator cend()   const ;

    reverse_iterator rbegin() ;
    reverse_iterator rend()   ;

    const_reverse_iterator rbegin() const ;
    const_reverse_iterator rend()   const ;
    const_reverse_iterator crbegin() const ;
    const_reverse_iterator crend()   const ;


    // Modifiers
    void clear();
    std::pair<Node<K, V>*, bool> insert(const K& key, const V& value);
    std::pair<Node<K, V>*, bool> insert(const std::pair<const K, V>& kv);
    void erase(const K& key);

    // Element access
    V& operator[](const K& key);
    V& at(const K& key);
    const V& at(const K& key) const;

    // Lookup
    bool contains(const K& key) const;
    size_t count(const K& key)const;
    Iterator lower_bound(const K& key);                         ///< First Not less than key ( maximum element with key less than given key )
    Iterator upper_bound(const K& key);                         ///< First greater than key ( minimum element with key greater than given key)
    std::pair<Iterator,Iterator> equal_range(const K& key);     ///< returns pair of lower_bound and upper_bound iterators

    // Traversal helpers
    void help_inorder(const Node<K, V>*, vector<std::pair<K, V> >&)const;
    void help_Preorder(const Node<K, V>*, vector<std::pair<K, V> >&)const;
    void help_Postorder(const Node<K, V>*, vector<std::pair<K, V> >&)const;
    vector<std::pair<K, V> > give_InOrder() const;
    vector<std::pair<K, V> > give_Preorder() const;
    vector<std::pair<K, V> > give_Postorder() const;

    // comparison
    bool operator==(const map& other) const;
    bool operator!=(const map& other) const;
    bool operator<(const map& other) const; 
    bool operator>(const map& other) const;
    Iterator find(const K& key); 

};

#include "./Details/map.tpp"
#endif
