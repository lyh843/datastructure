#include "heap.hpp"


template <class T, class E>
struct HuffmanNode{
    E data;
    HuffmanNode<T, E> *parent;
    HuffmanNode<T, E> *leftChild, *rightChild;
    HuffmanNode(): parent(nullptr), leftChild(nullptr), rightChild(nullptr){}   // 构造函数
    HuffmanNode(E elem, HuffmanNode<T, E> *pr = nullptr, HuffmanNode<T, E> *left = nullptr, HuffmanNode<T, E> *right = nullptr):
        data(elem), parent(pr), leftChild(left), rightChild(right){}
};

template <class T, class E>
class HuffmanTree{
protected:
    HuffmanNode<T, E> *root;    // 树的根
    void deleteTree(HuffmanNode<T, E> *t);  // 删除以 t 为根的子树
    void mergeTree(HuffmanNode<T, E>& ht1, HuffmanNode<T, E>& ht2, HuffmanNode<T, E> *&parent){

    }
public:
    HuffmanTree(E w[], int n){
        MinHeap<T, E> hp;
        HuffmanNode<T, E> *parent, *first, *second;
        HuffmanNode<T, E> *NodeList = new HuffmanNode<T, E>[n];
        for(int i = 0; i < n; i++){
            NodeList[i].data = w[i + 1];
            NodeList[i].leftChild = nullptr;
            NodeList[i].rightChild = nullptr;
            NodeList[i].parent = nullptr;
            hp.insert(NodeList[i]);     // 插入最小堆中
        }
        for(int i = 0; i < n - 1; i++){
            hp.remove(first);
            hp.remove(second);
            mergeTree(first, second, parent);
            hp.insert(*parent);
            root = parent;
        }
    }
    ~HuffmanTree(){
        delete Tree(root);
    }
};