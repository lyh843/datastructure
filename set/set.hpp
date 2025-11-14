template <class T>
class Set {
   public:
    // 构造函数
    Set();
    // 析构函数
    virtual ~Set();
    // 置空函数
    virtual void makeEmpty() = 0;
    // 添加成员
    virtual bool addMember(const T x) = 0;
    // 删除成员
    virtual bool delMember(const T x) = 0;
    // 集合的交运算
    virtual Set<T> intersectWith(const Set<T> &R) const = 0;
    // 集合的并运算
    virtual Set<T> unionWith(const Set<T> &R) const = 0;
    // 集合的差运算
    virtual Set<T> differenceFrom(const Set<T> &R) const = 0;
    // 判断集合是否包含元素 x
    virtual bool Contains(T x) const = 0;
    // 判断 this 是否为 R 的子集
    virtual bool subSet(const Set<T> &R) const = 0;
    // 判断集合是否相等
    virtual bool operator==(const Set<T> &R) const = 0;
   private:
};
