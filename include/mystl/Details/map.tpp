#pragma once
#include "../map.h"

#define temp template <typename K, typename V>

// ======================= Iterator (non-const) =======================

temp
map<K,V>::Iterator::Iterator(Node<K,V>* node , map<K,V>* m ){
    current = node;     // current node the iterator points to
    owner   = m;        // owning container (needed for Head, successor, etc.)
}

temp
void map<K,V>::Iterator::advance(){
    // In-order successor from 'current'
    if (current->right) {
        // Go right once, then far-left
        current = current->right;
        while (current->left) current = current->left;
    } else {
        // Go up until we move up from a left child
        Node<K, V>* parent = current->parent;
        while (parent && current == parent->right) {
            current = parent;
            parent = parent->parent;
        }
        current = parent; // may become nullptr (or Head in this design)
    }
    return;
}

// ======================= successor & predecessor (non-const) =======================

temp
Node<K, V>* map<K, V>::successor(Node<K, V>* node) {
    if (node == nullptr || node == Head) return Head;

    // If right subtree exists, successor is the leftmost in right subtree
    if (node->right) {
        node = node->right;
        while (node->left) node = node->left;
        return node;
    }
    // Else climb until we come from the left
    Node<K, V>* parent = node->parent;
    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent ? parent : Head; // Head serves as end()
}

temp
Node<K, V>* map<K, V>::predecessor(Node<K, V>* node) {
    if (node == nullptr) return Head;
    if (node == Head)    return Head->right; // Head->right points to maximum

    // If left subtree exists, predecessor is rightmost in left subtree
    if (node->left) {
        node = node->left;
        while (node->right) node = node->right;
        return node;
    }
    // Else climb until we come from the right
    Node<K, V>* parent = node->parent;
    while (parent != nullptr && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent ? parent : Head;
}

// ======================= successor & predecessor (const) =======================

temp
const Node<K, V>* map<K, V>::predecessor(const Node<K, V>* node) const {
    if (!node) return nullptr;

    if (node->left) {
        node = node->left;
        while (node->right) node = node->right;
        return node;
    }

    const Node<K, V>* parent = node->parent;
    while (parent && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }
    return parent;  // nullptr if none
}

temp
const Node<K, V>* map<K, V>::successor(const Node<K, V>* node) const {
    // In-order successor (const version)
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
    return y; // nullptr if none
}

// ======================= ConstIterator helpers =======================

temp
void map<K,V>::ConstIterator::advance(){
    // Same as Iterator::advance but for const pointers
    if (current->right) {
        current = current->right;
        while (current->left) current = current->left;
    } else {
        Node<K, V>* parent = current->parent;
        while (parent && current == parent->right) {
            current = parent;
            parent = parent->parent;
        }
        current = parent;
    }
    return;
}

temp
typename map<K,V>::ConstIterator::reference 
map<K,V>::ConstIterator::operator*() const {
    return current->data;
}

template<typename K, typename V>
std::pair<Node<K,V>*, bool> map<K,V>::insert(const std::pair<const K, V>& kv) {
    return insert(kv.first, kv.second);
}

temp
typename map<K, V>::ConstIterator& map<K, V>::ConstIterator::operator++() {
    // If at maximum, ++ => end() (Head)
    if (current == owner->maximum(owner->root)) {
        current = owner->Head;
    } else {
        current = owner->successor(current);
    }
    return *this;
}

temp
typename map<K, V>::ConstIterator
map<K, V>::ConstIterator::operator++(int) {
    ConstIterator tmp = *this;
    ++(*this);
    return tmp;
}

temp
typename map<K, V>::ConstIterator& map<K, V>::ConstIterator::operator--() {
    if (current == owner->Head)         // end()-- => last element
        current = owner->Head->right;   // Head->right points to maximum
    else
        current = owner->predecessor(current);
    return *this;
}

temp
typename map<K, V>::ConstIterator
map<K, V>::ConstIterator::operator--(int) {
    ConstIterator tmp = *this;
    --(*this);
    return tmp;
}

temp
typename map<K, V>::ConstIterator::pointer
map<K, V>::ConstIterator::operator->() const {
    return &(current->data);
}

// ======================= Iterator core ops =======================

temp
typename map<K, V>::Iterator::reference
map<K, V>::Iterator::operator*() const {
    return current->data;
}

temp
typename map<K, V>::Iterator::pointer
map<K, V>::Iterator::operator->() const {
    return &(current->data);
}

temp
typename map<K, V>::Iterator& map<K, V>::Iterator::operator++() {
    if (current == owner->maximum(owner->root)) {
        current = owner->Head;
    } else {
        current = owner->successor(current);
    }
    return *this;
}

temp
typename map<K, V>::Iterator
map<K, V>::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

temp
typename map<K, V>::Iterator& map<K, V>::Iterator::operator--() {
    if (current == owner->Head)
        current = owner->Head->right;
    else
        current = owner->predecessor(current);
    return *this;
}

temp
typename map<K, V>::Iterator
map<K, V>::Iterator::operator--(int) {
    Iterator tmp = *this;
    --(*this);
    return tmp;
}

temp
bool map<K, V>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

temp
bool map<K, V>::ConstIterator::operator==(const ConstIterator& other) const {
    return current == other.current;
}

temp
bool map<K, V>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

temp
bool map<K, V>::ConstIterator::operator!=(const ConstIterator& other) const {
    return current != other.current;
}

// ======================= begin()/end() (and const/CBegin/CEnd) =======================

temp
typename map<K, V>::Iterator  map<K, V>::begin() {
    // Head->left is kept as minimum(root); if empty, Head->left == Head
    return Iterator(Head->left == Head ? Head : Head->left, this);
}

temp
typename map<K, V>::Iterator map<K, V>::end() {
    return Iterator(Head, this); // Head is the past-the-end sentinel
}

temp
typename map<K, V>::ConstIterator map<K, V>::begin() const {
    return ConstIterator(Head->left == Head ? Head : Head->left, this);
}

temp
typename map<K, V>::ConstIterator map<K, V>::end() const {
    return ConstIterator(Head, this);
}

temp
typename map<K, V>::ConstIterator map<K, V>::cbegin() const {
    return begin();
}

temp
typename map<K, V>::ConstIterator map<K, V>::cend() const {
    return end();
}

// ======================= reverse iterators =======================

temp
typename map<K, V>::reverse_iterator map<K, V>::rbegin() {
    return reverse_iterator(end());
}

temp
typename map<K, V>::reverse_iterator map<K, V>::rend() {
    return reverse_iterator(begin());
}

temp
typename map<K, V>::const_reverse_iterator map<K, V>::rbegin() const {
    return const_reverse_iterator(end());
}

temp
typename map<K, V>::const_reverse_iterator map<K, V>::rend() const {
    return const_reverse_iterator(begin());
}

temp
typename map<K, V>::const_reverse_iterator map<K, V>::crbegin() const {
    return const_reverse_iterator(cend());
}

temp
typename map<K, V>::const_reverse_iterator map<K, V>::crend() const {
    return const_reverse_iterator(cbegin());
}

// ======================= ConstIterator ctor =======================

temp
map<K, V>::ConstIterator::ConstIterator(const Node<K, V>* node, const map<K, V>* m) {
    current = node;
    owner   = m;
}

// ======================= find() =======================

temp
typename map<K,V>::Iterator
map<K,V>::find(const K& key) {
    Node<K, V>* node = findNode(key);
    if (!node) return end();
    return Iterator(node, this);
}

// ======================= Rotations =======================

temp
void map<K, V>::right_rotate(Node<K, V> *&root, Node<K, V> *x)
{
    Node<K, V> *y = x->left;
    if (!y) return; // cannot rotate without left child

    x->left = y->right;
    if (y->right) y->right->parent = x;

    y->parent = x->parent;

    if (!x->parent)         root = y;
    else if (x == x->parent->left)  x->parent->left  = y;
    else                              x->parent->right = y;

    y->right = x;
    x->parent = y;
}

temp
void map<K, V>::left_rotate(Node<K, V> *&root, Node<K, V> *x)
{
    Node<K, V> *y = x->right;
    if (!y) return;

    x->right = y->left;
    if (y->left) y->left->parent = x;

    y->parent = x->parent;

    if (!x->parent)          root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else                               x->parent->left  = y;

    y->left = x;
    x->parent = y;
}

// ======================= Recolor / Fix-up (Insert) =======================

temp
void map<K, V>::recolor(Node<K, V> *&root, Node<K, V> *x)
{
    // Simple recolor helper (used in some insert cases)
    Node<K, V>* parent      = x->parent;
    Node<K, V>* grandparent = parent->parent;
    Node<K, V>* uncle       = (parent == grandparent->left) ? grandparent->right : grandparent->left;

    parent->red = false;
    if (uncle) uncle->red = false;
    grandparent->red = true;
    root->red = false; // root stays black
}

temp
void map<K, V>::fix_insert(Node<K, V> *&root, Node<K, V> *node)
{
    // Standard RB-tree insertion fix-up
    while (node != root && node->parent->red == true) {
        Node<K, V> *parent      = node->parent;
        Node<K, V> *grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node<K, V> *uncle = grandparent->right;

            if (uncle && uncle->red == true) {
                // Case 1: red uncle -> recolor and continue
                parent->red = false;
                uncle->red  = false;
                grandparent->red = true;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    // Case 2: inner child -> rotate to outer
                    left_rotate(root, parent);
                    node   = parent;
                    parent = node->parent;
                }
                // Case 3: outer -> rotate grandparent
                parent->red = false;
                grandparent->red = true;
                right_rotate(root, grandparent);
                break;
            }
        } else {
            // Mirror cases
            Node<K, V> *uncle = grandparent->left;

            if (uncle && uncle->red == true) {
                parent->red = false;
                uncle->red  = false;
                grandparent->red = true;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    right_rotate(root, parent);
                    node   = parent;
                    parent = node->parent;
                }
                parent->red = false;
                grandparent->red = true;
                left_rotate(root, grandparent);
                break;
            }
        }
    }
    root->red = false; // ensure root black
}

// ======================= transplant (erase helper) =======================

temp
void map<K, V>::transplant(Node<K, V> *&root, Node<K, V> *u, Node<K, V> *v)
{
    if (u->parent == nullptr)           root = v;
    else if (u == u->parent->left)      u->parent->left  = v;
    else                                 u->parent->right = v;

    if (v != nullptr) v->parent = u->parent;
}

// ======================= Fix-up (Delete) =======================

temp
void map<K, V>::fixDelete(Node<K, V> *&root, Node<K, V> *node)
{
    // RB-tree delete fix-up (node may be the moved-up child or nullptr)
    while (node != root && (node == nullptr || node->red == false)) {
        Node<K, V> *parent = node->parent;  

        if (node == parent->left) {
            Node<K, V> *sibling = parent->right;

            if (sibling && sibling->red == true) {
                sibling->red = false;
                parent->red  = true;
                left_rotate(root, parent);
                sibling = parent->right;
            }

            if ((sibling->left == nullptr  || sibling->left->red  == false) &&
                (sibling->right == nullptr || sibling->right->red == false)) {
                sibling->red = true;
                node = parent;
            } else {
                if (sibling->right == nullptr || sibling->right->red == false) {
                    if (sibling->left) sibling->left->red = false;
                    sibling->red = true;
                    right_rotate(root, sibling);
                    sibling = parent->right;
                }

                sibling->red = parent->red;
                parent->red  = false;
                if (sibling->right) sibling->right->red = false;
                left_rotate(root, parent);
                node = root;
                break;
            }
        } else {
            // Mirror branch
            Node<K, V> *sibling = parent->left;

            if (sibling && sibling->red == true) {
                sibling->red = false;
                parent->red  = true;
                right_rotate(root, parent);
                sibling = parent->left;
            }

            if ((sibling->left == nullptr  || sibling->left->red  == false) &&
                (sibling->right == nullptr || sibling->right->red == false)) {
                sibling->red = true;
                node = parent;
            } else {
                if (sibling->left == nullptr || sibling->left->red == false) {
                    if (sibling->right) sibling->right->red = false;
                    sibling->red = true;
                    left_rotate(root, sibling);
                    sibling = parent->left;
                }

                sibling->red = parent->red;
                parent->red  = false;
                if (sibling->left) sibling->left->red = false;
                right_rotate(root, parent);
                node = root;
                break;
            }
        }
    }
    if (node) node->red = false;
}

// ======================= Min / Max =======================

temp
Node<K, V>* map<K, V>::minimum(Node<K, V> *node) const
{
    if (!node->left) return node;
    return minimum(node->left);
}

temp
Node<K, V>* map<K, V>::maximum(Node<K, V> *node) const
{
    if (!node->right) return node;
    return maximum(node->right);
}

// ======================= Raw find (node*) =======================

temp
Node<K, V>* map<K, V>::findNode(const K &key) const
{
    Node<K, V> *node = root;
    while (node != nullptr && node->data.first != key) {
        node = (node->data.first > key) ? node->left : node->right;
    }
    return node;
}

// ======================= Destroy / Copy =======================

temp
void map<K, V>::destroy(Node<K, V> *node)
{
    if (!node || node == Head) return;  // don’t delete sentinel
    destroy(node->left);
    destroy(node->right);
    delete node;
}

temp
Node<K, V>* map<K, V>::copyTree(const Node<K, V> *node, Node<K, V> *parent)
{
    if (node == nullptr) return nullptr;

    Node<K, V>* newNode = new Node<K, V>(node->data.first, node->data.second);
    newNode->red    = node->red;
    newNode->parent = parent;

    newNode->left  = copyTree(node->left,  newNode);
    newNode->right = copyTree(node->right, newNode);
    return newNode;
}

// ======================= Ctors / Dtor / Assign / Swap =======================

temp 
map<K, V>::map() {
    // Create Head sentinel; Head->left=min, Head->right=max, Head->parent=root
    Head = new Node<K, V>(K(), V());
    Head->parent = Head;
    Head->left   = Head;
    Head->right  = Head;
    root = nullptr;
    node_count = 0;
}

temp
map<K, V>::map(const map &other)
{
    node_count = other.size();
    root = copyTree(other.root, nullptr);
    Head = new Node<K,V>(K(), V());
    Head->parent = root;
    Head->left   = (root ? minimum(root) : Head);
    Head->right  = (root ? maximum(root) : Head);
}

temp
map<K, V>& map<K, V>::operator=(map other) // copy-and-swap
{
    swap(other);
    return *this;
}

temp
map<K, V>::~map()
{
    destroy(root);
    delete Head;
}

temp
bool map<K, V>::empty() const { return node_count == 0; }

temp
size_t map<K, V>::size() const { return node_count; }

temp
void map<K, V>::clear()
{
    destroy(root);
    root = nullptr;
    node_count = 0;
    // Consider resetting Head->left/right to Head as well
}

temp
map<K, V>::map(map&& other) noexcept
    : root(other.root),  Head(other.Head) ,node_count(other.node_count)
{
    other.root = nullptr;
    other.Head = NULL; 
    other.node_count = 0;
}

temp
void map<K, V>::swap(map& other) noexcept {
    std::swap(root, other.root);
    std::swap(node_count, other.node_count);
    std::swap(Head, other.Head);
}

// ======================= insert / erase =======================

temp
std::pair<Node<K, V> *, bool> map<K, V>::insert(const K &key, const V &value)
{
    Node<K, V> *parent = nullptr;
    Node<K, V> *curr   = root;

    // BST insert search
    while (curr != nullptr) {
        if (key == curr->data.first) return {curr, false};
        parent = curr;
        curr = (key < curr->data.first) ? curr->left : curr->right;
    }

    // Create new red node
    Node<K, V> *node = new Node<K, V>(key , value);
    node->left = node->right = nullptr;
    node->parent = parent;

    if (parent == nullptr)          root = node;
    else if (key < parent->data.first) parent->left  = node;
    else                               parent->right = node;

    node_count++;
    fix_insert(root , node);   // restore RB invariants

    // Update Head sentinels (min/max)
    if (root) {
        Head->left   = minimum(root);
        Head->right  = maximum(root);
        Head->parent = root;
    } else {
        Head->left = Head->right = Head;
        Head->parent = nullptr;
    }
    return {node, true};
}

temp
void map<K, V>::erase(const K &key)
{
    Node<K, V> *node = root;

    // Find by key
    while (node != NULL && node->data.first != key) {
        node = (key < node->data.first) ? node->left : node->right;
    }
    if (node == NULL) return; // not found

    node_count--;

    Node<K, V> *y = node;
    Node<K, V> *x = NULL;
    Node<K, V> *x_parent = NULL;
    bool y_original_red = y->red;

    if (node->left == NULL) {
        x = node->right;
        x_parent = node->parent;
        transplant(root, node, node->right);
    }
    else if (node->right == NULL) {
        x = node->left;
        x_parent = node->parent;
        transplant(root, node, node->left);
    }
    else {
        // Two children: use successor
        y = minimum(node->right);
        y_original_red = y->red;
        x = y->right;

        if (y->parent == node) {
            if (x) x->parent = y;
            x_parent = y;
        } else {
            transplant(root, y, y->right);
            y->right = node->right;
            if (y->right) y->right->parent = y;
            x_parent = y->parent;
        }

        transplant(root, node, y);
        y->left = node->left;
        if (y->left) y->left->parent = y;
        y->red = node->red;
    }

    delete node;

    if (!y_original_red) {
        // x can be null; caller passes x or x_parent to avoid deref null inside fixDelete
        fixDelete(root, x ? x : x_parent);
    }

    // Update Head sentinels
    if (root) {
        Head->left  = minimum(root);
        Head->right = maximum(root);
        // Head->parent = root; // optionally keep this consistent
    } else {
        Head->left = Head->right = Head;
        // Head->parent = nullptr;
    }
}

// ======================= Element access =======================

temp
V& map<K, V>::operator[](const K &key)
{
    // Find node
    Node<K, V> *node = root;
    while (node != NULL && node->data.first != key) {
        node = (node->data.first > key) ? node->left : node->right;
    }
    // Insert default if absent
    if (node == nullptr) {
        auto result = insert(key, V{});
        return result.first->data.second;
    }
    return node->data.second;
}

temp
V& map<K, V>::at(const K &key)
{
    Node<K, V> *node = root;
    while (node != nullptr) {
        if (key == node->data.first) return node->data.second;
        node = (key < node->data.first) ? node->left : node->right;
    }
    throw std::out_of_range("Key not found in map");
}

temp
const V& map<K, V>::at(const K &key) const
{
   
    const Node<K, V> *node = root;
    while (node != nullptr) {
        if (key == node->data.first) return node->data.second;
        node = (key < node->data.first) ? node->left : node->right;
    }
    throw std::out_of_range("Key not found in map");
}

// ======================= Lookup helpers =======================

temp
bool map<K, V>::contains(const K &key) const
{
    Node<K, V> *node = root;
    while (node != NULL) {
        if (node->data.first == key) return true;
        node = (node->data.first > key) ? node->left : node->right;
    }
    return false;
}

temp
size_t map<K,V>::count(const K& key) const {
    if (this->contains(key)) return size_t(1);
    return size_t(0);
}

temp
typename map<K, V>::Iterator map<K, V>::lower_bound(const K& key) {
    Node<K, V>* node = root;
    Node<K, V>* candidate = Head;  // default end()

    while (node) {
        if (node->data.first >= key){ 
            candidate = node;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return Iterator(candidate, this);
}

temp
typename map<K, V>::Iterator map<K, V>::upper_bound(const K& key) {
    Node<K, V>* node = root;
    Node<K, V>* candidate = Head;

    while (node) {
        if (node->data.first > key){ 
            candidate = node;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return Iterator(candidate, this);
}

temp
std::pair<typename map<K, V>::Iterator, typename map<K, V>::Iterator>
map<K, V>::equal_range(const K& key) {
    return { lower_bound(key), upper_bound(key) };
}

// ======================= Traversal helpers (to vectors) =======================

temp
void map<K, V>::help_inorder(const Node<K, V> *node, vector<std::pair<K, V> > &vec)const
{
    if (!node) return;
    help_inorder(node->left, vec);
    vec.push_back(node->data); // pair<const K,V> decays to pair<K,V> copy
    help_inorder(node->right, vec);
}

temp
vector<std::pair< K, V > >
map<K, V>::give_InOrder() const
{
    vector<std::pair<K, V> > ans;
    help_inorder(root, ans);
    return ans;
}

temp
void map<K, V>::help_Preorder(const Node<K, V> *node, vector<std::pair<K, V> > &vec)const
{
    if (!node) return;
    vec.push_back(node->data);
    help_Preorder(node->left, vec);
    help_Preorder(node->right, vec);
}

temp
vector<std::pair<K, V> >
map<K, V>::give_Preorder() const
{
    vector<std::pair<K, V> > ans;
    help_Preorder(root, ans);
    return ans;
}

temp
void map<K, V>::help_Postorder(const Node<K, V> *node, vector<std::pair<K, V> > &vec)const
{
    if (!node) return;
    help_Postorder(node->left, vec);
    help_Postorder(node->right, vec);
    vec.push_back(node->data);
}

temp
vector<std::pair<K, V> >
map<K, V>::give_Postorder() const
{
    vector<std::pair<K, V> > ans;
    help_Postorder(root, ans);
    return ans;
}

// ======================= Comparisons =======================

temp
bool map<K,V>::operator==(const map& other) const {
    if (node_count != other.node_count) return false;
    ConstIterator it  = begin();
    ConstIterator it2 = other.begin();
    while (it != end() && it2 != other.end()) {
        if (*it != *it2) return false; // pair equality
        ++it; ++it2;
    }
    return it == end() && it2 == other.end();
}

temp
bool map<K,V>::operator!=(const map& other) const {
    return !(*this == other);
}

temp
bool map<K, V>::operator<(const map& other) const {
    // Lexicographic compare on (key,value) pairs in order
    auto it1 = begin(), it2 = other.begin();
    while (it1 != end() && it2 != other.end()) {
        if (it1->first < it2->first)  return true;
        if (it1->first > it2->first)  return false;

        if (it1->second < it2->second) return true;
        if (it1->second > it2->second) return false;

        ++it1; ++it2;
    }
    return node_count < other.node_count;
}

temp
bool map<K,V>::operator>(const map& other) const {
    return !( (*this < other) || (*this == other) );
}
