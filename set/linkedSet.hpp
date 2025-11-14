#include "set.hpp"
template <class T>
struct LinkedSetNode {
    T data;
    LinkedSetNode<T> *link;
    // 构造函数
    LinkedSetNode() : link(nullptr){};
    // 构造函数
    LinkedSetNode(const T &x, LinkedSetNode<T> *next = nullptr) : data(x), link(next){};
};

template <class T>
class LinkedSet : public Set<T> {
   private:
    LinkedSetNode<T> *first, *last;

   public:
    LinkedSet() { first = last = new LinkedSetNode<T>; }
    // 复制构造函数
    LinkedSet(LinkedSetNode<T> &R) {}
    ~LinkedSet() {
        makeEmpty();
        delete first;
    }
    void makeEmpty() override;
    bool addMember(const T &x) override;
    // 删除成员
    bool delMember(const T x) override;
    LinkedSet<T>& operator=(const LinkedSet<T> &R) override;  
    LinkedSet<T> operator+(const LinkedSet<T> &R) const;
    LinkedSet<T> operator*(const LinkedSet<T> &R) const;
    LinkedSet<T> operator-(const LinkedSet<T> &R) const;                 
    // 集合的交运算
    LinkedSet<T> intersectWith(const LinkedSet<T> &R) const override;   
    // 集合的并运算
    LinkedSet<T> unionWith(const LinkedSet<T> &R) const override;       
    // 集合的差运算
    LinkedSet<T> differenceFrom(const LinkedSet<T> &R) const override;  
    bool Contains(T x) const override;
    bool subSet(const Set<T> &R) const override;
    // 判断集合是否相等
    bool operator==(const Set<T> &R) const override;
    bool Min (T &x) const;
    bool Max (T &x) const;
};