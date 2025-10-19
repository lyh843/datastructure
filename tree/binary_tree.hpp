#include <istream>
#include <optional>
template<typename T>
struct BinTree_Noode{
    T data;
    BinTree_Noode<T>* left_child, *right_child;
    BinTree_Noode(){
        left_child = nullptr;
        right_child = nullptr;
    }
    BinTree_Noode(T x, BinTree_Noode<T>*_left_child = nullptr, BinTree_Noode<T>*_right_child = nullptr)
        :data(x), left_child(_left_child), right_child(_right_child){}
};
template<typename T>
class Binary_Tree{
protected:
    BinTree_Noode<T>* root;
    T ref_value;    // 数据输入停止标志
    void createbintree(std::istream& in, BinTree_Noode<T>* &subtree);
    bool insert(BinTree_Noode<T>* &)

public:
    Binary_Tree():root(nullptr){}
    Binary_Tree(T value):ref_value(value), root(nullptr){}
    Binary_Tree(Binary_Tree<T>&  other);
    ~Binary_Tree(){
        destroy(root);
    }
    bool isEmpty() const{
        return root == nullptr;
    }
    int height() const{
        return height(root);
    }
    int size() const{
        return size(root);
    }
    Binary_Tree<T>* parent(BinTree_Noode<T>* t) const{
        return (root==nullptr || root == t) ? nullptr : parent(root, t);
    }
    Binary_Tree<T>* left_child(BinTree_Noode<T>* t) const{
        return (t != nullptr) ? t->left_child : nullptr;
    }
    Binary_Tree<T>* right_child(BinTree_Noode<T>* t) const{
        return (t != nullptr) ? t->right_child : nullptr;
    }
    BinTree_Noode<T>* get_root() const{
        return root;
    }
    void pre_order(void (*visit)(BinTree_Noode<T>* t)){
        pre_order(root, visit);
    }
    void in_order(void (*visit)(BinTree_Noode<T>* t)){
        in_order(root, visit);
    }
    void post_order(void (*visit)(BinTree_Noode<T>* t)){
        post_order(root, visit);
    }
    void level_order(void *(visit)(BinTree_Noode<T>* t));
    int insert(const T item);
    BinTree_Noode<T>* find(T item) const;
};