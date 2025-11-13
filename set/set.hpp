template<class T>
class Set{
public:
    Set();
    virtual void makeEmpty() = 0;
    virtual bool addMember(const T x) = 0;
    virtual bool delMenber(const T x) = 0;
    virtual Set<T> intersectWith(Set<T>& R) = 0;
    virtual Set<T> unionWith(Set<T>& R) = 0;
    virtual Set<T> differenceFrom(Set<T>& R) = 0;
    virtual bool contains(T x) = 0;
    virtual bool subSet(Set<T>& R) = 0;
    virtual bool operator == (Set<T>& R) = 0;
};