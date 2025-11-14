#include <algorithm>
#include <istream>
#include <ostream>
#include <stack>
#include <queue>
template<typename T>
struct BinTree_Node{
    T data;
    BinTree_Node<T>* left_child, *right_child;
    BinTree_Node(){
        left_child = nullptr;
        right_child = nullptr;
    }
    BinTree_Node(T x, BinTree_Node<T>*_left_child = nullptr, BinTree_Node<T>*_right_child = nullptr)
        :data(x), left_child(_left_child), right_child(_right_child){}
};
template<typename T>
class Binary_Tree{
protected:
    BinTree_Node<T>* root; // the tree's root
    T ref_value;    // 数据输入停止标志
    void createbintree(std::istream& in, BinTree_Node<T>* &subtree){    // use string to create a binary tree 
        T item;
        if(!in.eof()){
            in >> item;
            if(item != ref_value){
                BinTree_Node<T>* sub_tree = new BinTree_Node<T>(item);
                createbintree(in, sub_tree->left_child);
                createbintree(in, sub_tree->right_child);
            }
        }
        else subtree = nullptr;
    }
    bool insert(BinTree_Node<T>*& sub_tree, T& x);   // insert a new node
    void destroy(BinTree_Node<T>*& sub_tree){ // destroy a target node and it's son node
        if(sub_tree != nullptr){
            destroy(sub_tree->left_child);
            destroy(sub_tree->right_child);
            delete sub_tree;
        }
        return ;
    }
    bool find(BinTree_Node<T>* sub_tree, T&x); //  find a target node in the sub_tree by it's value
    Binary_Tree<T>* copy(BinTree_Node<T>*r); //copy a tree
    int height(BinTree_Node<T>* sub_tree){
        if(sub_tree != nullptr){
            return 1 + std::max(height(sub_tree->left_child), height(sub_tree->right_child));
        }
        return 0;
    } // return the height of the sub_tree
    int size(BinTree_Node<T>* sub_tree){
        if(sub_tree != nullptr){
            return 1 + size(sub_tree->left_child) + size(sub_tree->right_child);
        }
        return 0;
    } // return the size of the sub_tree
    BinTree_Node<T>* parent(BinTree_Node<T>* sub_tree, BinTree_Node<T>* t){ // return the parent node of target node in the sub_tree
        if(sub_tree == nullptr) return nullptr;
        if(sub_tree->left_child == t || sub_tree->right_child == t) return sub_tree; 
        BinTree_Node<T>* p;
        if((p = parent(sub_tree->left_child, t)) != nullptr) return p;
        else return parent(sub_tree->right_child, t);
    }    
    BinTree_Node<T>* find(BinTree_Node<T>* sub_tree, T & x) const; // findout the node in the sub_tree by it's value
    void traverse(BinTree_Node<T>* sub_tree, std::ostream& out); // to printf the tree by pre_order
    void pre_order(BinTree_Node<T>& sub_tree, void (*visit)(BinTree_Node<T>* t)){ // pre_order to run the tree
        if(sub_tree != nullptr){
            visit(sub_tree);
            pre_order(sub_tree.left_child, visit);
            pre_order(sub_tree.right_child, visit);
        }
        
    }
        void in_order(BinTree_Node<T>& sub_tree, void (*visit)(BinTree_Node<T>* t)){ // in_order to run the tree
        if(sub_tree != nullptr){
            in_order(sub_tree.left_child, visit);
            visit(sub_tree);
            in_order(sub_tree.right_child, visit);
        }
    }
    void post_order(BinTree_Node<T>& sub_tree, void (*visit)(BinTree_Node<T>* t)){ // post_order to run the tree
        if(sub_tree != nullptr){
            post_order(sub_tree.left_child, visit);
            post_order(sub_tree.right_child, visit);
            visit(sub_tree);
        }
    }
    friend std::istream& operator >> (std::istream& in , Binary_Tree<T>& tree); // to overload the input
    friend std::ostream& operator << (std::ostream& out, Binary_Tree<T>& tree); // to overload the output
public:
    Binary_Tree():root(nullptr){} // constructor function
    Binary_Tree(T value):ref_value(value), root(nullptr){}  // constructor function
    Binary_Tree(Binary_Tree<T>&  other);    // copy constructor function
    ~Binary_Tree(){     // delete function
        destroy(root);  
    }
    bool isEmpty() const{   // judge is the tree empty?
        return root == nullptr;     
    }
    int height() const{     // get the height of the tree
        return height(root);
    }
    int size() const{   // get the size of the tree
        return size(root);
    }
    Binary_Tree<T>* parent(BinTree_Node<T>* t) const{      // get the parent node of the target node
        return (root==nullptr || root == t) ? nullptr : parent(root, t);
    }
    Binary_Tree<T>* left_child(BinTree_Node<T>* t) const{  // get the left child of the target node
        return (t != nullptr) ? t->left_child : nullptr;
    }
    Binary_Tree<T>* right_child(BinTree_Node<T>* t) const{     // get the right child of the target node
        return (t != nullptr) ? t->right_child : nullptr;
    }
    BinTree_Node<T>* get_root() const{     // get the tree's root
        return root;
    }
    void pre_order(void (*visit)(BinTree_Node<T>* t)){     // pre_order to run the tree
        // pre_order(root, visit);  // recursion
        std::stack<BinTree_Node<T>*> s;
        BinTree_Node<T> *p = root;
        s.push(nullptr);
        while(p != nullptr){
            visit(p);
            if(p->right_child != nullptr) s.push(p->right_child);
            if(p->left_child != nullptr) p = p->left_child;
            else{
                p = s.top();
                s.pop();
            }
        }
    }
    void in_order(void (*visit)(BinTree_Node<T>* t)){      // in_order to run the tree
        // in_order(root, visit);   // recursion
        std::stack<BinTree_Node<T>*> s;
        BinTree_Node<T>* p = root;
        do{
            while(p != nullptr){
                s.push(p);
                p = p->left_child;
            }
            if(! s.empty()){
                p = s.top();
                s.pop();
                visit(p);
                p = p->right_child;
            }
        }
        while(p != nullptr || !s.empty());
    }
    enum Tag{L, R} tag; 
    struct stk_node{
        BinTree_Node<T>* ptr;
        Tag tag;
        stk_node(BinTree_Node<T>* node = nullptr, Tag _tag = Tag::L):ptr(node), tag(_tag){}
    };
    void post_order(void (*visit)(BinTree_Node<T>* t)){    // post_order to run the tree
        // post_order(root, visit); // recursion
        std::stack<stk_node*> s;
        BinTree_Node<T>* p = root;
        do{
            while(p != nullptr){
                stk_node* new_node = new stk_node(p);
                s.push(new_node);
                p = p->left_child;
            }
            if(! s.empty()){
                stk_node* curr_node = s.top();
                s.pop();
                if(curr_node->tag == Tag::L){
                    stk_node* newnode = new stk_node(curr_node->ptr, Tag::R);
                    s.push(newnode);
                    p = curr_node->ptr->right_child;
                }
                else{
                    p = curr_node->ptr;
                    visit(p);
                    p = nullptr;
                }
                delete curr_node;
            }
        }
        while(p != nullptr || !s.empty());
    }
    void level_order(void *(visit)(BinTree_Node<T>* t)){   // level_order to run the tree
        if(root == nullptr) return;
        std::queue<BinTree_Node<T>*> Q;
        BinTree_Node<T>* p = root;
        visit(p); Q.push(p);
        while(!Q.empty()){
            p = Q.pop();
            if(p->left_child != nullptr){
                visit(p->left_child);
                Q.push(p->left_child);
            }
            if(p->right_child != nullptr){
                visit(p->right_child);
                Q.push(p->right_child);
            }
        }
    }
    int insert(const T item);   // insert a new node to the tree
    BinTree_Node<T>* find(T item) const;   // find a target node by it's value
};