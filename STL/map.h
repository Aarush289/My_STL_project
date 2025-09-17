#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include <iostream>
#include <utility>
#include <iterator>
#include <vector> // if using std::vector
using std::vector;
#define temp template <typename K, typename V>

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

template <typename K, typename V >
class map {
public:
    class Iterator {
        Node<K,V>* current;
        map<K,V>* owner;
        void advance();
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = std::pair<const K, V>;
        using difference_type   = std::ptrdiff_t;
        using pointer           = value_type*;
        using reference         = value_type&;

        Iterator(Node<K,V>* node = nullptr, map<K,V>* m = nullptr);
        reference operator*() const;
        pointer operator->() const;
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

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
    Node<K,V>* root;
    Node<K,V>* Head;
    size_t node_count;

    void right_rotate(Node<K, V>*& root, Node<K, V>* node);
    void left_rotate(Node<K, V>*& root, Node<K, V>* node);
    void recolor(Node<K, V>*& root, Node<K, V>* node);
    void fix_insert(Node<K, V>*& root, Node<K, V>* node);
    void transplant(Node<K, V>*& root, Node<K, V>*, Node<K, V>*);
    void fixDelete(Node<K, V>*& root, Node<K, V>* node);
    Node<K, V>* minimum(Node<K, V>*) const;
    Node<K, V>* maximum(Node<K, V>*) const;
    Node<K, V>* findNode(const K&) const;
    Node<K, V>* copyTree(const Node<K, V>* node, Node<K, V>* parent);
    void destroy(Node<K, V>*);

public:
    map();
    map(const map& other);
    map& operator=(map other);
    map(map&& other) noexcept;
    ~map();

    Node<K, V>* successor(Node<K, V>* node);                     // for Iterator
    const Node<K, V>* successor(const Node<K, V>* node) const;
    Node<K,V>* predecessor(Node<K, V>* node) ;
    const Node<K,V>* predecessor(Node<K, V>* node) const;

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
    Iterator lower_bound(const K& key);
    Iterator upper_bound(const K& key);
    std::pair<Iterator,Iterator> equal_range(const K& key);

    // Traversal helpers
    void help_inorder(Node<K, V>*, vector<std::pair<K, V> >&);
    void help_Preorder(Node<K, V>*, vector<std::pair<K, V> >&);
    void help_Postorder(Node<K, V>*, vector<std::pair<K, V> >&);
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

#include "map.tpp"
#endif
