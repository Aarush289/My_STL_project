#pragma once
#include "map.h"
#define temp template <typename K, typename V>


template <typename K, typename V>
map<K,V>::Iterator::Iterator(Node<K,V>* node , map<K,V>* m ){
    current = node;
    owner = m;
}
        

template <typename K, typename V>
void map<K,V>::Iterator::advance(){
      if (current->right) {
        // Go right once, then as left as possible
        current = current->right;
        while (current->left)
            current = current->left;
    } else {
        // Go up until we move from a left child
        Node<K, V>* parent = current->parent;
        while (parent && current == parent->right) {
            current = parent;
            parent = parent->parent;
        }
        current = parent;
    }
    return ;
}

// ======================= successor & predecessor =======================
template <typename K, typename V>
Node<K, V>* map<K, V>::successor(Node<K, V>* node) {
    if (node == nullptr || node == Head) return Head;

    if (node->right) {
        node = node->right;
        while (node->left) node = node->left;
        return node;
    }
    Node<K, V>* parent = node->parent;
    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent ? parent : Head;
}

template <typename K, typename V>
Node<K, V>* map<K, V>::predecessor(Node<K, V>* node) {
    if (node == nullptr) return Head;
    if (node == Head) return Head->right; // Head->right = maximum

    if (node->left) {
        node = node->left;
        while (node->right) node = node->right;
        return node;
    }
    Node<K, V>* parent = node->parent;
    while (parent != nullptr && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent ? parent : Head;
}


template <typename K, typename V>
const Node<K, V>* map<K, V>::predecessor(Node<K, V>* node) const{
    if (!node) return nullptr;

    // Case 1: Left subtree exists -> go to its right-most node
    if (node->left) {
        node = node->left;
        while (node->right) node = node->right;
        return node;
    }

    // Case 2: No left subtree -> go up until we come from right
    const Node<K, V>* parent = node->parent;
    while (parent && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;  // nullptr if no predecessor
}


template <typename K, typename V>
const Node<K, V>* map<K, V>::successor(const Node<K, V>* node) const {
    // same logic as non-const version but using const pointers
    if (node->right != nullptr) {
        node = node->right;
        while (node->left != nullptr) node = node->left;
        return node;
    }
    const Node<K, V>* y = node->parent;
    while (y != nullptr && node == y->right) {
        node = y;
        y = y->parent;
    }
    return y;
}

// ======================= Iterator Implementation =======================
template<typename K, typename V>
typename map<K,V>::ConstIterator::reference 
map<K,V>::ConstIterator::operator*() const {
    return current->data;
}

template<typename K, typename V>
std::pair<Node<K,V>*, bool> insert(const std::pair<const K, V>& kv) {
    return insert(kv.first, kv.second);
}

template <typename K, typename V>
typename map<K, V>::ConstIterator& map<K, V>::ConstIterator::operator++() {
    // If we're already at the maximum node, move to Head (end of the map)
    if (current == owner->maximum(owner->root)) {
        current = owner->Head;
    } else {
        current = owner->successor(current);  // Otherwise, just move to the successor
    }
    return *this;
}

template <typename K, typename V>
typename map<K, V>::ConstIterator::pointer
map<K, V>::ConstIterator::operator->() const {
    return &(current->data);
}

template <typename K, typename V>
typename map<K, V>::Iterator::reference
map<K, V>::Iterator::operator*() const {
    return current->data;
}

template <typename K, typename V>
typename map<K, V>::Iterator::pointer
map<K, V>::Iterator::operator->() const {
    return &(current->data);
}

template <typename K, typename V>
typename map<K, V>::Iterator& map<K, V>::Iterator::operator++() {
    // If we're already at the maximum node, move to Head (end of the map)
    if (current == owner->maximum(owner->root)) {
        current = owner->Head;
    } else {
        current = owner->successor(current);  // Otherwise, just move to the successor
    }
    return *this;
}

template <typename K, typename V>
typename map<K, V>::Iterator
map<K, V>::Iterator::operator++(int) {
    Iterator temp_iterator = *this;
    ++(*this);
    return temp_iterator;
}

template <typename K, typename V>
typename map<K, V>::Iterator& map<K, V>::Iterator::operator--() {
    if (current == owner->Head)                     // end() → last element
        current = owner->Head->right;
    else
        current = owner->predecessor(current);       // move backward
    return *this;
}

template <typename K, typename V>
typename map<K, V>::Iterator
map<K, V>::Iterator::operator--(int) {
    Iterator temp_iterator = *this;
    --(*this);
    return temp_iterator;
}

template <typename K, typename V>
bool map<K, V>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

template <typename K, typename V>
bool map<K, V>::ConstIterator::operator==(const ConstIterator& other) const {
    return current == other.current;
}


template <typename K, typename V>
bool map<K, V>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template <typename K, typename V>
bool map<K, V>::ConstIterator::operator!=(const ConstIterator& other) const {
    return current != other.current;
}

// ======================= map::begin() and map::end() =======================

// Non-const
template <typename K, typename V>
typename map<K, V>::Iterator  map<K, V>::begin() {
    return Iterator(Head->left == Head ? Head : Head->left, this);
}

template <typename K, typename V>
typename map<K, V>::Iterator map<K, V>::end() {
    return Iterator(Head, this);
}

template <typename K, typename V>
typename map<K, V>::ConstIterator map<K, V>::begin() const {
    return const_iterator(Head->left == Head ? Head : Head->left, this);
}

template <typename K, typename V>
typename map<K, V>::ConstIterator map<K, V>::end() const {
    return const_iterator(Head, this);
}

template <typename K, typename V>
typename map<K, V>::ConstIterator map<K, V>::cbegin() const {
    return begin();
}

template <typename K, typename V>
typename map<K, V>::ConstIterator map<K, V>::cend() const {
    return end();
}

// Reverse
template <typename K, typename V>
typename map<K, V>::reverse_iterator map<K, V>::rbegin() {
    return reverse_iterator(end());
}

template <typename K, typename V>
typename map<K, V>::reverse_iterator map<K, V>::rend() {
    return reverse_iterator(begin());
}

template <typename K, typename V>
typename map<K, V>::const_reverse_iterator map<K, V>::rbegin() const {
    return const_reverse_iterator(end());
}

template <typename K, typename V>
typename map<K, V>::const_reverse_iterator map<K, V>::rend() const {
    return const_reverse_iterator(begin());
}

template <typename K, typename V>
typename map<K, V>::const_reverse_iterator map<K, V>::crbegin() const {
    return const_reverse_iterator(cend());
}

template <typename K, typename V>
typename map<K, V>::const_reverse_iterator map<K, V>::crend() const {
    return const_reverse_iterator(cbegin());
}

template <typename K, typename V>
map<K, V>::ConstIterator::ConstIterator(const Node<K, V>* node, const map<K, V>* m) {
    current = node;
    owner = m;
}

template <typename K, typename V>
typename map<K,V>:: Iterator
map<K,V>::find(const K& key) {
    Node<K, V>* node = findNode(key);
    if (!node)
        return end();  // instead of nullptr
    return Iterator(node , this);
}

template <typename K, typename V>
void map<K, V>::right_rotate(Node<K, V> *&root, Node<K, V> *x)
{
    Node<K, V> *y = x->left;

    if (!y) {return;} // Cannot rotate if x has no left child

    x->left = y->right;
    if (y->right)   { y->right->parent = x;}
    y->parent = x->parent;

    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;
    x->parent = y;
}



template <typename K, typename V>
void map<K, V>::left_rotate(Node<K, V> *&root, Node<K, V> *x)
{
    Node<K, V> *y = x->right;
    if (!y)
        return;
    x->right = y->left;
    if (y->left)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (!x->parent)
        root = y;
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->left = x;
    x->parent = y;
}

template <typename K, typename V>
void map<K, V>::recolor(Node<K, V> *&root, Node<K, V> *x)
{
    Node<K, V>* parent = x->parent;
    Node<K, V>* grandparent = parent->parent;
    Node<K, V>* uncle = (parent == grandparent->left) ? grandparent->right : grandparent->left;

    // Rered parent and uncle to false, grandparent to red
    parent->red = false;
    if (uncle)
        uncle->red = false;
    grandparent->red = true;
    root->red = false;
}

template <typename K, typename V>
void map<K, V>::fix_insert(Node<K, V> *&root, Node<K, V> *node)
{
    while (node != root && node->parent->red==true )
    {
        Node<K, V> *parent = node->parent;
        Node<K, V> *grandparent = parent->parent;

        if (parent == grandparent->left)
        {
            Node<K, V> *uncle = grandparent->right;

            if (uncle && uncle->red == true)
            {
                // Case 1: Uncle is red -> Rered
                parent->red = false;
                uncle->red = false;
                grandparent->red = true;
                node = grandparent;
            }
            else
            {
                if (node == parent->right)
                {
                    // Case 2: node is inner child -> rotate to outer
                    left_rotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                // Case 3: Outer child -> rotate grandparent and rered
                parent->red = false;
                grandparent->red = true;
                right_rotate(root, grandparent);
                break;
            }
        }
        else
        {
            // Mirror cases (parent is right child of grandparent)
            Node<K, V> *uncle = grandparent->left;

            if (uncle && uncle->red == true)
            {
                // Case 1: Uncle is red -> Rered
                parent->red = false;
                uncle->red = false;
                grandparent->red = true;
                node = grandparent;
            }
            else
            {
                if (node == parent->left)
                {
                    // Case 2: inner child -> rotate to outer
                    right_rotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                // Case 3: Outer child -> rotate grandparent and rered
                parent->red = false;
                grandparent->red = true;
                left_rotate(root, grandparent);
                break;
            }
        }
    }

    root->red= false; // Ensure root remains false
}

template <typename K, typename V> 
void map<K, V>::transplant(Node<K, V> *&root, Node<K, V> *u, Node<K, V> *v)
{
    if (u->parent == nullptr)
    {
        root = v; // u is the root
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    if (v != nullptr)
    {
        v->parent = u->parent;
    }
}

template <typename K, typename V>
void map<K, V>::fixDelete(Node<K, V> *&root, Node<K, V> *node)
{
    while (node != root && (node == nullptr || node->red == false))
    {
        Node<K, V> *parent = node->parent;

        // Determine if node is a left or right child
        if (node == parent->left)
        {
            Node<K, V> *sibling = parent->right;

            // Case 1: Sibling is red
            if (sibling && sibling->red == true)
            {
                sibling->red = false;
                parent->red = true;
                left_rotate(root, parent);
                sibling = parent->right; // Update sibling after rotation
            }

            // Case 2: Sibling is false with both false children
            if ((sibling->left == nullptr || sibling->left->red == false) &&
                (sibling->right == nullptr || sibling->right->red == false))
            {
                sibling->red = true;
                node = parent;
            }
            else
            {
                // Case 3: Sibling is false, sibling's right child is false, left is red
                if (sibling->right == nullptr || sibling->right->red == false)
                {
                    if (sibling->left)
                        sibling->left->red = false;
                    sibling->red = true;
                    right_rotate(root, sibling);
                    sibling = parent->right; // Update sibling after rotation
                }

                // Case 4: Sibling is false and sibling's right child is red
                sibling->red = parent->red;
                parent->red = false;
                if (sibling->right)
                    sibling->right->red = false;
                left_rotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            // Mirror case: node is right child
            Node<K, V> *sibling = parent->left;

            // Case 1: Sibling is red
            if (sibling && sibling->red == true)
            {
                sibling->red = false;
                parent->red = true;
                right_rotate(root, parent);
                sibling = parent->left;
            }

            // Case 2: Both sibling children are false
            if ((sibling->left == nullptr || sibling->left->red == false) &&
                (sibling->right == nullptr || sibling->right->red == false))
            {
                sibling->red = true;
                node = parent;
            }
            else
            {
                // Case 3: Sibling's left child is false, right is red
                if (sibling->left == nullptr || sibling->left->red == false)
                {
                    if (sibling->right)
                        sibling->right->red = false;
                    sibling->red = true;
                    left_rotate(root, sibling);
                    sibling = parent->left;
                }

                // Case 4: Sibling is false and sibling's left child is red
                sibling->red = parent->red;
                parent->red = false;
                if (sibling->left)
                    sibling->left->red = false;
                right_rotate(root, parent);
                node = root;
                break;
            }
        }
    }

    if (node)
        node->red = false;
}

template <typename K, typename V>
    Node<K, V> *
    map<K, V>::minimum(Node<K, V> *node) const
{
    if (!node->left)
    {
        return node;
    }
    return minimum(node->left);
}

template <typename K, typename V>
    Node<K, V>*
    map<K, V>::maximum(Node<K, V> *node) const
{
    if (!node->right)
    {
        return node;
    }
    return maximum(node->right);
}

template <typename K, typename V>
    Node<K, V> *
    map<K, V>::findNode(const K &key) const
{
    Node<K, V> *node = root;
    while (node != nullptr && node->data.first != key)
    {
        if (node->data.first > key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return node;
}

template <typename K, typename V>
void map<K, V>::destroy(Node<K, V> *node)
{
    if (!node || node == Head) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

template <typename K, typename V>
    Node<K, V> *
    map<K, V>::copyTree(const Node<K, V> *node, Node<K, V> *parent)
{
    if (node == nullptr)
        return nullptr;
    Node<K, V>* newNode = new Node<K, V>(node->data.first, node->data.second);
    newNode->red = node->red;
    newNode->parent = parent;

    newNode->left = copyTree(node->left, newNode);
    newNode->right = copyTree(node->right, newNode);

    return newNode;
}

template <typename K, typename V> 
map<K, V>::map() {
    Head = new Node<K, V>(K(), V());  
    Head->parent = Head;
    Head->left = Head;
    Head->right = Head;
    root = nullptr;
    node_count=0;
}

template <typename K, typename V>
map<K, V>::map(const map &other)
{
    node_count = other.size();
    root = copyTree(other.root, nullptr);
    Head = new Node<K,V>(K(), V());
    Head->parent = root;
    Head->left = (root ? minimum(root) : Head);
    Head->right = (root ? maximum(root) : Head);

}

template <typename K, typename V>
map<K, V>& map<K, V>::operator=(map other) // <-- passed by value (copy)
{
    swap(other);   // exchange our data with the copy
    return *this;  // old data destroyed when other goes out of scope
}


template <typename K, typename V>
    map<K, V>::~map()
{
    destroy(root);
    delete Head;
}

template <typename K, typename V>
bool map<K, V>::empty() const
{
    return node_count == 0;
}

template <typename K, typename V>
    size_t
    map<K, V>::size() const
{
    return node_count;
}

template <typename K, typename V>
void map<K, V>::clear()
{
    destroy(root);
    root = nullptr;
    node_count = 0;
}

template <typename K, typename V>
map<K, V>::map(map&& other) noexcept
    : root(other.root), node_count(other.node_count) ,Head(other.Head)
{
    // Take ownership of other's resources
    other.root = nullptr;
    other.node_count = 0;
    other.Head = NULL;
}

template <typename K, typename V>
void map<K, V>::swap(map& other) noexcept {
    // Swap root pointers
    Node<K, V>* tempRoot = root;
    root = other.root;
    other.root = tempRoot;

    // Swap node counts
    size_t tempCount = node_count;
    node_count = other.node_count;
    other.node_count = tempCount;

   // If you have other members (like sentinel nodes, allocators), swap them similarly:
    Node<K,V>* tempHead = Head;
    Head = other.Head;
    other.Head = tempHead;
}


template <typename K, typename V>
std::pair<Node<K, V> *, bool> map<K, V>::insert(const K &key, const V &value)
{
    Node<K, V> *parent = nullptr;
    Node<K, V> *curr = root;

    while (curr != nullptr)
    {
        if (key == curr->data.first)
        {
            return {curr, false};
        }
        parent = curr;
        curr = (key < curr->data.first) ? curr->left : curr->right;
    }

    Node<K, V> *node = new Node<K, V>(key , value);
    node->left = nullptr;
    node->right = nullptr;
    node->parent = parent;

    if (parent == nullptr)
    {
        root = node;
    }
    else if (key < parent->data.first)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }

    node_count++;
    fix_insert(root , node);
    if (root) {
        Head->left = minimum(root);
        Head->right = maximum(root);
        Head->parent = root;
    } else {
        Head->left = Head;
        Head->right = Head;
        Head->parent = nullptr;
    }
    return {node, true};
}

template <typename K, typename V>
std::pair<Node<K, V>*, bool>
map<K, V>::insert(const std::pair<const K, V>& kv) {
    return insert(kv.first, kv.second);
}


template <typename K, typename V>
void map<K, V>::erase(const K &key)
{
    Node<K, V> *node = root;

    // Step 1: Find node with given key
    while (node != NULL && node->data.first != key)
    {
        if (key < node->data.first)
            node = node->left;
        else
            node = node->right;
    }

    // Key not found
    if (node == NULL)
        return;

    node_count--;

    Node<K, V> *y = node;
    Node<K, V> *x = NULL;
    Node<K, V> *x_parent = NULL;
    bool y_original_red = y->red;

    // Step 2: Node with at most one child
    if (node->left == NULL)
    {
        x = node->right;
        x_parent = node->parent;
        transplant(root, node, node->right);
    }
    else if (node->right == NULL)
    {
        x = node->left;
        x_parent = node->parent;
        transplant(root, node, node->left);
    }
    // Step 3: Node has two children
    else
    {
        y = minimum(node->right); // In-order successor
        y_original_red = y->red;
        x = y->right;

        if (y->parent == node)
        {
            if (x)
                x->parent = y;
            x_parent = y;
        }
        else
        {
            transplant(root, y, y->right);
            y->right = node->right;
            if (y->right)
                y->right->parent = y;
            x_parent = y->parent;
        }

        transplant(root, node, y);
        y->left = node->left;
        if (y->left)
            y->left->parent = y;
        y->red = node->red;
    }

    delete node;

    if (!y_original_red)
    {
        fixDelete(root, x ? x : x_parent); // x might be null
    }
    if (root) {
        Head->left = minimum(root);
        Head->right = maximum(root);
       // Head->parent = root;
    } else {
        Head->left = Head;
        Head->right = Head;
        //Head->parent = nullptr;
    }
}

template <typename K, typename V>
V& map<K, V>::operator[](const K &key)
{
    Node<K, V> *node = root;
    while (node != NULL && node->data.first != key)
    {
        if (node->data.first > key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    if (node == nullptr)
    {
        auto result = insert(key, V());
        return result.first->data.second;
    }
    return node->data.second;
}

template <typename K, typename V>
V& map<K, V>::at(const K &key)
{
    Node<K, V> *node = root;
    while (node != nullptr)
    {
        if (key == node->data.first)
            return node->data.second;

        node = (key < node->data.first) ? node->left : node->right;
    }

    throw std::out_of_range("Key not found in map");
}

template <typename K, typename V>
const V& map<K, V>::at(const K &key) const
{
    Node<K, V> *node = root;
    while (node != nullptr)
    {
        if (key == node->data.first)
            return node->data.second;

        node = (key < node->data.first) ? node->left : node->right;
    }

    throw std::out_of_range("Key not found in map");
}

template <typename K, typename V>
bool map<K, V>::contains(const K &key) const
{
    Node<K, V> *node = root;
    while (node != NULL)
    {
        if (node->data.first == key)
        {
            return true;
        }
        if (node->data.first > key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return false;
}

template <typename K, typename V>
size_t map<K,V> :: count(const K& key) const{
    if(this.contains(key)){return size_t(1);}
    return size_t(0);
}

template <typename K, typename V>
typename map<K, V>::Iterator map<K, V>::lower_bound(const K& key) {
    Node<K, V>* node = root;
    Node<K, V>* candidate = Head;  // Head acts as end()

    while (node) {
        if (node->data.first >= key){ 
            candidate = node;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return Iterator(candidate, this); // If none found, returns end()
}

template <typename K, typename V>
typename map<K, V>::Iterator map<K, V>::upper_bound(const K& key) {
    Node<K, V>* node = root;
    Node<K, V>* candidate = Head;  // Head acts as end()

    while (node) {
        if (node->data.first > key){ 
            candidate = node;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return Iterator(candidate, this); // If none found, returns end()
}

template <typename K, typename V>
std::pair<typename map<K, V>::Iterator, typename map<K, V>::Iterator>
map<K, V>::equal_range(const K& key) {
    return { lower_bound(key), upper_bound(key) };
}


template <typename K, typename V>
void map<K, V>::help_inorder(Node<K, V> *node, vector<std::pair<K, V> > &vec)
{
    if (!node)
    {
        return;
    }
    help_inorder(node->left, vec);
    vec.push_back(node->data);
    help_inorder(node->right, vec);
    return;
}

template <typename K, typename V>
    vector<std::pair< K, V > >
    map<K, V>::give_InOrder() const
{
    vector<std::pair<K, V> > ans;
    help_inorder(root, ans);
    return ans;
}

template <typename K, typename V>
void map<K, V>::help_Preorder(Node<K, V> *node, vector<std::pair<K, V> > &vec)
{
    if (!node)
    {
        return;
    }
    vec.push_back(node->data);
    help_Preorder(node->left, vec);
    help_Preorder(node->right, vec);
    return;
}

template <typename K, typename V>
    vector<std::pair<K, V> >
    map<K, V>::give_Preorder() const
{
    vector<std::pair<K, V> > ans;
    help_Preorder(root, ans);
    return ans;
}

template <typename K, typename V>
void map<K, V>::help_Postorder(Node<K, V> *node, vector<std::pair<K, V> > &vec)
{
    if (!node)
    {
        return;
    }
    
    help_Postorder(node->left, vec);
    help_Postorder(node->right, vec);
    vec.push_back(node->data);
    return;
}

template <typename K, typename V>
    vector<std::pair<K, V> >
    map<K, V>::give_Postorder() const
{
    vector<std::pair<K, V> > ans;
    help_Postorder(root, ans);
    return ans;
}


template <typename K, typename V>
bool map<K,V>:: operator==(const map& other) const{
    if(node_count!=other.node_count){return false;}
    ConstIterator it = begin();
    ConstIterator it2 = other.begin();
    while(it!=end() || it2!=other.end()){
        if(*it != *it2) return false;
        ++it;
        ++it2;
    }
    return true;
}

template <typename K, typename V>
bool map<K,V>:: operator!=(const map& other) const{
    return !(this == other);
}

template <typename K, typename V>
bool map<K, V>::operator<(const map& other) const {
    auto it1 = begin(), it2 = other.begin();
    while (it1 != end() && it2 != other.end()) {
        if (it1->first < it2->first)  
            return true;
        if (it1->first > it2->first)
            return false;

        if (it1->second < it2->second)
            return true;
        if (it1->second > it2->second)
            return false;

        ++it1;
        ++it2;
    }
    return node_count < other.node_count;  
}

template <typename K, typename V>
bool map<K,V>:: operator>(const map& other) const{
    return !(this<other || this == other);
}
